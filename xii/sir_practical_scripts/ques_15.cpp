#include <iostream>
using namespace std;

float& min(float& a, float& b) {
  if (a > b)
    return b;
  else return a;
}

int main() {
  float k, l;
  cout << "Enter values for k and l : "; cin >> k >> l;
  cout << "\nk = " << k;
  cout << "\nl = " << l;
  
  min(k, l) *= (1 + 0.1);
  
  cout << "\nk = " << k;
  cout << "\nl = " << l;
  
  while(getchar() != '\n');
  getchar();
  
  return 0;
}
