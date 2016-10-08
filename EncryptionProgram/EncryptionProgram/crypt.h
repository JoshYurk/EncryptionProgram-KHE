#ifndef ENCRYPT_DECRYPT
#define ENCRYPT_DECRYPT

//Includes
#include <string>
#include <iostream>
#include <vector>

//Usings
using std::cout;
using std::endl;
using std::string;


//Functions
string encrypt(string, int);
string invertBinary(string);
string decrypt(string, int);
string convertToBinary(string);
string printString(std::vector<int>);
std::vector<int> convertFromBinary(string);
int keyLogic(string);

#endif 

