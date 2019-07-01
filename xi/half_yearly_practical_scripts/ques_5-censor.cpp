/*####################################################
##    
##    
##    
##    
##    
##    
##    
##    
##    
##    
##    Time till now : 10min
##    
####################################################*/

#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;

int findString(string* arr, int size, string s1) {
    for (int i = 0; i < size; ++i) 
        if (arr[i] == s1) 
            return i;
    return -1;
}

int main () {
    int no_censored_words, till_next_space, para_length = 0;
    char ch;
    cout << "Enter no. of banned words : ";cin >> no_censored_words;
    string censored_words[no_censored_words], para = "";
    cout << "Enter banned words : ";
    for (int i = 0; i < no_censored_words; ++i)
        cin >> censored_words[i];
    // Clear input buffer and get para text
    while(getchar() != '\n');
    do {
        ch = getchar();
        para += ch;
        para_length++;
    } while (ch != '\n');
    
    for (int i = 0; i < para_length;) {
        cout << para[i];
         for (till_next_space = 0;; ++till_next_space) 
            if ( !((para[(i + till_next_space)] != ' ') || (para[(i + till_next_space)] != '.')) ) {
                cout << till_next_space << endl;
                break;
            }
        cout << typeid(para[i+till_next_space]).name();
        if (findString(censored_words, no_censored_words, para.substr(i, till_next_space)) >= 0) {
            cout << para[i];
            for (int j = 0; j < till_next_space; j++, i++)
                cout << "*";
        }
        // else 
            // for (int j = 0; j < till_next_space; j++, i++)
                // cout << para[i];
        
    }
    
    // cout << endl << para << endl;
    // for (int i = 0; i < no_censored_words; ++i)
        // cout << "\n\t" << censored_words[i];
}
