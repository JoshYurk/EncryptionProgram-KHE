//Joshua Yurkovich
//Math Logic

#include "crypt.h"
#include <bitset>
using std::bitset;

int convertToBinary(string input) {
	int* binaryArray = new int[256];
	int i = 0;
	while (i != input.length()) {
		bitset<8> bitset1(input[i]);
		string binaryString = bitset1.to_string();
		binaryArray[i] = std::stoi(binaryString);
	}
}