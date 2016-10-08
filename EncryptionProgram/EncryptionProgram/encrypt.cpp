//Joshua Yurkovich
//Encryption Logic

#include "crypt.h"

string encrypt(string unencrypted, int key) {
	string encryptedString;

	encryptedString = convertToBinary(unencrypted);
	int encryptedNum = std::stoi(encryptedString, nullptr, 10);

	encryptedNum = encryptedNum + key;

	string encryptedIntStr = std::to_string(encryptedNum);

	return encryptedIntStr;
}