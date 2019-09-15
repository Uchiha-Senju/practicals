#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

struct Employee {
  int EmpNo;
  char Name[20];
  float Salary;
  void display(ostream& out_strm) {
    cout << "\nEmployee " << EmpNo << " : ";
    cout << "\n\tName : " << Name;
    cout << "\n\tSalary : " << Salary;
  }
  void getData(istream& in_strm, ostream& out_strm) {
    out_strm << "\nEnter Employee Details :";
    out_strm << "\n\tEmployee no. : "; in_strm >> EmpNo;
    in_strm.ignore(std::numeric_limits<streamsize>::max(), '\n');
    out_strm << "\n\tName : "; in_strm.getline(Name, 20);
    out_strm << "\n\tSalary : "; in_strm >> Salary;
  }
};

int main() {
  int n;
  char file_path[100];
  Employee emp;
  cout << "Enter file path : "; cin.getline(file_path, 100);
  ofstream out(file_path, ios::out | ios::binary);
  if (not (out.is_open() and out.good())) {
    cerr << "FileError : cannot open file \"" << file_path << "\"";
    return 1;
  }
  cout << "No. of employees? "; cin >> n;
  for (int i = 0; i < n; ++i) {
    emp.getData(cin, cout);
    out.write( (char*)&emp, sizeof(Employee));
  }
}