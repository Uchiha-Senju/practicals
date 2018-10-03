/*####################################################
##    
##    To 'snail' a given 2D matrix e.g.
##    Matirx : [ 1, 2, 3, 4,5]
##             [16,17,18,19,6]
##             [15,24,25,20,7]
##             [14,23,22,21,8]
##             [13,12,11,10,9]
##    Snail output : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
##    
##    By Varad Mahashabde
##    Copyright 2018
##    
##    Time taken : 15-25 minutes
##    
####################################################*/

#include <iostream>
using namespace std;

struct Complex {
    int re;
    int im;
};

int main () {
    int r, c;
    cout << "Enter of rows amd columns : "; cin >> r >> c; // Get parameters for matrix
    char mtr[r][c];
    bool mtr_alt[r][c];
    for (int k = 0; k < r*c; ++k) mtr_alt[k/r][k%c] = false;
    for (int i = 0; i < r; ++i) for (int k = 0; k < c; ++k) {
        cout << "Enter matrix element row " << i + 1 << " no. " << k + 1 << " : "; cin >> mtr[i][k]; // Get elements of matrix row-wise
    }
    
    cout << "Snail trail : ";
    Complex direction = {0,1}, n = {0,0};
    for (int i = 0; i < r*c; ++i) {
        cout << mtr[n.re][n.im] << ' ';
        mtr_alt[n.re][n.im] = true;        
        if (mtr_alt[n.re + direction.re][n.im + direction.im] == true || n.im + direction.im >= c || n.re + direction.re >= r) { // Check if next element done or out of bounds 
            direction = {-(direction.im * -1), direction.re * -1}; // Multiply by -i
        }
        n = {n.re + direction.re, n.im + direction.im};
    }
    getchar();
}
