#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <string>
#include <ctype.h>
using namespace std;

class Crypto {
public:
    Crypto(string);
    ~Crypto();

    static string CaesarCipher(string, int, bool);
    static string MonoalphabeticCipher(string, string, bool);
    static string PlayfairCipher(string, string, bool);
};

#endif