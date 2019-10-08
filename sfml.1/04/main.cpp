#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "KAA");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({120, 15});
    shape1.setRotation(90);
    shape1.setPosition({200, 120});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({80, 15});
    shape2.setRotation(-50);
    shape2.setPosition({190, 180});
    shape2.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({80, 15});
    shape3.setRotation(50);
    shape3.setPosition({200, 170});
    shape3.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({120, 15});
    shape4.setRotation(-70);
    shape4.setPosition({270, 235});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({120, 15});
    shape5.setRotation(70);
    shape5.setPosition({330, 125});
    shape5.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({60, 15});
    shape6.setPosition({290, 180});
    shape6.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({120, 15});
    shape7.setRotation(-70);
    shape7.setPosition({390, 235});
    shape7.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({120, 15});
    shape8.setRotation(70);
    shape8.setPosition({450, 125});
    shape8.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({60, 15});
    shape9.setPosition({410, 180});
    shape9.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape9);

    window.display();

    sf::sleep(sf::seconds(5));
}