/*#####################################
##  
##  To count all the vowels, consonants 
##  , digits, special characters, words
##  and in given
##  
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
#include <string.h>
using namespace std;

bool isVowel(char let) {
    switch (let) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return true;
            break;
        default :
            return false;
            break;
    }
}

int main() {
    bool had_letter = false;
    int vowels, consonants, spaces, words, symbols, digits;
    vowels = consonants = spaces = words = symbols = 0;
    char ch;
    string text;
    cout << "Type text : ";
    while ((ch = getchar()) != '\n')
        text += ch;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            spaces++;
            had_letter ? words++ : 0;
            had_letter = false;
        } else if ((text[i] >= '!' and text[i] <= '/') or (text[i] >= ':' and text[i] <= '@') or (text[i] >= '[' and text[i] <='`') or (text[i] >= '{' and text[i] <=
        '~')) {
            symbols++;
            had_letter ? words++ : 0;
            had_letter = false;
        } else if (text[i] >= '0' && text[i] <= '9') 
            digits++;
        else if (isVowel(text[i])) 
            vowels++ == (had_letter = true);
        else if (!(isVowel(text[i]))) 
            consonants++ == (had_letter = true);
        if (i == text.size() - 1 and had_letter) words++;
    }
    cout << "\nWords " << words << "\nVowels " << vowels << "\nConsonants " << consonants << "\nSymbols " << symbols << "\nDigits " << digits << "\nSpaces " << spaces << endl;
    getchar();
}
