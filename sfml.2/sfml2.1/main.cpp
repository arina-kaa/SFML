#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Moving Ball");
    sf::Clock clockX;
    sf::Clock clockY;

    float x = 10;
    float y = 260;
    float speedX = 100.f;
    sf::Vector2f position = {x, y};

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

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

        constexpr float amplitudeY = 80.f;
        constexpr float periodY = 2;

        const float timeX = clockX.restart().asSeconds();
        const float timeY = clockY.getElapsedTime().asSeconds();

        const float wavePhase = timeY * float(2 * M_PI);
        x += speedX * timeX;
        y = amplitudeY * std::sin(wavePhase / periodY);
        sf::Vector2f offset = {x, y};

        sf::Vector2f currentPosition = ball.getPosition();
        
        if ((currentPosition.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speedX > 0))
        {
            speedX = -speedX;
        }
        if ((currentPosition.x < 0) && (speedX < 0))
        {
            speedX = -speedX;
        }

        ball.setPosition(position + offset);

        window.clear();
        window.draw(ball);
        window.display();
    }
}