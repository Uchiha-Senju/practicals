#include <iostream>
#include <fstream>
#include <string.h>
#include <limits>
using namespace std;

struct TeleRec {
  char name[21];
  char tele_no[11];
  
  void display(ostream& out_strm) {
    out_strm << "\n\tName : " << name;
    out_strm << "\n\tTele no. : " << tele_no;
  }
  void getData(istream& in_strm, ostream& out_strm) {
    out_strm << "\n\tName : "; in_strm.getline(name, 21);
    out_strm << "\tTele no. : "; in_strm.getline(tele_no, 11);
  }
};

int main() {
  char choice;
  bool found;
  char person_name[21], phone_no[11];
  TeleRec record;
  fstream record_file;
  
  record_file.open("tele_records.dat", ios::in | ios::out | ios::app | ios::binary);
  if (not (record_file.is_open() and record_file.good())) {
    record_file.close();
    record_file.open("tele_records.dat", ios::out);
      record_file.close();
    record_file.open("tele_records.dat", ios::in | ios::out | ios::app | ios::binary);
    if (not (record_file.is_open() and record_file.good())) {
      cerr << "FileError : cannot open file stream \"tele_records.dat\"";
      return 1;
    }
  }
  
  for (int i = 1; record_file.read((char*)(&record), sizeof(TeleRec)); ++i) {
    cout << "\nRecord " << i << " : ";
    record.display(cout);
  }
  
  do {
    cout << "\n\nPick an option : ";
    cout << "\n\t1 - Append records"
         << "\n\t2 - Search by Telephone number"
         << "\n\t3 - Search by Name"
         << "\n\t4 - Exit\n";
    cin >> choice;
    switch (choice) {
      case '1' :
        int n;
        cout << "No. of records to append? "; cin >> n;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        
        record_file.clear(); record_file.seekp(0, ios::end);
        for (int i = 0; i < n; ++i) {
          cout << "\nEnter Record Details : ";
          record.getData(cin, cout);
          record_file.write((char*)(&record), sizeof(TeleRec));
        }
        break;
        
      case '2' :
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter Telephone no. : "; cin.getline(phone_no, 11);
        found = false;
        
        record_file.clear(); record_file.seekg(0, ios::beg);
        for (int i = 1; record_file.read((char*)(&record), sizeof(TeleRec)) and not found; ++i) {
          if (strcmp(phone_no, record.tele_no) == 0) {
            found = true;
            cout << "\nRecord " << i << " : ";
            record.display(cout);
          }
        }
        if (not found) {
          cout << "\nRecord not found\n";
        }
        break;
        
      case '3' :
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter Name : "; cin.getline(person_name, 21);
        found = false;
        
        record_file.clear(); record_file.seekg(0, ios::beg);
        for (int i = 1; record_file.read((char*)(&record), sizeof(TeleRec)); ++i) {
          if (strcmp(person_name, record.name) == 0) {
            found = true;
            cout << "\nRecord " << i << " : ";
            record.display(cout);
          }
        }
        if (not found) {
          cout << "\nRecord not found\n";
        }
        break;
      
      case '4' :
        break;
      
      default : 
        cout << "Invalid input. Try again\n";
        break;
    }
  } while (choice != '4');
  
  record_file.close();
}
