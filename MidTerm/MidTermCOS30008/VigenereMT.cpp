#pragma once
#include "Vigenere.h"

using namespace std;

void Vigenere::initializeTable()
{
	for (char row = 0; row < CHARACTERS; row++)
	{
		char lChar = 'B' + row;

		for (char column = 0; column < CHARACTERS; column++)
		{
			if (lChar > 'Z')
				lChar = 'A';

			fMappingTable[row][column] = lChar++;
		}
	}
}

Vigenere::Vigenere(const string& aKeyword) : fKeyword(aKeyword), fKeywordProvider(KeyProvider(aKeyword))
{
	initializeTable();
}

string Vigenere::getCurrentKeyword()
{
	string result;

	for (size_t i = 0; i < fKeyword.length(); i++) {
		result += *fKeywordProvider; 
		fKeywordProvider << *fKeywordProvider;
		//copying keyword characters into result string
	}

	return result;
}

void Vigenere::reset()
{
	fKeywordProvider.initialize(fKeyword); 
}

char Vigenere::encode(char aCharacter)
{
	if (isalpha(aCharacter))
	{
		bool isLower = islower(aCharacter); //checking aCharacter uppercase or lowercase

		char encoded = fMappingTable [*fKeywordProvider - 'A'] [toupper(aCharacter) - 'A'];

		fKeywordProvider << aCharacter;

		return isLower ? static_cast<char>(tolower(encoded)) : (encoded); //updating current keyword character as part of the autokey cipher process
	}
	else
	{
		return aCharacter; //non-alphabetical character
	}
}

char Vigenere::decode(char aCharacter)
{
	if (isalpha(aCharacter))
	{
		bool isLower = islower(aCharacter); //checking aCharacter uppercase or lowercase

		char encoded = static_cast<char>(toupper(aCharacter));

		char decoded = 0;

		for (char column = 0; column < CHARACTERS; column++)
		{
			if (fMappingTable [*fKeywordProvider - 'A'] [column] == encoded)
			{
				decoded = static_cast<char>(column + 'A');
				break;
			}
		}
		fKeywordProvider << decoded;

		return isLower ? static_cast<char>(tolower(decoded)) : (decoded); //updating current keyword character as part of the autokey cipher process
	}
	else
	{
		return aCharacter; //non-alphabetical character
	}
}