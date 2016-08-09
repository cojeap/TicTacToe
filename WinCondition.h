//
// Created by petru on 8/4/16.
//

#ifndef TICTACTOE_WINCONDITION_H
#define TICTACTOE_WINCONDITION_H

#include "Exceptions.h"

enum class WinType{
    winPlayerRed=1,winPlayerBlue,tie,playing
};

struct WinCondition{
    WinCondition() : condition{false},winTypeText{WinType::playing} {};
    WinCondition(WinType type){
        if(type==WinType::winPlayerBlue)
            condition= true;
        else if (type==WinType::winPlayerRed)
            condition=true;
        else if(type==WinType::tie)
            condition= true;
        else if(type==WinType::playing)
            condition=false;
        else throw Exceptions("Win type is not valid! (WinCondition.h)",25);
    };
    bool condition;
    WinType winTypeText;

};


#endif //TICTACTOE_WINCONDITION_H
