#ifndef ENCRYPT_DECRYPT
#define ENCRYPT_DECRYPT

//Includes
#include <string>
#include <iostream>

//Usings
using std::cout;
using std::endl;
using std::string;


//Functions
string encrypt(string unencrypted);
string decrypt(string encrypted);
int convertToBinary(string input);
int convertToASCII(int input);
int keyConversion(string key);

//Variables
string userMenuInput;
string userInput;
string encryptedString;
string decryptedString;
string userKeyInput;

#endif 

