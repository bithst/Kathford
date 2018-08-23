#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
using namespace std;

string CaesarCipher(string, int, bool);


int main() {
  string message;
  int choice, key;
  
  cout<<"### Encryption and Decryption Using Caesar Cipher ###"<<endl;
  while(true) {
    cout<<"[1] Encrypt"<<endl;
    cout<<"[2] Decrypt"<<endl;
    cout<<"[0] Quit"<<endl;
    cout<<"Choose an option: ";
    cin>>choice;
    
    if(choice == 0) {
      cout<<"Exiting the program."<<endl;
      return 0;
    }
    
    switch(choice) {
      case 1:
        cout<<"Enter the message: ";
        cin>>message;
        cout<<"Enter the key: ";
        cin>>key;
        cout<<"Encrypted message: "<<CaesarCipher(message, key, true)<<endl;
        break;

      case 2:
        cout<<"Enter the message: ";
        cin>>message;
        cout<<"Enter the key: ";
        cin>>key;
        cout<<"Decrypted message: "<<CaesarCipher(message, key, false)<<endl;
        break;
        
      default:
        cout<<"Try again! Enter a valid option."<<endl;
    }
  }
}

string CaesarCipher(string message, int key, bool encrypt) {
  string result;
  int letter_case;
  
  if(encrypt) {
    letter_case = 64; 
  } else {
    key = -key;
    letter_case = 96;
  }
  
  char ch;
  for(int i = 0; i < message.length(); i++) {
    ch = message[i];
    
    if(isalpha(ch)) {
      ch = tolower(ch);
      result.push_back((char)((((ch - 96) + key) % 26) + letter_case));
    } else {
      result.push_back(ch);
    }
  }
  
  return result;
}