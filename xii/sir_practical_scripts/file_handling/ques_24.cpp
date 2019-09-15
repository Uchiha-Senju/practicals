#include <iostream>
#include <fstream>
using namespace std;

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
  ifstream input_file;
  ofstream output_file("copy.txt", ios::out);
  char file_name[100], word[100];
  
  cout << "Enter filename for input : "; cin.getline(file_name, 100);
  input_file.open(file_name, ios::in);
  if (not input_file.is_open()) {
    cerr << "ValueError : No such file as '" << file_name << "'\n";
    return 1;
  }
  input_file.seekg(0, ios::beg);
  while (not input_file.eof() ) {
    input_file >> word;
    int i;
    for (i = 0; word[i] != '\0'; ++i);
    if (not isVowel(word[i - 1]))
      output_file << word << ' ';
  }
  
  cout << "Done\n";
  while (cin.get() != '\n');
  cin.get();
}