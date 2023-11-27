#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
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
    
    //this is a makeshift setup so we don't have to touch generate item yet
    //we need to do it though
    objPos tempPos(-1, -1, 'o');
    myGM->generateFood(tempPos);//needs to be turned into arraylist operation
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
   MacUILib_clearScreen(); 

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;
    
    objPos tempFoodPos;
    myGM->getFoodPos(tempFoodPos);

    // this is a makeshift set up so I don't hace to touch generateItemyet
    // you need to do this yourself
    //objPos tempFoodPos (1, 1, o); // turn into array list set up
    //myGM->getFoodPos(tempFoodPos);


    int row, col, k;     
    bool drawn;

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

                if(drawn) continue;
                //if player body was drawn, don't draw anything below

                if (col == 0 || col == myGM->getBoardSizeX() - 1) // first or last column
                {
                    MacUILib_printf("%c", '#');
                }
                else if (row == tempFoodPos.y && col == tempFoodPos.x)
                {
                    MacUILib_printf("%c",tempFoodPos.symbol);                    
                }
                else
                {
                        MacUILib_printf("%c", ' ');
                }
            }
        }   
        MacUILib_printf("\n");

    }
    MacUILib_printf("Score: %d\n", myGM->getScore());
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
