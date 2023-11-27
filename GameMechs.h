#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib> // provides srand() and rand() 
#include <time.h> // can be replaced by <ctime> .. provides time()

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

        objPos foodPos;
        
        int boardSizeX;
        int boardSizeY;

        

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        //~GameMechs();
        
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        char getInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();  // could add const


        void setExitTrue();
        void setLoseFlag();
        void setInput(char this_input);
        void clearInput();
        void incrementScore();

       
        //Food();
        //~Food();
        void generateFood(objPos *objPosArrayList); //need to upgrade this somehow...
        
        // void generateFood(objPos blockOff);
        
        
        //Need to accept the player body array list
        //go through each array list element to make sure they are all
        //blocked off from random food generation (need a list of block offs?)


        void getFoodPos(objPos &returnPos);

};

#endif

