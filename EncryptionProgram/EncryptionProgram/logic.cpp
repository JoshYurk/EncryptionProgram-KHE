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