/*#####################################
##  
##  To output an ASCII character given
##  the code and vice versa
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
using namespace std;

int main() {
    int ch;
    char choice;
    cout << "Ascii2Num (1) or Num2Ascii(2) ? "; cin >> choice;
    if (choice == '1') {
        cout << "Input ASCII character : "; cin >> choice;
        cout << "The corresponding ASCII code for \'" << choice << "\' is " << int(choice) << endl;
    } else if (choice == '2') {
        cout << "Input ASCII code : "; cin >> ch;
        cout << "The corresponding ASCII character for " << ch << " is \'" << char(ch) << '\'' << endl;
    } else return 1;
    while (getchar() != '\n');
    getchar();
    return 0;
}
