#include <iostream>
#include <fstream>
#include <string.h>
#include <limits>
using namespace std;

void pullUpper(char* str, unsigned int size) {
  for (int i = 0; i < size; ++i) {
    if (str[i] >= 'a' and str[i] <= 'z')
      str[i] -= 32;
  }
}

struct BloodDonor {
  char name[21];
  unsigned short dob_day;
  unsigned short dob_month;
  unsigned short dob_year;
  char tele_no[11];
  char group[4];
  
  void display(ostream& out_stream) {
    out_stream << "\n\tName : " << name;
    out_stream << "\n\tDate of Birth : " << dob_day << '-' << dob_month << '-' << dob_year;
    out_stream << "\n\tBlood Group : " << group;
    out_stream << "\n\tTele no. : " << tele_no;
  }
  
  void getData(istream& in_stream, ostream& out_stream) {
    out_stream << "\n\tName : "; in_stream.getline(name, 21);
    out_stream << "\tDate Of Birth (DD MM YYYY) : "; in_stream >> dob_day >> dob_month >> dob_year;
    in_stream.ignore(std::numeric_limits<streamsize>::max(), '\n');
    out_stream << "\tBlood Group : "; in_stream.getline(group, 4);
    out_stream << "\tTelephone no. : "; in_stream.getline(tele_no, 11);
    pullUpper(group, 4);
  }
};

int main() {
  char choice;
  bool found;
  char blood_group[4], phone_no[11];
  BloodDonor record;
  fstream record_file("blood_bank_records.dat", ios::in | ios::out | ios::ate | ios::binary);
  if (not record_file.is_open()) {
    record_file.close();
    // ios::in requires that the file exists, so here we create the file
    record_file.open("blood_bank_records.dat", ios::out);
    record_file.close();
    // Reopen file normally
    record_file.open("blood_bank_records.dat", ios::in | ios::out | ios::ate | ios::binary);
    // Something is wrong if this still doesn't work
    if (not record_file.is_open()) {
      cerr << "\n\nFileError : Unable to open file stream\n\n";
      return 1;
    }
  }
  
  record_file.seekg(0, ios::beg);
  for (int i = 1; record_file.read((char*)(&record), sizeof(BloodDonor)); ++i) {
    cout << "\nRecord " << i << " : ";
    record.display(cout);
  }
  
  do {
    cout << "\n\nPick an option : ";
    cout << "\n\t1 - Append records"
         << "\n\t2 - Modify by Telephone number"
         << "\n\t3 - Search by Blood group"
         << "\n\t4 - Exit\n";
    cin >> choice;
    switch (choice) {
      case '1' :
        int n;
        cout << "No. of records to append? "; cin >> n;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        
        // Clear EOF errors, if any, and go to the end
        record_file.clear(); record_file.seekp(0, ios::end);
        for (int i = 0; i < n; ++i) {
          cout << "\nEnter Record Details : ";
          record.getData(cin, cout);
          
          record_file.write((char*)(&record), sizeof(BloodDonor));
        }
        break;
        
      case '2' :
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter Telephone no. : "; cin.getline(phone_no, 11);
        found = false;
        
        // Clear EOF errors, if any, and go to the beginning
        record_file.clear(); record_file.seekg(0, ios::beg);
        for (int i = 1; record_file.read((char*)(&record), sizeof(BloodDonor)) and not found; ++i) {
          if (strcmp(phone_no, record.tele_no) == 0) {
            found = true;
            cout << "\nRecord " << i << " : ";
            record.display(cout);
            
            cout << "\n\nEnter modified data : ";
            record.getData(cin, cout);
            
            record_file.seekg(-sizeof(BloodDonor), ios::cur);
            record_file.seekp(record_file.tellg(), ios::beg);
            record_file.write((char*)(&record), sizeof(BloodDonor));
          }
        }
        if (not found) {
          cout << "\nRecord not found\n";
        }
        break;
        
      case '3' :
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter blood group : "; cin.getline(blood_group, 4);
        found = false;
        
        record_file.clear(); record_file.seekg(0, ios::beg);
        for (int i = 1; record_file.read((char*)(&record), sizeof(BloodDonor)); ++i) {
          if (strcmp(blood_group, record.group) == 0) {
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
        cerr << "Invalid input. Try again\n";
        break;
    }
  } while (choice != '4');
  
  record_file.close();
}
