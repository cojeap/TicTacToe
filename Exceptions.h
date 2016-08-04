//
// Created by petru on 7/26/16.
//

#ifndef TICTACTOE_EXCEPTIONS_H
#define TICTACTOE_EXCEPTIONS_H

#include <string>
#include <iostream>


class Exceptions {
public:
    Exceptions() : msg{"Some error occured!"},line{0} {};
    Exceptions(std::string str) : msg{str},line{0} {};
    Exceptions(std::string str,int num) : msg{str},line{num} {};
    ~Exceptions()=default;
    void ShowExcept(){std::cerr<<msg<<"\t"<<line<<std::endl;};
private:
    std::string msg;
    int line;
};


#endif //TICTACTOE_EXCEPTIONS_H
