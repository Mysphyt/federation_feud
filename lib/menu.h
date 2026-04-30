#include <iostream>
#include <string>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <list>

#include "event.h"

struct Button {
    std::string buttonText;
    sf::RectangleShape background;
};

struct Menu {
    sf::RectangleShape background;
    std::list<Button> buttons;
};

VOID RenderMenu(sf::RenderWindow&, Menu);

VOID RenderButton(sf::RenderWindow&, Button);

Menu GenerateTestMenu(float width, float height);