//
// Created by petru on 8/9/16.
//

#include "Logger.h"


Logger::Logger(const char * str) : logFileName{str},logFile{str} {
    logFile<<"Logger file opened"<<std::endl<<std::endl;
}

void Logger::w(const std::string& someStr){
    logFile<<someStr<<"\n"<<std::endl;
}