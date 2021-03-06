//Joshua Yurkovich
//Encryption Program
//October 7-10, 2016

#include "crypt.h"
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include <chrono>

int main() {

	//README

	//The default file path is in the folder that houses the code for this program.

#pragma region Files
	std::ofstream encryptedString1;
	std::ofstream encryptedFile0;
	std::ifstream encryptedFile1;
	std::ifstream encryptionFile0;
	std::ofstream encryptionKey0;
	std::ofstream decryptedFile0;
#pragma endregion

#pragma region Variables
	string userMenuInput;
	string userInput;
	string decryptedString;
	string userKeyInput;
	string userPathInput;
#pragma endregion

	SetConsoleTitle("Encryption Program");

	do {
		/*1) Encrypt
		* 2) Decrypt*/
		system("cls");
		cout << "----------------------------------------------" << endl;
		cout << "Please select something to do (1-4): " << endl;
		cout << "1) Encrypt a single sentence" << endl;
		cout << "2) Encrypt a file" << endl;
		cout << "3) Decrypt" << endl;
		cout << "4) Exit" << endl;
		cout << "Enter a choice: ";
		std::cin >> userMenuInput;
		std::cin.ignore(1, '\n');


		if (userMenuInput == "1") {
			//File Openings
			encryptedString1.open("encryptedString.txt");
			encryptionKey0.open("encryptionKey.txt");

			//User Input for single string
			cout << "Please enter a string to encrypt (Max 256 characters): ";
			std::getline(std::cin, userInput);

			//User input for encryption key.
			cout << "Please create an encryption key (Max 12 characters of anything): ";
			std::getline(std::cin, userKeyInput);

			//Checks for length of the Key
			while (userKeyInput.length() > 12) {
				cout << "Error: Key too long, Please re-enter a key: ";
				std::getline(std::cin, userKeyInput);
			}

			//Prints the key to a file (Debug Mode)
			encryptionKey0 << userKeyInput;

			//Key Conversion
			int encryptionKey1 = keyLogic(userKeyInput);

			//Encryption
			if (encryptedString1.is_open()) {
				string encrypted = encrypt(userInput, encryptionKey1);

				encryptedString1 << encrypted;
				//Confirmation
				cout << "Encrypting the string" << endl;

				Sleep(1000);

				cout << endl << "The string is now encrypted." << endl;
			}
			else {
				cout << "File not opened.";
			}
			encryptedString1.close();
			encryptionKey0.close();
		}

		else if (userMenuInput == "2") {
			//User Input
			cout << "Please enter a file name or path: ";
			std::getline(std::cin, userInput);
			cout << "Please create an encryption key (Max 12 characters of anything): ";
			std::getline(std::cin, userKeyInput);
			//Checks length of Key
			while (userKeyInput.length() > 12) {
				cout << "Error: Key too long, Please re-enter a key: ";
				std::getline(std::cin, userKeyInput);
			}
			//Output user Input
			cout << "Enter a file path for encrypted file location or leave empty for default: ";
			std::getline(std::cin, userPathInput);


			encryptionKey0 << userKeyInput;

			//Key Conversion
			int encryptionKey1 = keyLogic(userKeyInput);

			encryptionFile0.open(userInput);
			//Checks if a custom filePath was entered or if it is default.
			if (userPathInput.length() == 0)
				encryptedFile0.open("encryptedFile.txt");
			else if (userPathInput.length() > 0)
				encryptedFile0.open(userPathInput);

			//File Encryption
			if (encryptionFile0.is_open()) {
				while (std::getline(encryptionFile0, userInput)) {
					encryptedFile0 << encrypt(userInput, encryptionKey1) << endl;
				}
				cout << "Encrypting the file" << endl;

				Sleep(1000);

				cout << endl << "The file is now encrypted." << endl;
			}
			else {
				cout << "File was unable to open." << endl;
			}
		}
		else if (userMenuInput == "3") {
			//Decryption
			//User Input
			cout << "Please enter the file path of the encrypted file: ";
			std::getline(std::cin, userInput);

			cout << "Please enter the encryption key: ";
			std::getline(std::cin, userKeyInput);
			//Checks length of key
			while (userKeyInput.length() > 12) {
				cout << "Error: Key too long, Please re-enter a key: ";
				std::getline(std::cin, userKeyInput);
			}

			//Key Conversion
			int encryptionKey = keyLogic(userKeyInput);

			cout << "Enter a file path for decrypted file location or leave empty for default: ";
			std::getline(std::cin, userPathInput);

			encryptedFile1.open(userInput);

			//Checks for custom file path
			if (userPathInput.length() == 0)
				decryptedFile0.open("decryptedFile.txt");
			else if (userPathInput.length() > 0)
				decryptedFile0.open(userPathInput);

			//Decryption Logic
			if (encryptedFile1.is_open()) {
				while (std::getline(encryptedFile1, userInput)) {
					decryptedFile0 << decrypt(userInput, encryptionKey) << endl;
				}
				cout << "Decrypting the file" << endl;
				Sleep(1000);
				cout << endl << "The file is now decrypted." << endl;
			}
			else {
				cout << "File was unable to open." << endl;
			}
		}
		Sleep(1000);
	} while (userMenuInput != "4");
}