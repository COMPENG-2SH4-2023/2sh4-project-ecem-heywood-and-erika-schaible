#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000


GameMechs* myGM;// pointer to game mech ... want to access anything here
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
    
    // objPos playerPos; //new object position created
    // myPlayer->getPlayerPos(playerPos); // getting player position.. saved in myPlayer
    // myGM ->generateFood (playerPos);
    

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

    // debug key call  for food generation for verification
    

    // remeber generateFood() requires player reference. You will need to provide it AFTER Player object is instantiated
    
}



void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    //objPos playerPos; //new object position created ... NAME
    //myPlayer->getPlayerPos(playerPos); // getting player position.. saved in myPlayer
    // setting data of obj you set data to playerPos using the getter function

    myPlayer->updatePlayerDir(); // update input 
    myPlayer->movePlayer(); // make a move
    myGM ->clearInput(); // so to not repeatedly process the input
    
    

    //myPlayer->getPlayerPos(playerPos);
}

void DrawScreen(void)
{
   
    objPos playerPos; //new object position created
    myPlayer->getPlayerPos(playerPos); // getting player position.. saved in myPlayer
    

    MacUILib_clearScreen(); 
    int row, col, k;
    objPos foodtemp;
    myGM -> getFoodPos(foodtemp);
     

    for (row = 0; row < myGM->getBoardSizeY(); row ++)
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
                if (col == 0 || col == myGM->getBoardSizeX() - 1) // first or last column
                {
                    MacUILib_printf("%c", '#');
                }
                else if (row == playerPos.y && col == playerPos.x)
                {
                    MacUILib_printf("%c", playerPos.symbol);
                } 
                else if (row == foodtemp.y && col == foodtemp.x)
                {
                    MacUILib_printf("%c",foodtemp.symbol);                    
                }
                else
                {
                        MacUILib_printf("%c", ' ');
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

    
    delete myGM;
    delete myPlayer;
    // obj created on stack and allocated in heap don't need to call in main.... if defined in the player.and in the h faile the c++ program will find it an call it and clean up itself
    // if obj on stack is declared to have space on heap the c++ will clean up by itself 
}
