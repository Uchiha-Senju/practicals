/*####################################################
##    
##    To create a pyramid of * given the number of
##    lines e.g. n = 3
##       *
##      ***
##     *****
##    or of similar character
##    
##    By Varad Mahashabde
##    Copyright 2018
##    
##    Time taken : 5 minutes
##    
####################################################*/

#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n, bb_in;
        char bb;
        cout << "Enter the number of lines : "; cin >> n; //Ask for no. of lines
        if ( n == 0) break;
        cout << "Enter ASCII code for block element (42 for *, 434 for " << char(434) << ", 475 for " << char(475) <<" , 510 for " << char(510)  << ", etc.): "; cin >> bb_in;    // Ask for building block
        bb = char(bb_in);
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n - i; ++k) cout << ' ';
            for (int k = 0; k < 2 * i + 1; ++k) cout << bb;
            cout << endl;
        }
        cout << "\n\n";
    }
    while (getchar() != '\n');
    getchar();
}
