#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 

    //Where does the input come from? How to check for input?
    //Hint not MacUILib get char
    //There will be a method in gamemechanism class that gets input and stores most recent
    //Just need to figure out how to get to it
    //How? It lies within the Gamemechs* inside your private member
    char input = mainGameMechsRef->getInput();
    switch(input)
    {
        case 'w':
                if (myDir != DOWN && myDir != UP)
                {
                    myDir = UP;
                }
                break;

            case 'a':
                if (myDir != RIGHT && myDir != LEFT)
                {
                    myDir = LEFT;
                }
                break;
                

            case 's':
                if (myDir != UP && myDir != DOWN)
                {
                    myDir = DOWN;
                }
                break;
                
            case 'd':
                if (myDir != RIGHT && myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;

            default:
                break;
    }       
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    //Work in progress
    //pretty sure the logic for how to move the player needs to be updated
    
    //playerPos.getObjPos(); //does this work?
    switch(myDir)
    {
        case UP:
            //playerPos.setObjPos() something like this...maybe sorta
            playerPos.y = playerPos.y - 1;
            if (playerPos.y == 0)
            {
                //playerPos.y = mainGameMechsRef->getBoardSizeY() - 2; //error here
            }
            break;

        case DOWN:
            playerPos.y++;
            if (playerPos.y == 9)//playerPos.y == mainGameMechsRef->getBoardSizeY() - 1) //same error here
            {
                playerPos.y = 1;
            }
            break;

        case LEFT:
            playerPos.x--;
            if (playerPos.x == 0)
            {
                //playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;

        case RIGHT:
            playerPos.x++;
            if (playerPos.x == 9)//playerPos.x == mainGameMechsRef->getBoardSizeY() - 1)
            {
                playerPos.x = 1;
            }
            break;

        default:
            break;
    }

}

