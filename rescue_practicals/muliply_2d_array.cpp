#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int r, c;
    do { cout << "Enter rows and columns : "; cin >> r >> c; }while ( r <= 0 || c <= 0);
    int karr[r][c], larr[r][c];
    
    cout << "Enter array 1 : \n";
    for (int i = 0; i < r; ++i) {
        cout << '\t';
        for (int j = 0; j < c; ++j)
            cin >> karr[i][j];
    }
    
    cout << "Enter array 2 : \n";
    for (int i = 0; i < r; ++i) {
        cout << '\t';
        for (int j = 0; j < c; ++j)
            cin >> larr[i][j];
    }
    
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            karr[i][j] *= larr[i][j];
    
    cout << "\nMultiplied matrix : ";
    for (int i = 0; i < r; ++i) {
        cout << "\n\t";
        for (int j = 0; j < c; ++j)
            cout << setw(8) << karr[i][j] << " ";
    }
    cout << "\n\n";
    
    while (getchar() != '\n');
    getchar();
}
