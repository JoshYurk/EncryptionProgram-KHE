//Joshua Yurkovich
//Math Logic
//logic.cpp

#include "crypt.h"
#include <bitset>

using std::bitset;


string convertToBinary(string input) {
	string binaryString = "";
	//Converts the entire string to binary and stores it.
	for (size_t i = 0; i < input.length(); ++i) {
		bitset<8> bitset1(input[i]);
		binaryString = binaryString + bitset1.to_string();
	}
	return binaryString;
}

std::vector<int> convertFromBinary(string binaryNum) {
	int num;
	std::vector<string> binaryNumbers;
	std::vector<int> decimalNumbers;
	string binary = "";
	//Splits up the binary number into 8 bit sections.
	for (size_t i = 0; i < binaryNum.length(); i+=8) {
		for (int j = 0; j < 8; ++j) {
			binary += binaryNum[j + i];
		}
		binaryNumbers.push_back(binary);
		binary = "";
	}

	for (size_t k = 0; k < binaryNumbers.size(); ++k)
	{
		//Converts binary to decimal
		num = std::stoi(binaryNumbers[k], nullptr,2);	
		decimalNumbers.push_back(num);
	}
	return decimalNumbers;
}

string printString(std::vector<int> decNums) {
	string decryptedString = "";
	//Prints the Letters
	for (size_t i = 0; i < decNums.size(); ++i) {
		decryptedString += decNums[i];
	}
	return decryptedString;
}

int keyLogic(string key) {
	int keyNum = 0;
	//Adds the ascii values of the key together
	for (size_t i = 0; i < key.length(); ++i) {
		keyNum = keyNum + key[i];
	}

	keyNum *= 2;

	return keyNum;
}

string invertBinary(string binStr) {
	string invBinStr;
	for (size_t i = 0; i < binStr.length(); ++i) {
		if (binStr[i] == '0') {
			invBinStr.insert(i, "1");
		}
		else if (binStr[i] == '1') {
			invBinStr.insert(i, "0");
		}
	}
	return invBinStr;
}