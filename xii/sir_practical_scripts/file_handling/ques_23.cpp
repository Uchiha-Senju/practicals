#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream input_file;
  char file_name[100], substring[100];
  bool present = false;
  
  cout << "Enter filename for input : "; cin.getline(file_name, 100);
  input_file.open(file_name, ios::in);
  if (not input_file.is_open()) {
    cerr << "ValueError : No such file as '" << file_name << "'\n";
    return 1;
  }
  input_file.seekg(0, ios::beg);
  
  cout << "Enter string to search : "; cin.getline(substring, 100);
  
  while (not input_file.eof() and not present) {
    char first_char;
    input_file.read(&first_char, 1);
    
    if (first_char == substring[0]) {
      present = true;
      for (int i = 1; substring[i] != '\0' and present; ++i) {
        input_file.read(&first_char, 1);
        present &= substring[i] == first_char; 
      }
    }
  }
  
  if (present)
    cout << "Given substring '" << substring << "' is present in '" << file_name << "'\n";
  else 
    cout << "Given substring '" << substring << "' is not present in '" << file_name << "'\n";
  
  while (cin.get() != '\n')
  cin.get();
  
  return 0;
}
