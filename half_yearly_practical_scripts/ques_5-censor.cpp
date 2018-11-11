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
#include <cstring>
using namespace std;

int main () {
    int no_cuss_words;
    char ch;
    cin >> no_cuss_words;
    string cuss_words[no_cuss_words];
    for (int i = 0; i < no_cuss_words; ++i) cuss_words[i] = gets(&(cuss_words[i][0]));
    // while (getchar() != '\n');
    // for (int i = 0; i < no_cuss_words; ++i) {
        // do ch = getchar();
        // while (ch != ' ' || ch != '\n' || ch != '\0');
    // }
    // cout << endl;
    // for (string word : cuss_words) cout << word << endl;
    string para; para = gets(&para[0]);
    cout << para << endl;
    for (int i = 0; i < no_cuss_words; ++i) cout << cuss_words[i] << endl;
    {while (getchar() != '\n');
    getchar();}
}
