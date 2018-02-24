#include <iostream>
#include <string>
#include <ctype.h>  // For performing operations on characters. isalpha(), toupper(), tolower(), etc...
#include <stdlib.h> // For quiting the program. exit(0)

#define _ENCRYPT true
#define _DECRYPT false

using namespace std;  // I know it is a bad habit but it saves time

class Crypto {
  public:
  static string CaesarCipher(string, int, bool);
  static string MonoalphabeticCipher(string, string, bool);
};

int main() {
  const string methods[] = {
    "Caesar cipher",
    "Monoalphabetic cipher"
  };
  int choice;
  string message, plaintext, ciphertext;
  
  message = "Hello world. This is a test, 123.";
  
  // Menu
  cout<<"### Demonstration of Cryptographic Algorithms ###"<<endl;
  while(true) {
    cout<<endl<<"Choose an algorithm"<<endl;
    for(int i = 0; i < sizeof(methods)/sizeof(*methods); i++) {
      cout<<"["<<i + 1<<"] "<<methods[i]<<endl;
    }
    cout<<"[0] Quit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    
    switch(choice) {
      case 0:
      cout<<"Exiting the program"<<endl;
      exit(0);
      
      case 1:
      ciphertext = Crypto::CaesarCipher(message, 3, _ENCRYPT);
      plaintext = Crypto::CaesarCipher(ciphertext, 3, _DECRYPT);
      
      cout<<endl<<"# Caesar Cipher #"<<endl;
      cout<<"Message: "<<message<<endl;
      cout<<"Key: "<<3<<endl;
      cout<<endl<<"Encrypting \""<<message<<"\""<<endl<<"gives \""<<ciphertext<<"\""<<endl;
      cout<<endl<<"Decrypting \""<<ciphertext<<"\""<<endl<<"gives \""<<plaintext<<"\""<<endl;
      break;
      
      case 2:
      ciphertext = Crypto::MonoalphabeticCipher(message, "QWERTYUIOPASDFGHJKLZXCVBNM", _ENCRYPT);
      plaintext = Crypto::MonoalphabeticCipher(ciphertext, "QWERTYUIOPASDFGHJKLZXCVBNM", _DECRYPT);
      
      cout<<endl<<"# Monoalphabetic Cipher #"<<endl;
      cout<<"Message: "<<message<<endl;
      cout<<"Key: "<<"\"QWERTYUIOPASDFGHJKLZXCVBNM\""<<endl;
      cout<<endl<<"Encrypting \""<<message<<"\""<<endl<<"gives \""<<ciphertext<<"\""<<endl;
      cout<<endl<<"Decrypting \""<<ciphertext<<"\""<<endl<<"gives \""<<plaintext<<"\""<<endl;
      break;
      
      default:
      cout<<"Invalid choice!"<<endl<<"Please try again."<<endl;
    }
  }
  
  
  return 0;
}

string Crypto::CaesarCipher(string message, int key, bool encrypt) {
  // Checking for bad input(s)
  if(key < 0 || key > 25) { // If a invalid key is sent, return nothing
    return NULL;
  }
  
  // Variable declarations
  string result;  // Stores the final result
  int letter_case;  // Used for defining the case of the result
  int shift_amount;  // Used for shifting the input character codes in the range [0 - 25]
  char ch;  // Used for storing individual character of the message while processing
  
  // Preparing for encryption/decryption
  shift_amount = (int)'a';
  if(encrypt) {
    letter_case = (int)'A'; // Shift the result to the ascii equivalent of capital 'A'
  } else {
    key = -key; // To change the shifting direction for decryption
    letter_case = (int)'a'; // Shift the result to the ascii equivalent of small 'a'
  }
  
  //NOTE
  // string.push_back(char*) is used for appending the character at the end of the string
  
  // Performing encryption/decryption
  for(int i = 0; i < message.length(); i++) { // For each character in the input message
    ch = tolower(message[i]); // Get a lower case version of the character
    
    if(isalpha(ch)) { // Check if the character is a alphabet
      result.push_back((char)((((ch - shift_amount) + key) % 26) + letter_case)); // Perform encryption/decryption on the character
    } else {  // If the character is not an alphabet, do nothing to it and append it to the result
      result.push_back(ch);
    }
  }
  
  return result;
}

string Crypto::MonoalphabeticCipher(string message, string key, bool encrypt) {
  // Checking for bad input(s)
  if(key.length() != 26) {  // If the key doesn't have the required number of characters, return nothing
    return NULL;
  }
  for(int i = 0; i < key.length(); i++) {
    for(int j = 0; j < key.length(); j++) {
      if(i != j && tolower(key[i]) == tolower(key[j])) {  // If the key has repeating alphabets, return nothing
        return NULL;
      }
    }
  }
  
  // Variable decleration
  string result;  // Stores the final result
  int letter_case;  // Used for defining the case of the result
  int shift_amount;  // Used for shifting the input character codes in the range [0 - 25]
  char ch;  // Used for storing individual character of the message while processing
  
  // Preparing for encryption/decryption
  shift_amount = (int)'a';
  for(int i = 0; i < key.length(); i++) {
    key[i] = tolower(key[i]); // Set the key to lower case
  }
  if(encrypt) {
    letter_case = (int)'A'; // Shift the result to the ascii equivalent of capital 'A'
  } else {
    letter_case = (int)'a'; // Shift the result to the ascii equivalent of small 'a'
  }
  
  // Performing encryption/decryption
  if(encrypt) { // For encryption
    for(int i = 0; i < message.length(); i++) { // For each character in the message
      ch = tolower(message[i]); // Change the case to lower case for consistency
      
      if(isalpha(ch)) { // If the character is an alphabet
        result.push_back(toupper(key[(int)(ch - shift_amount)])); // Append the value in key at the positon of the numeric value of the character of the message
      } else {  // If the character is not an alphabet, just append it as is to the result
        result.push_back(ch);
      }
    }
  } else {  // For decryption
    for(int i = 0; i < message.length(); i++) { // For each character in the message
      ch = tolower(message[i]); // Change the case to lower case for consistency
      
      if(isalpha(ch)) { // If the character is an alphabet
        for(int j = 0; j < key.length(); j++) { // Loop through each key value
          if(ch == key[j]) {  // If the character matches the key value
            result.push_back((char)(j + letter_case));  // Append the character equivalent of the position in key where the match occured
          }
        }
      } else {  // If the character is not an alphabet, just append it as is to the result
        result.push_back(ch);
      }
    }
  }
  
  return result;
}









