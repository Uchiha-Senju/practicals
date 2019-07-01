#include <iostream>
#include <fstream>
using namespace std;

bool isUpperCase(char c) {
  return (c <= 'Z' and c >= 'A');
}
bool isLowerCase(char c) {
  return (c <= 'z' and c >= 'a');
}
bool isAlpha(char c) {
  return isUpperCase(c) or isLowerCase(c);
}
bool isDigit(char c) {
  return (c <= '9' and c >= '0');
}
bool isAlphaNum(char c) {
  return isAlpha(c) or isDigit(c);
}
bool isVowel(char c) {
  switch (c) {
    case 'a' : case 'e' : case 'i' : case 'o' : case 'u' : case 'A' : case 'E' : case 'I' : case 'O' : case 'U' : 
      return true;
      break;
    default : 
      return false;
      break;
  }
}
char readNthByteFromCurrentPosition(ifstream& file, int n) {
  file.seekg(n, std::ios::cur);
  char ch = file.get();
  file.seekg(-n, std::ios::cur);
  return ch;
}

int main() {
  char file_name[51];
  cout << "Enter file name (max 50 char) : "; cin.getline(file_name, 51, '\n');
  ifstream input_file (file_name, ios::in);
  if (not input_file.is_open()) {
    cout << "ERR : File does not exist\n";
    return 0;
  }
  input_file.seekg(0, ios::beg);
  
  input_file.seekg(0, ios::end);
  long long file_length = input_file.tellg();
  input_file.seekg(0, ios::beg);  
  
  char ch;
  int no_of_blanks = 0, no_of_lines = 0, no_of_up = 0, no_of_low = 0, no_of_lines_start_up = 0, no_of_words = 0, no_of_digits = 0, no_of_words_end_vow = 0;
  bool word_started = false;

  //For first character
  input_file.get(ch);
  input_file.seekg(1, ios::beg);
  if (isUpperCase(ch)) {
    no_of_up++; word_started = true;
    // if (readNthByteFromCurrentPosition(input_file, -1) == '\n') 
      no_of_lines_start_up++;
  } else if (isLowerCase(ch)) {
    no_of_low++; word_started = true;
  } else if (isDigit(ch)) {
    no_of_digits++;
  } else if (ch == '\n') {
    no_of_lines++;
    // if (word_started)
      // no_of_words++;
    // word_started = false;
    // if (isVowel( readNthByteFromCurrentPosition(input_file, -1) )) 
      // no_of_words_end_vow++;
    // else if (readNthByteFromCurrentPosition(input_file, -1) == '\n') 
      no_of_blanks++;
  // } else if (ch == ' ') {
    // no_of_words++;
    // if (isVowel( readNthByteFromCurrentPosition(input_file, -1) )) 
      // no_of_words_end_vow++;
  }
  
  while (not input_file.eof()) {
    input_file.get(&ch, 1);
    input_file.seekg(1, ios::cur);
    if (isUpperCase(ch)) {
      no_of_up++; word_started = true;
      if (readNthByteFromCurrentPosition(input_file, -1) == '\n') 
        no_of_lines_start_up++;
    } else if (isLowerCase(ch)) {
      no_of_low++; word_started = true;
    } else if (isDigit(ch)) {
      no_of_digits++;
    } else if (ch == '\n') {
      no_of_lines++;
      if (word_started)
        no_of_words++;
      word_started = false;
      if (isVowel( readNthByteFromCurrentPosition(input_file, -1) )) 
        no_of_words_end_vow++;
      else if (readNthByteFromCurrentPosition(input_file, -1) == '\n') 
        no_of_blanks++;
    } else if (ch == ' ') {
      if (word_started)
        no_of_words++;
      word_started = false;
      if (isVowel( readNthByteFromCurrentPosition(input_file, -1) )) 
        no_of_words_end_vow++;
    } else if (not isAlphaNum(ch)) {
      if (word_started)
        no_of_words++;
      word_started = false;
    }
    cout << "\n read char " << input_file.tellg() << " : " << ch;
  }
  input_file.clear();

  no_of_lines++;
  if (word_started)
    no_of_words++;
  word_started = false;
  if(isVowel(input_file.get())) {
    no_of_words_end_vow++;
  }
  
  cout << "\n\nNo . of  blanks = " << no_of_blanks;
  cout << "\nNo . of  lines = " << no_of_lines;
  cout << "\nNo . of  UPPERCASE letters = " << no_of_up;
  cout << "\nNo . of  lowercase letters = " << no_of_low;
  cout << "\nNo . of  lines starting with a Capital letter = " << no_of_lines_start_up;
  cout << "\nNo . of  words = " << no_of_words;
  cout << "\nNo . of  digits = " << no_of_digits;
  cout << "\nNo . of  words ending with a vowel = " << no_of_words_end_vow;
  
  input_file.close();
  
  while (cin.get() != '\n');
  cin.get();
  
  return 0;
}
