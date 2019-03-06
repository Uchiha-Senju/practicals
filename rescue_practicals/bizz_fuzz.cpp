#include <iostream>
using namespace std;

int main() {
    int n;
    do {cout << "Give max number : "; cin >> n;} while (n <= 0);
    for (int i = 1; i <= n; ++i) {
        if (i % 3 && i % 5)
            cout << i;
        else {
            if(!(i % 3))
                cout << "Fizz";
            if(!(i % 5))
                cout << "Buzz";
        }
        cout << endl;
    }
    while (getchar() != '\n');
    getchar();
}
