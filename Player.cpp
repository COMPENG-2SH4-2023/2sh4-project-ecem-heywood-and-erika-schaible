#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPos tempPos;

    //sets player location and symbol
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
    //creates space on the heap
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    //for debugging purpose - insert another four segments
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
}


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
    char input = mainGameMechsRef->getInput();
    switch(input)
    {
        case ' ':
            mainGameMechsRef->setExitTrue();
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
    //holding the position information of the current head
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);
    
    //Player movement and wraparound logic
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
            if (currentHead.y >= mainGameMechsRef->getBoardSizeY() - 1)
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
            if (currentHead.x >= mainGameMechsRef->getBoardSizeX() - 1)
            {
                currentHead.x = 1;
            }
            break;

        case STOP:
        default:
            break;
    }

    //New head inserted to the head of the list
    playerPosList->insertHead(currentHead);

    //check for self collision, if self collision ends game
    if(myDir != STOP)
    {
        if(checkSelfCollision())
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

    objPos foodPos;
    //Checks if new head collides with food, increments snake and generates new food if true
    if (currentHead.x == foodPos.x && currentHead.y == foodPos.y){
        mainGameMechsRef-> generateFood (playerPosList);
        mainGameMechsRef->incrementScore();
    }
    else
    {
        playerPosList->removeTail();
    }
}

bool Player::checkSelfCollision()
{
    //Checks for self collision
    bool collision = false;
    objPos currentHead;
    objPos tempPos;
    playerPosList->getHeadElement(currentHead);

    //Compares current head to all other elements of the arraylist
    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(tempPos, i);
        if(tempPos.isPosEqual(&currentHead))
        {
            collision = true;
            break;
        }
    }
    return collision;
}









