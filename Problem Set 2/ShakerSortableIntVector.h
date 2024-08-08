#pragma once 
#include "SortableIntVector.h" 
#include <functional>

class ShakerSortableIntVector : public SortableIntVector
{
public:
    ShakerSortableIntVector (const int aArrayOfIntegers[], size_t aNumberOfElements);

    void sort (Comparable aOrderFunction) ;
}; 