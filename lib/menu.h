#include <iostream>
#include <string>
#include <Windows.h>
#include <SFML/Graphics.hpp>

struct Button {
    std::string buttonText;
    sf::RectangleShape background;
};

struct Menu {
    const UINT buttonListSize;
    const Button *buttons;

    sf::RectangleShape background;
};

VOID RenderMenu(sf::RenderWindow&, Menu);