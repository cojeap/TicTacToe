//
// Created by petru on 8/9/16.
//

#ifndef TICTACTOE_LOGGER_H
#define TICTACTOE_LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    Logger(const char * str);
    ~Logger()= default;
    void w(const std::string& someStr);
private:
    std::ofstream logFile;
    std::string logFileName;
};


#endif //TICTACTOE_LOGGER_H
