#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

template <typename base_type = double>
base_type abs(base_type x) {
  if (x > 0)
    return x;
  else 
    return -x;
}

template <typename base_type = double>
base_type pow_int(base_type b, long long int e) {
  if (e == 0 or b == 1) return 1;
  base_type num = 1, square_base = b;
  if (e < 0) square_base = 1/b; // Takes care of inverse sign
  long long int power = abs(e);
  // Modular Exponentiation Algorithm
  while (power > 0) {
    // if p is odd,
    //   n^p = n * (n*n) ^ (p-1)/2
    // if p is even,
    //   n^p = (n*n) ^ (p/2)
    if (power % 2) 
      num *= square_base;
    square_base *= square_base;
    power /= 2;
  }
  
  return num;
}

template <typename base_type = long long int>
base_type fact(int x) {
  base_type res = 1;
  for (int i = x; i > 1; --i)
    res *= i;
  return res;
}

template <typename base_type = double>
base_type exp(base_type x) {
  base_type a = 0, a_old = 1;
  for (int i = 0; a != a_old; ++i) {
    a_old = a;
    a += pow_int<base_type>(x, i) / fact<base_type>(i);
  }
  return a;
}


template <typename base_type = double>
base_type ln(base_type x) {
  if (x <= 0) return numeric_limits<base_type>::quiet_NaN();
  base_type a = 0, a_old = 1;
  for (int i = 1; a != a_old; i+=2) {
    a_old = a;
    a += pow_int( ((x - 1)/(x + 1)), i) / i;
  }
  return 2*a;
}

template <typename base_type = double, typename exponent_type = double>
base_type pow(base_type b, exponent_type e) {
  return exp(e * ln(b));
}

template <typename base_type = double, typename exponent_type = double>
base_type power(base_type b, exponent_type e = 1) {
  return pow(b,e);
}

int main() {
  long double x, n;
  char pass_exp;
  cout << "Enter base and exponent : "; cin >> x >> n;
  cout << "Pass exponent to function (y/n)? "; cin >> pass_exp;
  cout << "Result is ";
  if (pass_exp == 'n' or pass_exp == 'N') 
    cout << setprecision(50) << std::fixed << power(x);
  else 
    cout << setprecision(50) << std::fixed << power(x,n);
  
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
  cin.clear();
  getchar();
  
  return 0;
}
