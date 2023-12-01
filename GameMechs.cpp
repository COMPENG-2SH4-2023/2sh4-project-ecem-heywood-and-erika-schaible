#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    srand(time(NULL)); // seed the random integer generator 
    input = 0;
    exitFlag = false;
    boardSizeX = 20; // default size
    boardSizeY = 10;
    loseFlag = false;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;

}

bool GameMechs:: getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    //Recieves input from the user
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


int GameMechs:: getScore(){
    return score;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}


void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}


void GameMechs::incrementScore(){
    score += 1; // score incremented by one once the food is collected
}


void GameMechs:: generateFood (objPosArrayList* blockoff)
{
    srand(time(NULL));
    int conflict = 1;
    //Continues regenerating random coordinates for the food until there is no conflict with the food position and snake
    while (conflict == 1)
    {
        conflict = 0;
        //Generate random values for the x and y coordinates of the food
        int randX = (rand() % (boardSizeX-2)) + 1;
        int randY = (rand() % (boardSizeY-2)) + 1;

        objPos tempPos;
        tempPos.setObjPos(randX, randY, 'o');
        objPos tempArr;
        int size = blockoff->getSize();
        int check = 0;
        int k = 0;

        //Iterates through the snake size, and compares food position to snake position
        for (k = 0; k < size; k++)
        {
            blockoff->getElement(tempArr, k);
            //If food position and snake position are equal, flag is raised
            if(tempPos.isPosEqual(&tempArr))
            {
                conflict = 1;
                break;
            }
        }
        //If no conflict, sets food position
        if (conflict == 0){
            foodPos.x = randX;
            foodPos.y = randY;
            foodPos.symbol = 'o';
        }
    }
     
    
}

void GameMechs:: getFoodPos( objPos &returnPos){
    //Returns food position
    returnPos.setObjPos(foodPos);
}
