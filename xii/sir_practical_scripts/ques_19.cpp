#include <iostream>
using namespace std;

long long HCF(long long a, long long b) {
  long long temp;
  if (a < b) {
    temp = a;
    a = b;
    b = temp;
  }
  while (a % b != 0ll) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return b;
}

inline long long LCM(long long a, long long b) {
  return a * (b / HCF(a,b));
}

class Fraction {
  public :
  long long numerator, denominator;
  
  Fraction() {
    this->numerator = 0;
    this->denominator = 1;
  }
  Fraction(long long num, long long den) {
    long long hcf = HCF(num,den);
    this->numerator = num / hcf;
    if (den == 0)
      this->denominator = 1;
    else
      this->denominator = den / hcf;
    if (this->denominator < 0) {
      this->denominator *= -1;
      this->numerator *= -1;      
    }
  }
  Fraction(long long k) {
    *this = Fraction(k,1);
    // this->Fraction(k,1);
  }
  Fraction(long double d) {
    *this = Fraction(d * 1e8, 1e8);
  }
  
  
  Fraction add(const Fraction& a) const {
    long long den_hcf = HCF(this->denominator, a.denominator);
    return Fraction(this->numerator * (a.denominator / den_hcf) + a.numerator * (this->denominator / den_hcf),
                    LCM(this->denominator, a.denominator));
  }
  Fraction subtract(const Fraction& s) const {
    long long den_hcf = HCF(this->denominator, s.denominator);
    return Fraction(this->numerator * (s.denominator / den_hcf) - s.numerator * (this->denominator * den_hcf),
                    LCM(this->denominator, s.denominator));
  }
  Fraction multiply(const Fraction& m) const {
    return Fraction(this->numerator * m.numerator, this->denominator * m.denominator);
  }
  Fraction divide(const Fraction& d) const {
    return Fraction(this->numerator * d.denominator, this->denominator * d.numerator);
  }
  
  operator long double() {
    return (long double)(this->numerator) / this->denominator;
  }
  
  inline friend Fraction operator+(const Fraction& a, const Fraction& b) {
    return a.add(b);
  }
  inline friend Fraction operator-(const Fraction& a, const Fraction& b) {
    return a.subtract(b);
  }
  inline friend Fraction operator*(const Fraction& a, const Fraction& b) {
    return a.multiply(b);
  }
  inline friend Fraction operator/(const Fraction& a, const Fraction& b) {
    return a.divide(b);
  }
  inline friend Fraction operator+=(Fraction& a, const Fraction& b) {
    return a = a.add(b);
  }
  inline friend Fraction operator-=(Fraction& a, const Fraction& b) {
    return a = a.subtract(b);
  }
  inline friend Fraction operator*=(Fraction& a, const Fraction& b) {
    return a = a.multiply(b);
  }
  inline friend Fraction operator/=(Fraction& a, const Fraction& b) {
    return a = a.divide(b);
  }
  friend istream& operator>>(istream& input_stream, Fraction& f) {
    while (!(input_stream >> f.numerator)) {
      input_stream.ignore(1);
      input_stream.clear();
    }
    while (!(input_stream >> f.denominator)) {
      input_stream.ignore(1);
      input_stream.clear();
    }
    f =  Fraction(f.numerator, f.denominator);
    return input_stream;
  }
  friend ostream& operator<<(ostream& display_stream, const Fraction f) {
    display_stream << f.numerator << '/' << f.denominator;
    return display_stream;
  }
};

int main() {
  Fraction r1, r2;
  
  cout << "Enter r1 : "; cin >> r1;
  cout << "Enter r2 : "; cin >> r2;
  
  cout << "\nr1 = " << r1;
  cout << "\nr2 = " << r2;
  
  cout << "\n\nr1 + r2 = " << r1 + r2;
  cout << "\nr1 - r2 = " << r1 - r2;
  cout << "\nr1 * r2 = " << r1 * r2;
  
  while (getchar() != '\n');
  getchar();
  
  return 0;
}
