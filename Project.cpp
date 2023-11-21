#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

objPos myPos;

GameMechs* myGM;
Player* myPlayer;

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
    myPlayer->updatePlayerDir();
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    int row, col, k;
    //error with the mainGameMechsRef->, doesn't work....

    // for (row = 0; row < mainGameMechsRef->getBoardSizeY(); row ++)
    // {
    //     if (row == 0 || row == 9)
    //     {
    //         MacUILib_printf("####################");
    //     }

    //     else
    //     {
    //         for (col = 0; col < mainGameMechsRef->getBoardSizeX(); col++)
    //         {
    //             if (col == 0 || col == 19)
    //             {
    //                 MacUILib_printf("#");
    //             }
    //             // else if (row == playerPos.y && col == playerPos.x)//do a get object pos here
    //             // {
    //             //     MacUILib_printf("%c", playerPos.symbol);
    //             // }
    //             else
    //             {
    //                 //int isOccupied = 0;
    //                 // for(k = 0; k < 5; k++)
    //                 // {
    //                 //     if (row == itemBin[k].y && col == itemBin[k].x)
    //                 //     {
    //                 //         MacUILib_printf("%c", itemBin[k].symbol);
    //                 //         isOccupied = 1;
    //                 //         break;
    //                 //     }
    //                 // }
    //                 //if(isOccupied == 0)
    //                 //{
    //                     MacUILib_printf(" ");
    //                 //}
    //             }
    //         }
    //     }   
    //     MacUILib_printf("\n");

    //}
    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);
    MacUILib_printf("Board Size: %d x %d, Player Pos: <%d, %d> + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
