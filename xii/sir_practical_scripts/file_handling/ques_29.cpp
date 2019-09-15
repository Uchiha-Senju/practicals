#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string.h>
#include <stdio.h>
#include "cls.h"
using namespace std;

void strxor(char* str_1, unsigned int size_1, char* str_2, unsigned int size_2) {
  for (int i = 0; i < size_1;) 
    for (int j = 0; i < size_1 and j < size_2; j++ and i++) {
      str_1[i] ^= str_2[j];
    }
}

class Book{
  public:
    int BookNo;
    char Book_name[20];
    // function to enter book details
    void enterdetails() {
      cout << "\n\tBook no. : "; cin >> BookNo;
      cout << "\n\tBook name : "; 
      cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
      cin.getline(Book_name, 20);
    }
    //function to display Book details
    void showdetails() {
      cout << "\n\tBook no. : " << BookNo;
      cout << "\n\tBook Name : " << Book_name;
    }
    //function to return Book_no
    int Rbook_no() {return BookNo;}
    //function to return Book_name
    char* Rbook_name() {return Book_name;}
    // encrypt/decrypt
    void crypt(char* password, unsigned int size) {
      strxor((char*)this, sizeof(Book), password, size);
    }
};

class Library {
  fstream shelf;
  char file_path[100];
  char password[11];
  
  public :
    Book cur_book;
    
    Library() : shelf() {}
    Library(char file_path[]) : shelf(file_path, ios::in | ios::out | ios::binary) {
      strcpy(this->file_path, file_path);
      if (not shelf.is_open()) {
        shelf.close();
        shelf.open(file_path, ios::out);
        shelf.close();
        shelf.open(file_path, ios::in | ios::out | ios::binary);
        if (not shelf.is_open()) {
          cerr << "\n\nFileError : cannot open file stream\n\n";
        }
      }
      shelf.seekp(0, ios::beg); shelf.seekg(0, ios::beg);
    }
    ~Library() {
      for (int i = 0; i < 11; ++i)
        password[i] = '\0';
      shelf.close();
    }
    void setPassword(char* passwd) {
      for (int i = 0; i < 10; ++i)
        password[i] = passwd[i];
      password[10] = '\0';
    }
    int size() {
      if (shelf.is_open() and shelf.good()) {
        int temp = shelf.tellp();
        shelf.seekp(0, ios::beg);
        int length = -shelf.tellp();
        shelf.seekp(0, ios::end);
        length += shelf.tellp();
        shelf.seekp(temp);
        return length/sizeof(Book);
      } else
        return -1;
    }
    
