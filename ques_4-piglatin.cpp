/*####################################################
##    
##    To print Piglatin text from given text
##    Rules:
##    Break word at first vowel, move the front end
##    end to last, and add ay
##    If first letter vowel, add hay at end e.g.
##    THIS IS SPARTA IN THE IRON AGE
##    ISTHAY ISHAY ARTASPAY INHAY ETHAY IRONHAY AGEHAY
##    
##    By Varad Mahashabde
##    copyright 2018
##    
##    Time taken : 1 hour 15 minutes
##    
####################################################*/

#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main () {
    string k; k = gets(&k[0]);
    int no_of_consonants = 0;
    bool saw_vowel = false, vowel_first = false;
    string c = "";
    for (int i = 0; i < strlen(&k[0]); ++i) {
        if (!vowel_first && isVowel(k[i]) && (!i || k[i-1] == ' ')) { // check for vowel at start of word
            vowel_first = true; saw_vowel= true;
            cout << k[i];
        }
        else if (!saw_vowel && isVowel(k[i]) && k[i-1] != ' ') { //check for vowels within word
            saw_vowel = true;
            cout << k[i];
        }
        // else if (isVowel(k[i]) && saw_vowel) cout << k[i];
        else if (k[i] == ' ' || k[i] == '.' || i == strlen(&k[0]) - 1) {
            if (i + 1 == strlen(&k[0])) cout << k[i];
            cout << c;                                          //Print all consonants before vowel and print ay/hay
            if (vowel_first) cout << "hay";
            else cout << "ay";
            if (i + 1 != strlen(&k[0])) cout << k[i];
            if (k[i] == '.') cout << k[++i]; //If ., then print next also, sinc it is ' ''
            saw_vowel = false; vowel_first = false; no_of_consonants = 0; c = "";
        }
        else if (saw_vowel /* && ! isVowel(k[i]) */) cout << k[i]; //Print consonants after vowel
        else if (!saw_vowel && !isVowel(k[i])) c += k[i]; //Don't print but remember consonants before vowel
    }
    getchar();
}
