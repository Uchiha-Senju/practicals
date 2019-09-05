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

int main() {
  char file_name[51];
  ifstream input_file;
  
  cout << "Enter file name (max 50 char) : "; cin.getline(file_name, 51, '\n');
  input_file.open(file_name, ios::in);
  if (not input_file.is_open()) {
    cout << "ERR : File does not exist\n";
    return 0;
  }
  
  input_file.seekg(0, ios::beg);
  long long file_length = -input_file.tellg();
  input_file.seekg(0, ios::end);
  file_length += input_file.tellg();
  input_file.seekg(0, ios::beg);  
  
  char ch, prev_ch;
  int no_of_blanks = 0, no_of_lines = 0, no_of_up = 0, no_of_low = 0, no_of_lines_start_up = 0, no_of_words = 0, no_of_digits = 0, no_of_words_end_vow = 0;
  bool word_started = false;

  //For first character
  input_file.get(ch);
  input_file.seekg(1, ios::beg);
  if (isUpperCase(ch)) {
    no_of_up++; word_started = true;
    no_of_lines_start_up++;
  } else if (isLowerCase(ch)) {
    no_of_low++; word_started = true;
  } else if (isDigit(ch)) {
    no_of_digits++;
  } else if (ch == '\n' or ch == '\r') {
    no_of_lines++;
    no_of_blanks++;
  }
  
  while (not input_file.eof()) {
    prev_ch = ch;
    input_file.read(&ch, 1);
    
    if (isUpperCase(ch)) {
      no_of_up++; word_started = true;
      if (prev_ch == '\n' or prev_ch == '\r') 
        no_of_lines_start_up++;
    } else if (isLowerCase(ch)) {
      no_of_low++; word_started = true;
    } else if (isDigit(ch)) {
      no_of_digits++;
    } else if (ch == '\n' or ch == '\r') {
      no_of_lines++;
      if (word_started)
        no_of_words++;
      word_started = false;
      if (isVowel( prev_ch )) 
        no_of_words_end_vow++;
      else if (prev_ch == '\n' or prev_ch == '\r') 
        no_of_blanks++;
    } else if (ch == ' ') {
      if (word_started)
        no_of_words++;
      word_started = false;
      if (isVowel( prev_ch )) 
        no_of_words_end_vow++;
    } else if (not isAlphaNum(ch)) {
      if (word_started)
        no_of_words++;
      word_started = false;
    }
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
