#pragma once 
#include "SortableIntVector.h" 
#include <functional> 

using namespace std;
using Comparable = function <bool(int, int)>;

//constructor
SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : IntVector::IntVector(aArrayOfIntegers, aNumberOfElements) {}

void SortableIntVector::sort(Comparable aOrderFunction) {
	int i = 1;
	for (i = 0; i < size(); i++)
	{
		for(int j = i + 1; j <= size(); j++)
		{
			if (aOrderFunction(get(j), get(i)) == true) { swap(j, i); }
		}
	}
}

