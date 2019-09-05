#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    unsigned int lines, choice;
    cout << "Enter no. of lines : "; cin >> lines;
    do {
        cout << "Enter type of pyramid :\nGUIDE :\nNumber Pyramid - 0\nUpside-down Isosceles Pyramid - 1\nHollow Diamond - 2\nBottom-filled Diamond - 3\n\tChoice? ";
        cin >> choice;
        if (choice >= 4)
            cout << "ERR : INPUT OUT OF BOUNDS(0-3)\n";
    } while (choice >= 4);

    switch (choice) {
        case 0:
            for (int i = 0; i < lines; ++i) {
                for (int j = lines - i; j > 0; --j)
                    cout << ' ';
                for (int j = 1; j < i + 2; ++j)
                    cout << j;
                for (int j = i; j > 0; --j)
                    cout << j;
                cout << '\n';
            }
            break;
        case 1:
            for (int i = lines; i > 0; --i) {
                for (int j = lines - i + 1; j > 0; --j)
                    cout << ' ';
                for (int j = 2 * i - 1; j > 0; --j)
                    cout << '*';
                cout << '\n';
            }
            break;
        case 2:
            for (int i = 0; i < lines/2; ++i) {
                for (int j =(lines + 2)/2 - i; j > 0; --j)
                    cout << ' ';
                cout << '*';
                for (int j = 2*i - 1; j > 0; j--)
                    cout << ' ';
                if (i) cout << '*';
                cout << '\n';
            }
            for (int i = lines/2; i >= 0; --i) {
                for (int j =(lines + 2)/2 - i; j > 0; --j)
                    cout << ' ';
                cout << '*';
                for (int j = 2*i - 1; j > 0; j--)
                    cout << ' ';
                if (i) cout << '*';
                cout << '\n';
            }
            break;
        case 3:
            for (int i = 0; i < lines/2; ++i) {
                for (int j =(lines + 2)/2 - i; j > 0; --j)
                    cout << ' ';
                cout << '*';
                for (int j = 2*i - 1; j > 0; j--)
                    cout << ' ';
                if (i) cout << '*';
                cout << '\n';
            }
            for (int i = lines/2; i >= 0; --i) {
                for (int j =(lines + 2)/2 - i; j > 0; --j)
                    cout << ' ';
                for (int j = 2*i + 1; j > 0; --j)
                    cout << '*';
                cout << '\n';
            }
            break;
    }

    while (getchar() != '\n');
    getchar();
}
