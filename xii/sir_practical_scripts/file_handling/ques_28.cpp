#include <fstream>
#include <iostream>
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
};

int main() {
  ifstream in_1("comp1.dat", ios::in | ios::binary), in_2("comp2.dat", ios::in | ios::binary);
  ofstream out("newcomp.dat", ios::out | ios::binary | ios::trunc);
  int n_1 = 0, n_2 = 0;
  Employee emp1, emp2;
  if (not (in_1.good() and in_1.is_open())) {
    cerr << "FileError : cannot open file stream \"comp1.dat\"";
    return 1;
  }
  if ( not (in_2.good() and in_2.is_open())) {
    cerr << "FileError : cannot open file stream \"comp2.dat\"";
    return 1;
  }
  
  cout << "\n\nContents of \"comp1.dat\" : ";
  while( in_1.read((char*)&emp1, sizeof(Employee))) {
    emp1.display(cout);
    n_1++;
  }
  
  cout << "\n\nContents of \"comp2.dat\" : ";
  while( in_2.read((char*)&emp2, sizeof(Employee))) {
    emp2.display(cout);
    n_2++;
  }
  
  out.seekp(0, ios::beg);
  cout << "\n\nContents of \"newcomp.dat\" : ";  
  int i,j;
  in_1.clear(); in_2.clear();
  in_1.seekg(0, ios::beg); in_2.seekg(0, ios::beg);
  in_1.read((char*)&emp1, sizeof(Employee));
  in_2.read((char*)&emp2, sizeof(Employee));
  for ( i = 0, j = 0; i < n_1 and j < n_2;) {
    if (emp1.EmpNo < emp2.EmpNo) {
      out.write((char*)&emp1, sizeof(Employee));
      emp1.display(cout);
      in_1.read((char*)&emp1, sizeof(Employee));
      i++;
    } else {
      out.write((char*)&emp2, sizeof(Employee));
      emp2.display(cout);
      in_2.read((char*)&emp2, sizeof(Employee));
      j++;
    }
  }
  if (i == n_1) {
    for (; j < n_2; j++) {
      out.write((char*)&emp2, sizeof(Employee));
      emp2.display(cout);
      in_2.read((char*)&emp2, sizeof(Employee));
    }
  } else {
    for (; i < n_1; i++) {
      out.write((char*)&emp1, sizeof(Employee));
      emp1.display(cout);
      in_1.read((char*)&emp1, sizeof(Employee));
    }
  }
  
  cout <<"\n\n";
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
  cin.get();
}
