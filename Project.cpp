#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000


GameMechs* myGM;// pointer to gameMechs, access anything gameMechs through here
Player* myPlayer;//pointer to Player, access anything Player through here


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    
    Initialize();
    

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13); //initializes board size
    myPlayer = new Player(myGM);
}



void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); //Updates player direction according to input
    myPlayer->movePlayer(); //Moves player according to input
    myGM ->clearInput(); //Clears input to not repeatedly process input
}

void DrawScreen(void)
{
   MacUILib_clearScreen(); 

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;
    
    objPos tempFoodPos;
    myGM->getFoodPos(tempFoodPos);

    int row, col, k;     
    bool drawn;

    for (row = 0; row < myGM->getBoardSizeY(); row ++) //cycle through rows
    {
        if (row == 0 || row == myGM->getBoardSizeY() - 1) // first or last row print
        {
            for(int i = 0; i < myGM->getBoardSizeX(); i++) 
            {
                MacUILib_printf("%c", '#');
            }
        }

        else
        {
            for (col = 0; col < myGM->getBoardSizeX(); col++) // cycle through columns
            {
                drawn = false;
                for(int i = 0; i < playerBody->getSize(); i++)
                {
                    playerBody->getElement(tempBody, i); // iterate through every position in the grid and if that matches a part of the body (string) draw it
                    if(tempBody.x == col && tempBody.y == row)
                    {
                        MacUILib_printf("%c", tempBody.symbol);
                        drawn = true;
                        break;
                    }
                }

                //if player body was drawn, don't draw anything below
                if(drawn) continue;

                if (col == 0 || col == myGM->getBoardSizeX() - 1) // first or last column
                {
                    MacUILib_printf("%c", '#');
                }
                //Prints food
                else if (row == tempFoodPos.y && col == tempFoodPos.x)
                {
                    MacUILib_printf("%c",tempFoodPos.symbol);                    
                }
                //Fills unaccounted for space
                else
                {
                        MacUILib_printf("%c", ' ');
                }
            }
        }   
        MacUILib_printf("\n");

    }
    MacUILib_printf("Score: %d\n", myGM->getScore());    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    if(myGM->getLoseFlagStatus())
    {
        //Game lost message
        MacUILib_printf("You lost. Final score was %d\n", myGM->getScore());
    }
    else
    {
        //Game exited message
        MacUILib_printf("Final score was %d\n", myGM->getScore());
    }
  
    MacUILib_uninit();

    delete myGM;
    delete myPlayer;
}
