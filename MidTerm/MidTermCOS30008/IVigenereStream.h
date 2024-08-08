#pragma once
#include <fstream>
#include <functional>

#include "Vigenere.h"

using Cipher = function<char(Vigenere& aCipherProvider, char aCharacter)>;

class iVigenereStream
{
private:
	ifstream fIStream;
	Vigenere fCipherProvider;
	Cipher fCipher;

public:

	iVigenereStream(Cipher aCipher, const string& aKeyword, const char* aFileName = nullptr); // [8]

	~iVigenereStream(); // [2]

	void open(const char* aFileName); // [8]

	void close(); // [2]

	void reset(); // [10]

	// conversion operator to bool
	operator bool() { return !eof(); }

	// stream positioning
	uint64_t position() { return fIStream.tellg(); }

	void seekstart() { fIStream.clear(); fIStream.seekg(0, ios_base::beg); }

	bool good() const; // [3]

	bool is_open() const; // [3]

	bool eof() const; // [3]

	iVigenereStream& operator>>(char& aCharacter); // [17]
};