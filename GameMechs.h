#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        
        int boardSizeX;
        int boardSizeY;

        //objPos foodPos;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        //~GameMechs();
        
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        char getInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore(); 


        void setExitTrue();
        void setLoseFlag();
        void setInput(char this_input);
        void clearInput();
        void incrementScore();

       
        //Food();
        //~Food();
       // void generateFood(blockOff objPos);
       // void getFoodPos(returnPos &objPos);

};

#endif

/*
class food
{
    private:
    objPos foodPos;

    public:
    Food();
    //~Food();
    void generateFood(blockOff objPos);
    void getFoodPos(returnPos &objPos);
}
*/