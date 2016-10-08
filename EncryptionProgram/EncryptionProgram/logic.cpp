//Joshua Yurkovich
//Math Logic

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
	int dec = 0, rem, base = 1;
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
	for (size_t i = 0; i < decNums.size(); ++i) {
		decryptedString += decNums[i];
	}
	return decryptedString;
}

int keyLogic(string key) {
	int keyNum = std::stoi(key,nullptr,10);
	keyNum *= 2;

	return keyNum;
}