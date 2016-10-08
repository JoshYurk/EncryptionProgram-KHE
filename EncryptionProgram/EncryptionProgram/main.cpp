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
	cout << "Please select something to do (1-4): " << endl;
	cout << "1) Encrypt a single sentence" << endl;
	cout << "2) Encrypt a file" << endl;
	cout << "3) Decrypt" << endl;
	cout << "4) Exit" << endl;
	std::cin >> userMenuInput;

	if (userMenuInput == "1") {
		//User Input for single string
		cout << "Please enter a string to encrypt (Max 256 characters): ";
		std::getline(std::cin, userInput);
		//User input for encryption key.
		cout << "Please create an encryption key (Max 12 characters of anything): " ;
		std::getline(std::cin, userKeyInput);



	}
	else if (userMenuInput == "2") {
		cout << "Please enter a file name or path: ";
		std::getline(std::cin, userInput);
		cout << "Please create an encryption key (Max 12 characters of anything): ";
		std::getline(std::cin, userKeyInput);
	}

	//Decryption
		//Enter Key
		//Decrypt String
		//Show Decrypted String
}