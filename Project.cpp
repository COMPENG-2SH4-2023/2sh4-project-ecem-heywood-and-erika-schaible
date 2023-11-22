#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000


GameMechs* myGM;
Player* myPlayer;
//objPos playerPos;

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

    myGM = new GameMechs(26, 13); //makes board size 26 x 13
    myPlayer = new Player(myGM);

}



void GetInput(void)
{
   
}

void RunLogic(void)
{
    //objPos playerPos; //new object position created ... NAME
    //myPlayer->getPlayerPos(playerPos); // getting player position.. saved in myPlayer
    // setting data of obj you set data to playerPos using the getter function

    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    //myPlayer->getPlayerPos(playerPos);
}

void DrawScreen(void)
{
   
    objPos playerPos; //new object position created
    myPlayer->getPlayerPos(playerPos); // getting player position.. saved in myPlayer

    MacUILib_clearScreen(); 
    int row, col, k;

    for (row = 0; row < myGM->getBoardSizeY(); row ++)
    {
        if (row == 0 || row == myGM->getBoardSizeY() - 1)
        {
            for(int i = 0; i < myGM->getBoardSizeX(); i++)
            {
                MacUILib_printf("#");
            }
        }

        else
        {
            for (col = 0; col < myGM->getBoardSizeX(); col++)
            {
                if (col == 0 || col == myGM->getBoardSizeX() - 1)
                {
                    MacUILib_printf("#");
                }
                else if (row == playerPos.y && col == playerPos.x)
                {
                    MacUILib_printf("%c", playerPos.symbol);
                }
                else
                {
                        MacUILib_printf(" ");
                }
            }
        }   
        MacUILib_printf("\n");

    }
    MacUILib_printf("Board Size: %d x %d, Player Pos: <%d, %d> + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), playerPos.x, playerPos.y, playerPos.symbol);
    MacUILib_printf("This is the score %d\n", myGM->getScore());
    MacUILib_printf("This is the lose screen %d\n", myGM->getLoseFlagStatus());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();
  
    MacUILib_uninit();

    delete myPlayer;
    delete myGM;
}
