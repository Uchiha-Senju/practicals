#include <iostream>
#define SQR(x) x*x
using namespace std;

int Sqr(int x) { return x * x; }

inline int sqr(int x) { return x * x;}

int main () {
  unsigned int choice;
  int n;
  
  cout << "Welcome to Square-inator\n"
       << "========================\n";
  cout << "Input number : "; 
  while(!(cin >> n)); // Check if cin goes into a fail state
  cout << "Choose a squaring method :\n"
       << "\tMacro : 1\n"
       << "\tOutline function : 2\n"
       << "\tInline function : 3\n";
  while(!(cin >> choice)); // Check if cin goes into a fail state
  
  switch ( (choice - 1) % 3 + 1) {
    case 1 :
      cout << SQR(n);
      break;
    case 2 :
      cout << Sqr(n);
      break;
    case 3 :
      cout << sqr(n);
      break;
  }
  
  while (getchar() != '\n');
  getchar();
  
  return 0;
}
