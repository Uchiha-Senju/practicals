#include <iostream>
#include "array.cpp"
using namespace std;

int main() {
  int n1, n2;
  cout << "Max size of arr? "; cin >> n1;
  Array arr(n1);
  
  char choice;
  do {
    cout << "\nEnter your choice :"
         << "\n\t1 - Display array"
         << "\n\t2 - Insert element"
         << "\n\t3 - Remove element"
         << "\n\t4 - Linear Search"
         << "\n\t5 - Binary Search"
         << "\n\t6 - Exit\n";
    cin >> choice;
    switch(choice) {
      case '1' :
        cout << "\nArray : ";
        arr.display(cout);
        cout << '\n';
        break;
      case '2' :
        cout << "\nEnter the index for insertion : "; cin >> n1;
        cout << "Enter value : "; cin >> n2;
        if (not arr.insert(n2, n1))
          cerr << "\nValueError : invalid value provided for function \'bool Array::insert(int,int)\'\n";
        break;
      case '3' :
        cout << "\nEnter the index for insertion : "; cin >> n1;
        if (not arr.remove(n1))
          cerr << "\nValueError : invalid value provided for function \'bool Array::remove(int)\'\n";
        break;
      case '4' :
        cout << "\nEnter the value to be searched : "; cin >> n1;
        n2 = arr.linearSearch(n1);
        if (n2 == -1) 
          cout << "Value not found\n";
        else 
          cout << "Value found at index " << n2 << '\n';
        break;
      case '5' :
        cout << "\nEnter the value to be searched : "; cin >> n1;
        n2 = arr.binarySearch(n1);
        if (n2 == -1) 
          cout << "Value not found\n";
        else 
          cout << "Value found at index " << n2 << '\n';
        break;
      case '6' :
        cout << "\nBye!!\n\n";
        break;
      default :
        cout << "\nInvalid option, try again\n";
    }
  } while (choice != '6');
}
