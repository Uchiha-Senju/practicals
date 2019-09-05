#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


int getDigitSum(int x, int base) {
    int sum = 0;
    while (x > 0) {
        sum += x % base;
        x /= base;
    }
    return sum;
}

int main () {
    time_t k;
    srand( unsigned(time(&k)) );
    // cout << (unsigned int)(-1) << "\n\n";
    // for (int i = 0; i < 255; ++i)
    //     cout << rand() << endl;

    int guess, luckys[3];
    bool won = false;
    do {
        cout << "Enter your guess : "; cin >> guess;
        if (guess < 2 || guess > 19)
            cout << "ERR : INPUT OUT OF BOUNDS (2 - 19)\n";
    } while (guess < 2 || guess > 19);

    for (int i = 0; i < 3; ++i)
        luckys[i] = (199 - 101) * float(rand()) / 0x7fff + 101;
    cout << "The lucky numbers are : \n\t";
    for (int i = 0 ; i < 3; ++i) cout << setw(8) << luckys[i];

    for (int i = 0; i < 3; ++i) {
        luckys[i] = getDigitSum(luckys[i], 10);
        won |= luckys[i] == guess;
    }
    cout << "\nThe digit sums are : \n\t";
    for (int i = 0 ; i < 3; ++i) cout << setw(8) << luckys[i];

    if (won)
        cout << "\nYES YOU ARE THE WINNERRRRRR!!!!\nnow get out\n";
    else
        cout << "\nAye, your luck is like a wet squib.";

    while (getchar() != '\n');
    getchar();
}
