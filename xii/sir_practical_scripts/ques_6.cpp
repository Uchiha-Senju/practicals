#include <iostream>
#include <stdio.h>
using namespace std;

bool isUpper (char ch) {
  return ch >='A' and ch <= 'Z';
}

bool isLower (char ch) {
  return ch >='a' and ch <= 'z';
}

char toUpper (char ch) {
  if (isLower(ch))
    return (ch - 0b00100000);
  return ch;
}

char toLower (char ch) {
  if (isUpper(ch))
    return (ch + 0b00100000);
  return ch;
}

int main() {
  char str[1000];
  cout << "Give your string :\n\t";
  // cin << flush;
  cin.getline(str, 1000, '\n');


  for (int i = 0; str[i] != '\0'; ++i) {
    if (isUpper(str[i]))
      str[i] = toLower(str[i]);
    else if (isLower(str[i]))
      str[i] = toUpper(str[i]);
  }

  cout << str;
  
  while (getchar() != '\n');
  getchar();
}
