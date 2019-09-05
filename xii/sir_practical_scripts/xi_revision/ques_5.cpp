#include <iostream>
#include <stdio.h>
using namespace std;

bool isUpper (char ch) {
    return ch >='A' and ch <= 'Z';
}

bool isLower (char ch) {
    return ch >='a' and ch <= 'z';
}

int main() {
    char str[1000];
    cout << "Give your string :\n\t";
    // cin << flush;
    cin.getline(str, 1000, '\n');

    int upper, lower, non_alpha, words;
    upper = lower = non_alpha = words = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (isUpper(str[i]))
            upper++;
        else if (isLower(str[i]))
            lower++;
        else {
            if (str[i] == ' ') {
                words++;
                if (str[i + 1] == '.') {
                    i++; non_alpha++;
                }
            }
            non_alpha++;
        }
    }
    words++;

    cout << "\nNo. of CAPITAL LETTERS : " << upper << "\nNo. of lowercase letter : " << lower << "\nNo. of non-alphabets : " << non_alpha << "\nNo. of words : " << words << endl;

    getchar();
}
