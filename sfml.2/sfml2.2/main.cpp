#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

constexpr unsigned START_POSITION_X = 400;
constexpr unsigned START_POSITION_Y = 300;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Flower",
        sf::Style::Default, settings
    );
    sf::Clock clock;

    sf::ConvexShape ellipse;
    ellipse.setPosition({START_POSITION_X, START_POSITION_Y});
    ellipse.setFillColor(sf::Color(0xFF, 0x09, 0x80));

    constexpr int pointCount = 200;
    ellipse.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float ellipseRadius = 200 * sin(6 * angle);
        sf::Vector2f point = {
            ellipseRadius * std::sin(angle),
            ellipseRadius * std::cos(angle)
        };
        ellipse.setPoint(pointNo, point);
    }

    constexpr float rotationSpeed = 20.f;
    constexpr float positionSpeed = 5.f;
    constexpr float positionRadius = 30.f;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float time = clock.getElapsedTime().asSeconds();
        ellipse.setRotation(rotationSpeed * time);
        ellipse.setPosition({
            START_POSITION_X + 30.f * std::sin(positionSpeed * time),
            START_POSITION_Y + 30.f * std::cos(positionSpeed * time)
        });

        window.clear();
        window.draw(ellipse);
        window.display();
    }
}