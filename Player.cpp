#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    //for debugging purpose - insert another four segments
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
}


// iterations 3 you will need deconstructor 

Player::~Player()
{
    //delete heap members
    delete playerPosList;
}


objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
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
        case ' ':
            mainGameMechsRef->setExitTrue();
            break;
        
        // case 'f':
        //     mainGameMechsRef->generateFood(tempPos);
        //     break;
        
        case 'l':
            mainGameMechsRef->setLoseFlag();
            break;

        case 'i':
            mainGameMechsRef->incrementScore();
            break;

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
    objPos currentHead; //holding the pos information of the current head
    playerPosList->getHeadElement(currentHead);
    
    switch(myDir)
    {
        case UP:
            currentHead.y--;
            if (currentHead.y <= 0)
            {
                currentHead.y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;

        case DOWN:
            currentHead.y++;
            if (currentHead.y >= mainGameMechsRef->getBoardSizeY())
            {
                currentHead.y = 1;
            }
            break;

        case LEFT:
            currentHead.x--;
            if (currentHead.x <= 0)
            {
                currentHead.x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;

        case RIGHT:
            currentHead.x++;
            if (currentHead.x >= mainGameMechsRef->getBoardSizeX())
            {
                currentHead.x = 1;
            }
            break;

        case STOP:
        default:
            break;
    }

    //new current head should be inserted to the head of the list
    playerPosList->insertHead(currentHead);

    //check if new head pos collides with food
    //if yes, increment the score in GM and generate new food, don't remove tail
    //otherwise, remove tail

    if (currentHead.x == foodPos.x && currentHead.y == foodPos.y){
        generateFood (objPos *objPosArrayList)
        mainGameMechsRef->incrementScore();//could we do this instead of setting score to array length??
        
    }
    else
    {
        playerPosList->removeTail();
    }
    
    
    //then remove tail
    //playerPosList->removeTail();

    //int end = getTailElement(playerPosList) // how to know the final position of the snake?
    // generateFood (insertTail(playerPosList) ); // block of the position of the list of the snake?

}

bool Player::checkSelfCollision()
{
    objPosArrayList* headElement = playerPosList->getHeadElement();
    for(int i = 1; i < playerPosList.getSize(); i++)
    {

    }
}

