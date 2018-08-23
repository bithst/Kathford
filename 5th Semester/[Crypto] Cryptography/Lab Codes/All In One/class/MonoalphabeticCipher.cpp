#include "header/Cryptography.h"
using namespace std;

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