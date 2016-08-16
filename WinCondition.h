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
    WinCondition() : gameEnded{false},winTypeText{WinType::playing} {};

    WinCondition(WinType type){
        if(type==WinType::winPlayerBlue)
            gameEnded= true;
        else if (type==WinType::winPlayerRed)
            gameEnded=true;
        else if(type==WinType::tie)
            gameEnded= true;
        else if(type==WinType::playing)
            gameEnded=false;
        else throw Exceptions("Win type is not valid! (WinCondition.h)",26);
    };

    void SetWinType(WinType type){
        if(type==WinType::winPlayerBlue)
            gameEnded= true;
        else if (type==WinType::winPlayerRed)
            gameEnded=true;
        else if(type==WinType::tie)
            gameEnded= true;
        else if(type==WinType::playing)
            gameEnded=false;
        else throw Exceptions("Win type is not valid! (WinCondition.h)",37);
    };
    bool gameEnded;
    WinType winTypeText;
};


#endif //TICTACTOE_WINCONDITION_H
