//Joshua Yurkovich
//Encryption Program
//October 7-10, 2016

#include "crypt.h"
#include <fstream>

int main() {
	std::ofstream binaryFile;
	string userMenuInput;
	string userInput;
	string encryptedString;
	string decryptedString;
	string userKeyInput;

	binaryFile.open("C:/Users/Josh/Desktop/binary.txt");
	//Menu
		/*1) Encrypt
		* 2) Decrypt*/
	cout << "Input a string to convert to binary: ";
	std::getline(std::cin,userMenuInput);
	cout << endl;

	cout << "Your string in binary is: " << endl;
	binaryFile << convertToBinary(userMenuInput);
	

	//Encryption
		//Enter String to Encrypt (Max 256 characters)
		//Encrypt String
		//Show Encrypted String
	
	//Key
		//Enter & Set 12 character string of Alpha-Numeric-Special
		//Key Conversion Logic

	//Decryption
		//Enter Key
		//Decrypt String
		//Show Decrypted String
}