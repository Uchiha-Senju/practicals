/*#####################################
##  
##  To compute the area or perimeter of
##  circle based on user choice
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
using namespace std;

int main() {
    char choice; double r;
    while (true) {
    cout << "Enter radius of circle : "; cin >> r;
    cout << "Area of circumference (a/c)? : "; cin choice
    if (choice == 'A' or choice == 'a') 
        cout << "Area of circle : " << 3.1415926 * r * r << endl;
    else 
        cout << "Circumference of circle : " << 6.2831852 * r << endl;
        // cout << "Continue (Y/N)? "; cin >> choice;
        // if (choice != 'y' and choice != 'Y') break;
    }
    while (getchar() != '\n');
    getchar();
}
