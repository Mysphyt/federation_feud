#include <string>
#include <sstream>
#include <iostream>

enum LogLevel {
    SILENT,
    DEBUG 
};

const LogLevel LOG_LEVEL = DEBUG;

void Debug(std::string message); 