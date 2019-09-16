#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream input_file, temp_file;
  char file_name[100];
  char old_ch, new_ch;
  
  cout << "Enter input filename : "; cin.getline(file_name, 100);
  input_file.open(file_name, ios::in);
  temp_file.open(".temp.txt", ios::out);
  if (not input_file.is_open()) {
    cerr << "ValueError : Invalid filename given";
    return 1;
  }
  input_file.seekg(0, ios::beg);
  temp_file.seekp(0, ios::beg);
  
  cout << "Enter the two characters to find and replace : ";
  cin >> old_ch >> new_ch;
  
  while (not input_file.eof()) {
    char ch;
    input_file.read(&ch, 1);
    
    if (ch == old_ch) 
      temp_file.write(&new_ch, 1);
    else 
      temp_file.write(&ch, 1);
  }
  input_file.close(); input_file.open(file_name, ios::out);
  temp_file.close(); temp_file.open(".temp.txt", ios::in);
  input_file.seekp(0, ios::beg);
  temp_file.seekg(0, ios::beg);
  
  while (not temp_file.eof()) {
    char ch;
    temp_file.read(&ch, 1);
    input_file.write(&ch, 1);
  }
  
  cout << "Done";
  
  while( cin.get() != '\n');
  cin.get();
}
