//Joshua Yurkovich
//Encryption Logic
//encrypt.cpp

#include "crypt.h"

string encrypt(string unencrypted, int key) {
	string encryptedString;
	string binaryString;

	binaryString = convertToBinary(unencrypted);

	

	encryptedString = invertBinary(binaryString) + convertToBinary(std::to_string(key));

	return encryptedString;
}