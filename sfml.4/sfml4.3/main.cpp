#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>

using namespace std;

struct picture
{
    string path;
    int width;
    int height;
    sf::Vector2f startPosition;
};

void init(sf::Texture &texture, sf::Sprite &cat, picture pictureInfo)
{
    texture.loadFromFile(pictureInfo.path);

    cat.setTexture(texture);
    cat.setTextureRect(sf::IntRect(0, 0, pictureInfo.width, pictureInfo.height));
    cat.setPosition(pictureInfo.startPosition);
}

void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &targetPosition)
{
    targetPosition = {float(event.x),
                      float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &targetPosition)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            onMouseClick(event.mouseButton, targetPosition);
            break;
        default:
            break;
        }
    }
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

float toRadians(float degrees)
{
    return float(double(degrees) * M_PI / 180.0);
}

bool isMore180(float angle)
{
    return ((angle < -180) || (angle > 180));
}

bool isLeftCirclePart(float angle)
{
    return ((angle > 90) && (angle < 270));
}

float getLess180Angle(float startAngle, float endAngle)
{
    float angleDiff = endAngle - startAngle;
    if (isMore180(angleDiff))
    {
        angleDiff = startAngle - endAngle;
    }
    return angleDiff;
}

float increaseLessZeroAngle(float &angle)
{
    if (angle < 0)
    {
        angle += 360;
    }
    return angle;
}

void update(const sf::Vector2f &targetPosition, sf::Sprite &cat, sf::Clock &clock)
{
    const float maxWaySpeed = 20.0;
    const float time = clock.restart().asSeconds();
    const float maxWayDiff = maxWaySpeed * time;
    const sf::Vector2f startPosition = cat.getPosition();
    sf::Vector2f pointerDiff = targetPosition - startPosition;
    sf::Vector2f newPosition = startPosition;

    float newAngle = toDegrees(atan2(pointerDiff.y, pointerDiff.x));
    increaseLessZeroAngle(newAngle);
    if (isLeftCirclePart(newAngle))
        cat.setScale(-1, 1);
    else
        cat.setScale(1, 1);

    if (sqrt((pointerDiff.x * pointerDiff.x) + (pointerDiff.y * pointerDiff.y)) > maxWayDiff)
    {
        pointerDiff.x = maxWayDiff * cos(toRadians(newAngle));
        pointerDiff.y = maxWayDiff * sin(toRadians(newAngle));
    }
    newPosition.x += pointerDiff.x;
    newPosition.y += pointerDiff.y;
    cat.setPosition(newPosition);
}

void redrawFrame(sf::RenderWindow &window, sf::Sprite &cat, sf::Sprite &target)
{
    window.clear(sf::Color(255, 255, 255));
    window.draw(target);
    window.draw(cat);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Pointer follows mouse", sf::Style::Default, settings);

    sf::Clock clock;
    sf::Sprite cat;
    sf::Sprite target;
    sf::Texture textureCat;
    sf::Texture textureTarget;
    sf::Vector2f targetPosition;
    struct picture catPicture = {"cat.png", 38, 35, {400, 300}};
    struct picture targetPicture = {"red_pointer.png", 32, 32, {0, 0}};

    init(textureCat, cat, catPicture);
    init(textureTarget, target, targetPicture);

    while (window.isOpen())
    {
        pollEvents(window, targetPosition);
        target.setPosition(targetPosition);
        update(targetPosition, cat, clock);
        redrawFrame(window, cat, target);
    }
}