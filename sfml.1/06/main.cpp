#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RectangleShape background;
    background.setSize({625, 545});
    background.setPosition({0, 0});
    background.setFillColor(sf::Color(255, 255, 255));

    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(90, 29, 21));
    roof.setPosition(310, 175);
    roof.setPointCount(4);
    roof.setPoint(0, {-115, 0});
    roof.setPoint(1, {+115, 0});
    roof.setPoint(2, {+280, 120});
    roof.setPoint(3, {-280, 120});

    sf::RectangleShape wall;
    wall.setSize({455, 235});
    wall.setPosition({85, 295});
    wall.setFillColor(sf::Color(75, 46, 11));

    sf::RectangleShape door;
    door.setSize({70, 160});
    door.setPosition({130, 370});
    door.setFillColor(sf::Color(24, 23, 23));

    sf::CircleShape circle1(15);
    circle1.setPosition({395, 105});
    circle1.setFillColor(sf::Color(191, 191, 191));

    sf::CircleShape circle2(18);
    circle2.setPosition({405, 80});
    circle2.setFillColor(sf::Color(191, 191, 191));

    sf::CircleShape circle3(23);
    circle3.setPosition({420, 50});
    circle3.setFillColor(sf::Color(191, 191, 191));

    sf::CircleShape circle4(25);
    circle4.setPosition({430, 20});
    circle4.setFillColor(sf::Color(191, 191, 191));

    sf::RectangleShape pipeBody;
    pipeBody.setSize({35, 65});
    pipeBody.setPosition({385, 170});
    pipeBody.setFillColor(sf::Color(59, 56, 56));

    sf::RectangleShape pipeHead;
    pipeHead.setSize({55, 40});
    pipeHead.setPosition({375, 130});
    pipeHead.setFillColor(sf::Color(59, 56, 56));

    sf::RenderWindow window(sf::VideoMode({625, 545}), "House");
    window.clear();
    window.draw(background);
    window.draw(roof);
    window.draw(wall);
    window.draw(door);
    window.draw(circle1);
    window.draw(circle2);
    window.draw(circle3);
    window.draw(circle4);
    window.draw(pipeBody);
    window.draw(pipeHead);
    window.display();

    sf::sleep(sf::seconds(5));
}