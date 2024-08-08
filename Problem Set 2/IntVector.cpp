#pragma once
#include "IntVector.h"
#include <iostream>
#include <cstddef> 

using namespace std;

//constructor
IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
{
    fNumberOfElements = aNumberOfElements;
    fElements = new int[fNumberOfElements];

    for (size_t i = 0; i < fNumberOfElements; i++)
    {
        fElements[i] = aArrayOfIntegers[i];
    }
}

// Destructor: release memory 
// Destructor is virtual to allow inheritance 

IntVector::~IntVector()
{
    delete[] fElements;
}

// size getter 
size_t IntVector::size() const
{
    return fNumberOfElements;
}

// element getter 
const int IntVector::get(size_t aIndex) const
{
    return operator[](aIndex);
}

// swap two elements within the vector 
void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex)
{
    size_t num = get(aSourceIndex);
    fElements[aSourceIndex] = get(aTargetIndex);
    fElements[aTargetIndex] = num;
}

// indexer 
const int IntVector::operator[](size_t aIndex) const
{
    return fElements[aIndex];
}

