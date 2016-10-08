//Joshua Yurkovich
//Encryption Program
//October 7-10, 2016

#include "crypt.h"
#include <fstream>

int main() {
	std::ofstream encryptedFile;
	std::ifstream encryptionFile;
	string userMenuInput;
	string userInput;
	string decryptedString;
	string userKeyInput;


	//Menu
		/*1) Encrypt
		* 2) Decrypt*/
	cout << "Please select something to do (1-4): " << endl;
	cout << "1) Encrypt a single sentence" << endl;
	cout << "2) Encrypt a file" << endl;
	cout << "3) Decrypt" << endl;
	cout << "4) Exit" << endl;
	cout << "Enter a choice: ";
	std::cin >> userMenuInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (userMenuInput == "1") {
		encryptedFile.open("C:/Users/Josh/Desktop/encryptedString.txt");
		//User Input for single string
		cout << "Please enter a string to encrypt (Max 256 characters): ";
		std::getline(std::cin, userInput);
		//User input for encryption key.
		cout << "Please create an encryption key (Max 12 characters of anything): ";
		std::getline(std::cin, userKeyInput);

		int encryptionKey = keyLogic(userKeyInput);
		encryptedFile << encrypt(userInput, encryptionKey);


	}
	if (userMenuInput == "2") {
		cout << "Please enter a file name or path: ";
		std::getline(std::cin, userInput);
		cout << "Please create an encryption key (Max 12 characters of anything): ";
		std::getline(std::cin, userKeyInput);
	}
	if (userMenuInput == "3") {
		cout << "Please enter the encryption key: ";
		std::getline(std::cin, userKeyInput);
		cout << "Please enter the string or file path: ";
		std::getline(std::cin, userInput);

		encryptionFile.open(userInput);
		if (encryptionFile.is_open()) {

		}
		else {
			cout << "Your decrypted string is: " << endl << decrypt(userInput, keyLogic(userKeyInput)) << endl;
		}
	}
	if (userMenuInput == "4") {
		exit(0);
	}
}