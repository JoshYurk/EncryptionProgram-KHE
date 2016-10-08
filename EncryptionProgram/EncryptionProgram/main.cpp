//Joshua Yurkovich
//Encryption Program
//October 7-10, 2016

#include "crypt.h"
#include <fstream>
#include <Windows.h>

int main() {
	std::ofstream encryptedFile;
	std::ifstream encryptedFile1;
	std::ifstream encryptionFile;
	std::ofstream encryptionKey;
	std::ofstream decryptedFile;

	string userMenuInput;
	string userInput;
	string decryptedString;
	string userKeyInput;
	string userPathInput;
	

	SetConsoleTitle("Encryption Program");
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
	std::cin.ignore(1, '\n');

	if (userMenuInput == "1") {
		encryptedFile.open("encryptedString.txt");
		encryptionKey.open("encryptionKey.txt");
		//User Input for single string
		cout << "Please enter a string to encrypt (Max 256 characters): ";
		std::getline(std::cin, userInput);
		//User input for encryption key.
		cout << "Please create an encryption key (Max 12 characters of anything): ";
		std::getline(std::cin, userKeyInput);
		while (userKeyInput.length() > 12) {
			cout << "Error: Key too long, Please re-enter a key: ";
			std::getline(std::cin, userKeyInput);
		}

		encryptionKey << userKeyInput;

		int encryptionKey = keyLogic(userKeyInput);
		encryptedFile << encrypt(userInput, encryptionKey);

		cout << endl << "String is now encrypted." << endl;

		encryptedFile.close();
	}
	if (userMenuInput == "2") {
		cout << "Please enter a file name or path: ";
		std::getline(std::cin, userInput);
		cout << "Please create an encryption key (Max 12 characters of anything): ";
		std::getline(std::cin, userKeyInput);
		while (userKeyInput.length() > 12) {
			cout << "Error: Key too long, Please re-enter a key: ";
			std::getline(std::cin, userKeyInput);
		}
		cout << "Enter a file path for encrypted file location or leave empty for default: ";
		std::getline(std::cin, userPathInput);

		encryptionKey << userKeyInput;

		int encryptionKey = keyLogic(userKeyInput);

		encryptionFile.open(userInput);
		if (userPathInput.length() == 0)
			encryptedFile.open("encryptedFile.txt");
		else if (userPathInput.length() > 0)
			encryptedFile.open(userPathInput);

		if (encryptionFile.is_open()) {
			while (std::getline(encryptionFile, userInput)) {
				encryptedFile << encrypt(userInput, encryptionKey) << endl;
			}
			cout << endl << "File is now encrypted." << endl;
		}
		else {
			cout << "File was unable to open." << endl;
		}
		encryptedFile.close();
		encryptionFile.close();

	}
	if (userMenuInput == "3") {
		cout << "Please enter the file path of the encrypted file: ";
		std::getline(std::cin, userInput);

		cout << "Please enter the encryption key: ";
		std::getline(std::cin, userKeyInput);
		while (userKeyInput.length() > 12) {
			cout << "Error: Key too long, Please re-enter a key: ";
			std::getline(std::cin, userKeyInput);
		}

		int encryptionKey = keyLogic(userKeyInput);

		cout << "Enter a file path for decrypted file location or leave empty for default: ";
		std::getline(std::cin, userPathInput);

		encryptedFile1.open(userInput);

		if (userPathInput.length() == 0)
			decryptedFile.open("decryptedFile.txt");
		else if (userPathInput.length() > 0)
			decryptedFile.open(userPathInput);
		
		if (encryptedFile1.is_open()) {
			while (std::getline(encryptedFile1, userInput)) {
				decryptedFile << decrypt(userInput, encryptionKey) << endl;
			}
			cout << endl << "File is now decrypted." << endl;
		}

		encryptedFile1.close();
		decryptedFile.close();
	}
}