//Joshua Yurkovich
//Decryption Logic
//decrypt.cpp

#include "crypt.h"

string decrypt(string encryptedString, int key) {
	string decryptedString;
	string keyStr = convertToBinary(std::to_string(key));

	string key3 = encryptedString.substr(encryptedString.length() - keyStr.length(), keyStr.length());
	string encrypted = encryptedString.erase(encryptedString.length() - keyStr.length(), keyStr.length());

	if (key3 == keyStr) {
		decryptedString = printString(convertFromBinary(invertBinary(encrypted)));
	}
	else {
		decryptedString = printString(convertFromBinary(encryptedString));
	}

	return decryptedString;
}