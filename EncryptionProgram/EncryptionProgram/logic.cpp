//Joshua Yurkovich
//Math Logic

#include "crypt.h"
#include <bitset>

using std::bitset;

string binaryString = "";
string convertToBinary(string input) {
	//Converts the entire string to binary and stores it.
	for (int i = 0; i < input.length(); ++i) {
		bitset<8> bitset1(input[i]);
		binaryString = binaryString + bitset1.to_string();
	}
	return binaryString;
}

string convertFromBinary(string binaryNum) {
	long bin, dec = 0, rem, num, base = 1;
	//Converts the binaryString to an Integer
	num = std::stoi(binaryNum);

	bin = num;

	while (num > 0) {
		rem = num % 10;
		dec = dec + rem * base;
		base *= 2;
		num /= 10;
	}
	string decimal = std::to_string(dec);
	
	return decimal;
}