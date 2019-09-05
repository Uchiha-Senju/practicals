#include <iostream>
#include <limits>
using namespace std;

unsigned int strlen(const char* str) {
  unsigned len;
  for (len = 0; str[len] != '\0'; ++len);
  return len;
}

char* strcopy(char* str1, const char* str2) {
  for (int i = strlen(str2) - 1; i > -1; --i)
    str1[i] = str2[i];
  return str1;
}

char* strcat (const char* str1, const char* str2) {
  unsigned len1 = strlen(str1), len2 = strlen(str2);
  char* cat_str = new char[len1 + len2 + 1];
  
  for (int i = 0 ; i < len1; ++i) 
    cat_str[i] = str1[i];
  for (int i = 0 ; i < len2; ++i)
    cat_str[i + len1] = str2[i];
  
  cat_str[len2 + len1] = '\0';
  
  return cat_str;
}

bool isPalindrome(const char* str) {
  bool is_palin = true;
  unsigned len = strlen(str);
  for (int i = len/2 - 1; i > -1 and is_palin; --i)
    is_palin &= (str[i] == str[len - i - 1]);
  return is_palin;
}

int main() {
  char *str, *concat_str;
  const char* yes_palin = "Hello Palindrome ";
  const char*  no_palin = "Hello Non-palindrome ";
  unsigned len;
  
  cout << "Enter string length : "; cin >> len;
  str = new char[len + 1];
  concat_str = new char[len + 22];
  cout << "Enter string : \n\t"; 
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
  cin.clear();
  cin.getline(str, len + 1, '\n');
  
  if (isPalindrome(str))
    strcopy(concat_str, strcat(yes_palin, str));
  else 
    strcopy(concat_str, strcat(no_palin, str));
  
  cout << concat_str;
  
  while (getchar() != '\n');
  getchar();
}