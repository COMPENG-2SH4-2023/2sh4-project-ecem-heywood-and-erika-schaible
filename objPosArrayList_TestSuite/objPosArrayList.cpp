#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; //200 elements on the heap
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
    //need error check, what if list size is at capacity??
    //check if sizeList is equal to sizeArray. If yes, don't insert
    if(sizeList == sizeArray)
    {
        return;
    }
    for(int i = sizeList; i > 0; i--)
    {
        aList[i].setObjPos(aList[i-1]); //shuffles all the elements towards the tail
    }
    aList[0].setObjPos(thisPos);
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    //need error check here too
    if(sizeList == sizeArray)
    {
        return;
    }
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
    returnPos.setObjPos(aList[index]);
}