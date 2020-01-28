#include <iostream>
#include <fstream>
#include "../classes.h"

int main() {
  int n;
  char file_path[100];
  Student stu;
  std::cout << "Enter file path : "; std::cin.getline(file_path, 100);
  std::ofstream out(file_path, std::ios::out | std::ios::binary | std::ios::trunc);
  if (not (out.is_open() and out.good())) {
    std::cerr << "FileError : cannot open file \"" << file_path << "\"";
    return 1;
  }
  std::cout << "No. of students? "; std::cin >> n;
  for (int i = 0; i < n; ++i) {
    stu.getData(std::cin, std::cout);
    out.write( (char*)&stu, sizeof(Student));
  }
}