    bool loadBook(unsigned int index) {
      if (index >= size() or not (shelf.is_open() and shelf.good()))
        return false;
      shelf.seekp(index * sizeof(Book), ios::beg);
      if( not shelf.read((char*)&cur_book, sizeof(Book)) )
        return false;
      cur_book.crypt(password, 10);
      return true;
    }
    bool loadNextBook() {
      if (not (shelf.is_open() and shelf.good()))
        return false;
      if( not shelf.read((char*)&cur_book, sizeof(Book)) )
        return false;
      cur_book.crypt(password, 10);
      return true;
    }
    bool pushBook(unsigned int index) {
      if (index >= size() or not (shelf.is_open() and shelf.good()))
        return false;
      shelf.seekg(index * sizeof(Book), ios::beg);
      cur_book.crypt(password, 10);
      if( not shelf.write((char*)&cur_book, sizeof(Book)) )
        return false;
      cur_book.crypt(password, 10);
      return true;
    }
    bool pushNextBook() {
      if (not (shelf.is_open() and shelf.good()))
        return false;
      cur_book.crypt(password, 10);
      if( not shelf.write((char*)&cur_book, sizeof(Book)) )
        return false;
      cur_book.crypt(password, 10);
      return true;
    }
    bool removeBook(unsigned int index) {
      if (index > size() or not (shelf.is_open() and shelf.good()))
        return false;
      int siz = size();
      ofstream temp(".tempbinarydatafile", ios::in | ios::binary | ios::trunc);
      char* buf = new char[sizeof(Book)];
      if (buf == nullptr)
        return false;
      shelf.seekg(0, ios::beg);
      temp.seekp(0, ios::beg);
      // Create temp file without the given index
      for (int i = 0; i < index; ++i) {
        shelf.read(buf, sizeof(Book));
        temp.write(buf, sizeof(Book));
      }
      shelf.seekg(sizeof(Book), ios::cur);
      for (int i = index + 1; i < siz; ++i) {
        shelf.read(buf, sizeof(Book));
        temp.write(buf, sizeof(Book));
      }
      // Rename temp to shelf
      shelf.close();
      temp.close();
      remove(file_path);
      rename(".tempbinarydatafile", file_path);
      remove(".tempbinarydatafile");
      // Reopen shelf
      shelf.open(file_path, ios::in | ios::out | ios::binary);
      if (not shelf.is_open()) {
        shelf.close();
        shelf.open(file_path, ios::out);
        shelf.close();
        shelf.open(file_path, ios::in | ios::out | ios::binary);
        if (not shelf.is_open()) {
          cerr << "\n\nFileError : cannot open file stream\n\n";
          return false;
        }
      }
      return true;
    }
    void display(ostream& out_strm) {
      int siz = size();
      shelf.seekg(0, ios::beg);
      out_strm << "\tIndex  Book no.  Book Name\n";
      out_strm << "\t=====  ========  ====================\n";
      for (int i = 0; i < siz; i++) {
        loadNextBook();
        out_strm << '\t' << setw(5) << i << setw(10) << cur_book.BookNo << setw(22) << cur_book.Book_name << '\n';
      }
    }
    void sortByName() {
      struct smallBook_n{
        int index;
        char book_name[20];
        void quickSort_n(smallBook_n* arr, unsigned int start, unsigned int end) {
          if (start + 1 >= end)
            return;
          int pivotIndex = start;
          smallBook_n temp;
          for (int i = start ; i < end - 1 ; ++i) {
            if (strcmp(arr[i].book_name, arr[end].book_name)  <= 0) {
              temp = arr[i];
              arr[i] = arr[pivotIndex];
              arr[pivotIndex] = temp;
              pivotIndex++;
            }
          }
          temp  = arr[end];
          arr[end] = arr[pivotIndex];
          arr[pivotIndex] = temp;
          quickSort_n(arr, start, pivotIndex);
          quickSort_n(arr, pivotIndex + 1, end);
        }
      } dummy;
      cout << "here";
      int siz = size();
      // Create a lighter representative array
      smallBook_n* books = new smallBook_n[siz];
      for (int i = 0; i < siz; ++i) {
        loadBook(i);
        books[i].index = i;
        strcpy(books[i].book_name, cur_book.Book_name);
      }
      // Sort the lighter array
      cout << "sorting";
      dummy.quickSort_n(books, 0, siz);
      // shuffle according to the sorted positions
      cout << "start moving";
      shelf.clear();
      for (int i = 0; i < siz; ++i) {
        Book temp1, temp2;
        // swap the books
        loadBook(books[i].index);
        temp1 = cur_book;
        loadBook(i);
        temp2 = cur_book;
        cur_book = temp1;
        pushBook(i);
        loadBook(books[i].index);
        cur_book = temp2;
        pushBook(books[i].index);
        // swap the indices on the lighter array
        int j;
        for (j = i + 1; j < siz and books[j].index != i; j++);
        books[j].index = books[i].index;
        books[i].index = i;
      }
    }
    void sortByNumber() {
      struct smallBook_n{
        int index;
        int book_number;
        void quickSort_n(smallBook_n* arr, unsigned int start, unsigned int end) {
          if (start + 1 >= end)
            return;
          int pivotIndex = start;
          smallBook_n temp;
          for (int i = start ; i < end - 1 ; ++i) {
            if (arr[i].book_number < arr[end].book_number) {
              temp = arr[i];
              arr[i] = arr[pivotIndex];
              arr[pivotIndex] = temp;
              pivotIndex++;
            }
          }
          temp  = arr[end];
          arr[end] = arr[pivotIndex];
          arr[pivotIndex] = temp;
          quickSort_n(arr, start, pivotIndex);
          quickSort_n(arr, pivotIndex + 1, end);
        }
      } dummy;
      int siz = size();
      // Create a lighter representative array
      smallBook_n* books = new smallBook_n[siz];
      for (int i = 0; i < siz; ++i) {
        loadBook(i);
        books[i].index = i;
        books[i].book_number = cur_book.BookNo;
      }
      for (int i = 0; i < siz; ++i)
        cout << i << " - " << books[i].index << " : ";
      cout << '\n';
      // Sort the lighter array
      dummy.quickSort_n(books, 0, siz);
      for (int i = 0; i < siz; ++i)
        cout << i << " - " << books[i].index << " : ";
      cout << '\n';
      // shuffle according to the sorted positions
      shelf.clear();
      for (int i = 0; i < siz; ++i) {
        Book temp1, temp2;
        // swap the books
        loadBook(books[i].index);
        temp1 = cur_book;
        loadBook(i);
        temp2 = cur_book;
        cur_book = temp1;
        pushBook(i);
        loadBook(books[i].index);
        cur_book = temp2;
        pushBook(books[i].index);
        // swap the indices on the lighter array
        int j;
        for (j = i + 1; j < siz and books[j].index != i; j++);
        books[j].index = books[i].index;
        books[i].index = i;
      }
    }
    bool appendBook() {
      if (not (shelf.is_open() and shelf.good()))
        return false;
      shelf.seekg(0, ios::end);
      cur_book.crypt(password, 10);
      if( not shelf.write((char*)&cur_book, sizeof(Book)) )
        return false;
      cur_book.crypt(password, 10);
      return true;
    }
    int findByNumber(int book_number) {
      int siz = size();
      shelf.clear();
      shelf.seekg(0, ios::beg);
      for (int i = 0; i < siz; i++) {
        if( not shelf.read((char*)&cur_book, sizeof(Book)) )
          return -1;
        cur_book.crypt(password, 10);
        if (cur_book.BookNo == book_number)
          return i;
      }
      return -1;
    }
    int findByName(char* book_name) {
      int siz = size();
      shelf.clear();
      shelf.seekg(0, ios::beg);
      for (int i = 0; i < siz; i++) {
        if( not shelf.read((char*)&cur_book, sizeof(Book)) )
          return -1;
        cur_book.crypt(password, 10);
        if (strcmp(cur_book.Book_name, book_name) == 0)
          return i;
      }
      return -1;
    }
    
};

