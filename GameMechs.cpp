#include "GameMechs.h"
#include "MacUILib.h"

//think about where to seed the RING


GameMechs::GameMechs()
{
    srand(time(NULL)); // seed the random integer generator 
    input = 0;
    exitFlag = false;
    boardSizeX = 20; // default size
    boardSizeY = 10;
    loseFlag = false;
    score = 0;
    foodPos.setObjPos(-1, -1, 'o');
    
     // hold the most recently generated food position

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    
    foodPos.setObjPos(-1, -1, 'o');
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


void GameMechs:: generateFood (objPosArrayList* blockoff){
    //objPosArrayList* ArrList
// heap player class
    int conflict = 1;
    while (conflict == 1){
        //generate random x and y coordinate
        // check x and y against 0 and boardSize / Y.
        int randX = (rand() % (boardSizeX-2)) + 1; // can go from 1 to max -2
        int randY = (rand() % (boardSizeY-2)) + 1; // can go from 1 to max - 2

        //Check if it equals blackOff
        objPos tempPos(randX, randY, 'o'); // objPos is type like int for class objPos
        // puts pair
        // define a new objPos which is used for getElemnt output value
        
       objPos tempArr;

        //int check = blockoff->isPosEqual(&tempPos); // refPos == &tempPos
        // if both equal it will return true therefore 1

        int size = blockoff->getSize();
        int check = 0;
        int k = 0;

        for (k = 0; k < size; k++){
            blockoff->getElement(tempArr, k);
            //check = tempPos.isPosEqual(tempArr);

            if(tempPos.isPosEqual(&tempArr)){ // only if there is no conlifct will it assign the value to thr random position
            conflict = 0; // genertated in player position
            foodPos.x = randX;
            foodPos.y = randY;
            foodPos.symbol = 'o';
            break; // do I need this?
            }
        }


/*
        for (int i = 0; i < size; i++){
            int check = blockoff[i]->getElement(tempPos, i);
            // tempPos.isPosEqual(blockoff[i])
            
            //int check = blockoff[i].isPosEqual(&tempPos);
            
            if(check != 1){ // only if there is no conlifct will it assign the value to thr random position
            conflict = 0; // genertated in player position
            foodPos.x = randX;
            foodPos.y = randY;
            foodPos.symbol = 'o';
            break; // do I need this?
            }
        }
        */


        if (conflict == 0){
            break; // leave while loop if no conflict
        }

/*
        if(check != 1){ // only if there is no conlifct will it assign the value to thr random position
            conflict = 0; // genertated in player position
            foodPos.x = randX;
            foodPos.y = randY;
            foodPos.symbol = 'o';
            break; 
            }
            */
      

    }
     
    
}

void GameMechs:: getFoodPos( objPos &returnPos){
    // return pos is an instance of objPos
    // want to copy the food position and set it to the return pos
    
    //returnPos.x = foodPos.x;
    //returnPos.y = foodPos.y
    //returnPos.symbol = foodPos.symbol;
    returnPos.setObjPos(foodPos);

    
}
