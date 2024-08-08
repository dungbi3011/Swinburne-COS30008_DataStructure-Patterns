#pragma once 

#include "IntVector.h" 

#include <functional> 

using namespace std;
using Comparable = function<bool(int, int)>;

class SortableIntVector : public IntVector
{
public:
    SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements);

    void sort (Comparable aOrderFunction);
};
