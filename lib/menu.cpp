#include "menu.h"

VOID RenderButton(sf::RenderWindow& window, Button button)
{
    window.draw(button.background); 
};

VOID RenderMenu(sf::RenderWindow& window, Menu menu) 
{
    // Draw the menu background
    window.draw(menu.background);

    // Render each button
    for (Button menuButton : menu.buttons)
    {
        RenderButton(window, menuButton); 
    }
};

Menu GenerateTestMenu(float width, float height)
{
    Debug("Generating Test Menu...");

    sf::RectangleShape menuBackground({0,0});
    menuBackground.setSize({width, height});
    menuBackground.setFillColor(sf::Color({50,50,50}));

    // Button1
    sf::RectangleShape btn1Rect = sf::RectangleShape({100,100});
    btn1Rect.setPosition({100.f,100.f});
    btn1Rect.setFillColor(sf::Color(0,0,250));
    Button btn1 = {
        "Button 1", 
        btn1Rect
    };
    // Button2
    sf::RectangleShape btn2Rect = sf::RectangleShape({100,100});
    btn2Rect.setPosition({100.f,200.f});
    btn2Rect.setFillColor(sf::Color(0,250,0));
    Button btn2 = {
        "Button 2", 
        btn2Rect
    };
    // Button3
    sf::RectangleShape btn3Rect = sf::RectangleShape({100,100});
    btn1Rect.setPosition({100.f,300.f});
    btn2Rect.setFillColor(sf::Color(250,0,0));
    Button btn3 = {
        "Button 3", 
        btn3Rect
    };

    Debug("Menu");
    std::list<Button> menuBtns{btn1, btn2, btn3};

    Menu menu = {menuBackground,menuBtns};
    
    Debug("Return");
    return menu;
};