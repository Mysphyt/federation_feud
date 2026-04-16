#include <ctime>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <thread>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "menu.h"

CONST UINT WIN_WIDTH = 800;
CONST UINT WIN_HEIGHT = 600;

enum class GameState {
    Menu
};

/*
int teststuff()
{
    struct TestStruct {
        int somenumber;
        sf::RectangleShape shape;   
    };

    struct ListStruct {
        const TestStruct *structList;
    };
    sf::RectangleShape someShape({100,100});
    sf::RectangleShape someOtherShape({220,220});

    TestStruct testStruct1({1, someShape});
    TestStruct testStruct2({2, someOtherShape});

    TestStruct structList[2] = {testStruct1, testStruct2};

    ListStruct listStruct({structList});

    std::cout << sizeof(TestStruct) << ", " << sizeof(listStruct.structList);
}
*/

int main()
{
    GameState currentGameState = GameState::Menu;

    // create the window
    sf::RenderWindow window(sf::VideoMode({WIN_WIDTH, WIN_HEIGHT}), "My window");

    sf::RectangleShape testMenuBackground({0, 0});
    testMenuBackground.setSize({WIN_WIDTH/2, WIN_HEIGHT/2});

    Menu testMenu = Menu { 0, {}, testMenuBackground };

    // == Event Callbacks ==>

    const auto onClose = [&window](const sf::Event::Closed&)
    {
        window.close();
    };

    const auto onResized = [&window](const sf::Event::Resized& resized)
    {
        std::cout << "new width: " << resized.size.x << std::endl;
        std::cout << "new height: " << resized.size.y << std::endl;

        // update the view to the new size of the window
        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized.size));
        window.setView(sf::View(visibleArea));
    };

    const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
    {
        if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
        {
            /*
            == scancode info debug ==>

            std::cout << "the escape key was pressed" << std::endl;
            std::cout << "scancode: " << static_cast<int>(keyPressed.scancode) << std::endl;
            std::cout << "code: " << static_cast<int>(keyPressed.code) << std::endl;
            std::cout << "control: " << keyPressed.control << std::endl;
            std::cout << "alt: " << keyPressed.alt << std::endl;
            std::cout << "shift: " << keyPressed.shift << std::endl;
            std::cout << "system: " << keyPressed.system << std::endl;
            std::cout << "description: " << sf::Keyboard::getDescription(keyPressed.scancode).toAnsiString() << std::endl;
            std::cout << "localize: " << static_cast<int>(sf::Keyboard::localize(keyPressed.scancode)) << std::endl;
            std::cout << "delocalize: " << static_cast<int>(sf::Keyboard::delocalize(keyPressed.code)) << std::endl;
            
            <== scancode info debug ==
            */

            // Close the window
            window.close();
        }
        else 
        {
            std::cout << "Key Pressed: " << sf::Keyboard::getDescription(keyPressed.scancode).toAnsiString() << std::endl;
        }
    };

    const auto onKeyReleased = [&window](const sf::Event::KeyReleased& keyReleased)
    {
        std::cout << "Key Released: " << sf::Keyboard::getDescription(keyReleased.scancode).toAnsiString() << std::endl;
    };

    const auto onMouseWheelScrolled = [&window](const sf::Event::MouseWheelScrolled& mouseWheelScrolled)
    {
        switch (mouseWheelScrolled.wheel)
        {
            case sf::Mouse::Wheel::Vertical:
                std::cout << "wheel type: vertical" << std::endl;
                break;
            case sf::Mouse::Wheel::Horizontal:
                std::cout << "wheel type: horizontal" << std::endl;
                break;
        }
        std::cout << "wheel movement: " << mouseWheelScrolled.delta << std::endl;
        std::cout << "mouse x: " << mouseWheelScrolled.position.x << std::endl;
        std::cout << "mouse y: " << mouseWheelScrolled.position.y << std::endl;
    };

    const auto onMouseButtonPressed = [&window](const sf::Event::MouseButtonPressed& mouseButtonPressed)
    {
        if (mouseButtonPressed.button == sf::Mouse::Button::Right)
        {
            std::cout << "the right button was pressed" << std::endl;
            std::cout << "mouse x: " << mouseButtonPressed.position.x << std::endl;
            std::cout << "mouse y: " << mouseButtonPressed.position.y << std::endl;
        }
        else if (mouseButtonPressed.button == sf::Mouse::Button::Left)
        {
            std::cout << "the left button was pressed" << std::endl;
            std::cout << "mouse x: " << mouseButtonPressed.position.x << std::endl;
            std::cout << "mouse y: " << mouseButtonPressed.position.y << std::endl;
        }

    };

    const auto onMouseMoved = [&window](const sf::Event::MouseMoved& mouseMoved)
    {
        std::cout << "new mouse x: " << mouseMoved.position.x << std::endl;
        std::cout << "new mouse y: " << mouseMoved.position.y << std::endl;   
    };

    // <== Event Callbacks ==

    // Target frame rate
    int FPS = 60;

    auto time_between_frames = std::chrono::microseconds(std::chrono::seconds(1)) / FPS;
    auto target_frame_time = std::chrono::steady_clock::now();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // 
        DWORD current_time, delta_time;
        current_time = clock();
         
        // == Game Loop ==>

        // Pass event callbacks
        window.handleEvents(
            onClose,
            onKeyPressed,
            onKeyReleased,
            onMouseWheelScrolled,
            onMouseButtonPressed,
            onMouseMoved,
            onResized
        );

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        RenderMenu(window, testMenu);
        
        // end the current frame
        window.display();

        // <== Game Loop ==

        // Target frame time calculation
        delta_time = current_time - clock() / (double) CLOCKS_PER_SEC;

        // Use sleep_until to reach target frame time (does nothing if frame time is already reached)
        target_frame_time += time_between_frames;     // calculate target point in time
        std::this_thread::sleep_until(target_frame_time);  // sleep until that time point
    }
}