int main() {
  int number;
  char str[20];
  int choice;
  Library lib("book.dat");
  
  cout << "Enter password : "; cin.getline(str, 11);
  ClearScreen();
  lib.setPassword(str);
  
  do {
    cout << "\n\nPick an option : ";
    cout << "\n\t1 - Append records"
         << "\n\t2 - Modify by Book Number"
         << "\n\t3 - Search by Book Name"
         << "\n\t4 - Delete record"
         << "\n\t5 - Display records"
         << "\n\t6 - Sort by Book Name"
         << "\n\t7 - Sort by Book Number"
         << "\n\t8 - Exit\n";
    cin >> choice;
    ClearScreen();
    switch (choice) {
      case 1 :
        cout << "Enter book details : "; 
        lib.cur_book.enterdetails();
        lib.appendBook();
        break;
      case 2 :
        cout << "\nEnter Book Number : "; cin >> number;
        number = lib.findByNumber(number);
        if (number >= 0) {
          cout << "\nIndex " << number << " : ";
          lib.cur_book.showdetails();
          lib.cur_book.enterdetails();
          lib.pushBook(number);
        } else
          cout << "\nNot found";
        break;
      case 3 :
        cout << "\nEnter Book Name : ";
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cin.getline(str, 20);
        number = lib.findByName(str);
        if (number >= 0) {
          cout << "\nIndex " << number << " : ";
          lib.cur_book.showdetails();
        }
        else
          cout << "\nNot found";
        break;
      case 4 :
        cout << "\nEnter index of book : "; cin >> number;
        if (not lib.removeBook(number)) 
          cout << "\nCouldn't remove book";
        else
          cout << "\nBook removed";
        break;
      case 5 :
        lib.display(cout);
        break;
      case 6 :
        lib.sortByName();
        break;
      case 7 :
        lib.sortByNumber();
        break;
      case 8 :
        cout << "\nBYE!!\n";
        break;
      default :
        cout << "\nInvalid option";
        break;
    }
  } while (choice != 8);
  lib.~Library();
  
}
