#include <ctime>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <thread>
#include "./ConsoleEvent.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    // Event callbacks
    // ===============
    const auto onClose = [&window](const sf::Event::Closed&)
    {
        window.close();
    };

    const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
    {
        if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
        {
            // Debug
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
    // ===============

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
         
        // == [bgn] Game Loop ==
        window.handleEvents(onClose, onKeyPressed, onKeyReleased);

        // Check for keyboard input
        // if(_kbhit()) {
        //    CheckEmitConsoleEvent();
        // }

        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            /*
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
            */
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        
        // end the current frame
        window.display();
        // == [end] Game Loop ==

        // Target frame time calculation
        delta_time = current_time - clock() / (double) CLOCKS_PER_SEC;

        // Use sleep_until to reach target frame time (does nothing if frame time is already reached)
        target_frame_time += time_between_frames;     // calculate target point in time
        std::this_thread::sleep_until(target_frame_time);  // sleep until that time point
    }
}
