//Joshua Yurkovich
//Decryption Logic
//decrypt.cpp

#include "crypt.h"

string decrypt(string encryptedString, int key) {
	string keyStr = convertToBinary(std::to_string(key));

	encryptedString = encryptedString.erase(encryptedString.length() - keyStr.length(), keyStr.length());

	string decryptedString = printString(convertFromBinary(invertBinary(encryptedString)));

	return decryptedString;
}