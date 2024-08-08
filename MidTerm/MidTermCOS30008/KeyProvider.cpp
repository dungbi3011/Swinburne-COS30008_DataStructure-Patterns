#pragma once
#include "KeyProvider.h"
#include <string>

using namespace std;

KeyProvider::KeyProvider(const string& aKeyword) : //components of KeyProvider class
	fSize(aKeyword.length()),
	fIndex(0),
	fKeyword(new char[aKeyword.length()])
{
	initialize(aKeyword);
}

KeyProvider::~KeyProvider()
{
	delete[] fKeyword; //release memory
}

void KeyProvider::initialize(const string& aKeyword)
{
	fSize = aKeyword.length();
	fKeyword = new char[fSize];
	for (size_t i = 0; i < fSize; i++)
	{
		fKeyword[i] = static_cast<char>(toupper(aKeyword[i])); //similar to constructor (converting string to char)
	}
	fIndex = 0;
}

char KeyProvider::operator*() const 
{
	return fKeyword[fIndex]; //accessing current keyword character
}	

KeyProvider& KeyProvider::operator<<(char aKeyCharacter)
{	
	if (isalpha(aKeyCharacter)) //checking alphabet letters
	{
		fKeyword[fIndex] = static_cast<char>(toupper(aKeyCharacter)); //replacing with AKEYCHARACTER
	}

	fIndex++; //KeyProvider advances to next keyword character
	
	if (fIndex >= fSize) 
	{ 
		fIndex = 0; //checking to reset keyword index
	}

	return *this;
}
