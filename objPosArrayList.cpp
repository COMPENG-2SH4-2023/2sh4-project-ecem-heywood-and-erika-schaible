#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; //256 elements on the heap
    sizeList = 0; //no valid element in the list upon startup
    sizeArray = ARRAY_MAX_CAP; //array capacity should be max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    //check if sizeList is equal to sizeArray. If yes, don't insert
    if(sizeList == sizeArray)
    {
        return;
    }

    for(int i = sizeList; i > 0; i--)
    {
        aList[i].setObjPos(aList[i-1]); //shuffles all the elements towards the tail
    }
    //Inserts head element and increases length counter
    aList[0].setObjPos(thisPos);
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList == sizeArray)
    {
        return;
    }
    //Inserts tail element and increases length counter
    aList[sizeList].setObjPos(thisPos);
    sizeList++;
}

void objPosArrayList::removeHead()
{
    for(int i = 0; i < sizeList - 1; i++)
    {
        aList[i].setObjPos(aList[i+1]); //shuffles all the elements towards the head
    }
    sizeList--;
}

void objPosArrayList::removeTail()
{
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]); //head element is element 0
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList - 1]); //tail element is end element
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    //Checks if desired index is valid
    if(sizeList == 0 || index < 0 || index >= sizeList)
    {
        return;
    }
    returnPos.setObjPos(aList[index]);
}