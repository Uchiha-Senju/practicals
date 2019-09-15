#include <iostream>
#include <fstream>
#include <string.h>
#include <limits>
using namespace std;

struct TeleRec {
  char name[21];
  char tele_no[11];
};

int main() {
  char choice;
  bool found;
  char person_name[21], phone_no[11];
  TeleRec record;
  fstream record_file;
  
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
        
        record_file.open("tele_records.dat", ios::out | ios::app | ios::binary);
        for (int i = 0; i < n; ++i) {
          cout << "\nEnter Record Details : ";
          cout << "\n\tName : "; cin.getline(record.name, 21);
          cout << "\tTele no. : "; cin.getline(record.tele_no, 11);
          record_file.write((char*)(&record), sizeof(TeleRec));
        }
        record_file.close();
        break;
        
      case '2' :
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter Telephone no. : "; cin.getline(phone_no, 11);
        found = false;
        
        record_file.open("tele_records.dat", ios::in | ios::binary);
        record_file.seekg(0, ios::beg);
        for (int i = 1; record_file.read((char*)(&record), sizeof(TeleRec)) and not found; ++i) {
          if (strcmp(phone_no, record.tele_no) == 0) {
            found = true;
            cout << "\nRecord " << i << " : ";
            cout << "\n\tName : " << record.name;
            cout << "\n\tTele no. : " << record.tele_no;
          }
        }
        if (not found) {
          cout << "\nRecord not found\n";
        }
        record_file.close();
        break;
        
      case '3' :
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter Name : "; cin.getline(person_name, 21);
        found = false;
        
        record_file.open("tele_records.dat", ios::in | ios::binary);
        record_file.seekg(0, ios::beg);
        for (int i = 1; record_file.read((char*)(&record), sizeof(TeleRec)); ++i) {
          if (strcmp(person_name, record.name) == 0) {
            found = true;
            cout << "\nRecord " << i << " : ";
            cout << "\n\tName : " << record.name;
            cout << "\n\tTele no. : " << record.tele_no;
          }
        }
        if (not found) {
          cout << "\nRecord not found\n";
        }
        record_file.close();
        break;
      
      case '4' :
        break;
      
      default : 
        cerr << "Invalid input. Try again\n";
        break;
    }
  } while (choice != '4');

}
