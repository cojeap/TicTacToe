//
// Created by petru on 8/9/16.
//

#include "Logger.h"


Logger::Logger(const char * str) : logFileName{str},logFile{str} {

    if(!logFile){
        std::ofstream createLogFile{logFileName};
        createLogFile<<"Created logger file\n\n"<<std::endl;
        logFile.open(logFileName);
    }
    else {
        logFile<<"Logger file"<<std::endl<<std::endl;
    }
}

void Logger::w(const std::string& someStr){
    logFile<<someStr<<"\n"<<std::endl;
}