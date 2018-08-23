#include <iostream>
#include <string>
#include <ctype.h>  // For performing operations on characters. isalpha(), toupper(), tolower(), etc...
#include <stdlib.h> // For quiting the program some console operations. exit(0)
#include "class/header/Cryptography.h"

#define _ENCRYPT true
#define _DECRYPT false

using namespace std;  // I know it is a bad habit but it saves time

int main() {
    const string methods[] = {
        "Caesar cipher",
        "Monoalphabetic cipher"
    };
    int choice;
    string message, plaintext, ciphertext;
    
    message = "Hello world. This is a test, 123.";


    Crypto::PlayfairCipher("carnival", "apple", true);
    //awdnajwnjdjawdkajwnnjnnjakwndnnnn
    

    return 0;
    
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
            case 0: // Quit the program
            cout<<"Exiting the program"<<endl;
            exit(0);

            case 1: // Caesar cipher
            ciphertext = Crypto::CaesarCipher(message, 3, _ENCRYPT);
            plaintext = Crypto::CaesarCipher(ciphertext, 3, _DECRYPT);

            cout<<endl<<"# Caesar Cipher #"<<endl;
            cout<<"Message: "<<message<<endl;
            cout<<"Key: "<<3<<endl;
            cout<<endl<<"Encrypting \""<<message<<"\""<<endl<<"gives \""<<ciphertext<<"\""<<endl;
            cout<<endl<<"Decrypting \""<<ciphertext<<"\""<<endl<<"gives \""<<plaintext<<"\""<<endl;
            break;

            case 2: // Monoalphabetic cipher
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