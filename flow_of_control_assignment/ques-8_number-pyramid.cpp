/*#####################################
##  
##  To print the following upto n
##  1
##  12
##  123
##  1234
##  12345
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Value of n? "; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=i; ++j) 
            cout << j;
        cout << endl;
    }
    while (getchar() != '\n');
    getchar();
}
