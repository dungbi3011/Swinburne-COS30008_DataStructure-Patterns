#pragma once 

#include "ShakerSortableIntVector.h" 
#include <functional>

using namespace std;

//constructor
ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : SortableIntVector::SortableIntVector(aArrayOfIntegers, aNumberOfElements) {}

void ShakerSortableIntVector::sort(Comparable aOrderFunction) {
	int i = 1;
	for (i = 0; i < size(); i++)
	{
		for (int j = i + 1; j < size(); j++)
		{
			if (aOrderFunction(get(j), get(i)) == true) { swap(j, i); }
		}
	}
}
