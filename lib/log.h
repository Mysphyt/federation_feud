#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>

enum LogLevel {
    SILENT,
    DEBUG 
};

const sf::Font DEFAULT_FONT("myfont.ttf");

const LogLevel LOG_LEVEL = DEBUG;

void Debug(std::string message); 