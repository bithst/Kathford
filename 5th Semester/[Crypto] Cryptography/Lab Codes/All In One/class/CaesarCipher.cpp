#include "header/Cryptography.h"
using namespace std;

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