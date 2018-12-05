#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int precedence(char ch) {
  if (ch == '(') {
    return 0;
  } else if (ch == '+' || ch == '-') {
    return 1;
  } else if (ch == '*' || ch == '/') {
    return 2;
  }
}

int main() {
  string postfix;
  string infix;

  cout<<"Enter a infix expression: ";
  cin>>infix;

  for(int i = 0; i < infix.length(); i++) {
    char ch = infix[i];

    if (ch == '(') {
      postfix.push_back(ch);
    } else if (ch == ')') {
      while (ch = postfix.back() != ')') {
        cout<<ch;
        postfix.pop_back();
      }
      postfix.pop_back();
    } else if (isalnum(ch)) {
      cout << ch;
    } else {
      while (postfix.length() != 0 && precedence(ch) <= precedence(postfix.back())) {
          cout<<postfix.back();
          postfix.pop_back();
      }
      postfix.push_back(ch);
    }
  } 

  return 0;
}