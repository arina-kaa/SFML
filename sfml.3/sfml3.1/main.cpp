#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x),
                     float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
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

bool isMore180(float angle)
{
    return ((angle < -180) || (angle > 180));
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

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, sf::Clock &clock)
{
    const float maxSpeed = 15.0;
    const float time = clock.restart().asSeconds();
    const float maxAngle = maxSpeed * time;
    const float startRotation = pointer.getRotation();
    const sf::Vector2f pointerDiff = mousePosition - pointer.getPosition();

    float newAngle = toDegrees(atan2(pointerDiff.y, pointerDiff.x));
    increaseLessZeroAngle(newAngle);

    const float angleDiff = getLess180Angle(startRotation, newAngle);
    const float deltaAngle = (angleDiff > 0) ? std::min(angleDiff, maxAngle) : std::max(angleDiff, 0 - maxAngle);
    float newRotation = pointer.getRotation() + deltaAngle;
    increaseLessZeroAngle(newRotation);

    pointer.setRotation(newRotation);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
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

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    sf::Clock clock;

    init(pointer);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock);
        redrawFrame(window, pointer);
    }
}