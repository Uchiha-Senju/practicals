#include <limits>

template <typename number = double>
number max(number a, number b) {
  if (a > b) 
    return a;
  return b;
}

template <typename number = double>
number abs(number x) {
  if (x < 0) 
    return -x;
  return x;
}

template <typename base_type = double>
base_type pow_int(base_type b, long long int e) {
  if (e == 0 or b == 1) return 1;
  base_type num = 1, square_base = b;
  if (e < 0) square_base = 1/b;
  long long int power = abs(e);
  while (power > 0) {
    if (power % 2) 
      num *= square_base;
    square_base *= square_base;
    power /= 2;
    //cout << "\n\tnum - " << num << "\n\tsquare-base - " << square_base << "\n\tpower - " << power << '\n';
  }
  
  return num;
  
  // if (e > 0) 
    // return num;
  
  // else 
    // return 1 / num;
}

class Polynomial {
  public :
  
  float* coeff;
  unsigned degree;
  
  Polynomial() {
    this->degree = 0;
    this->coeff = nullptr;
  }
  Polynomial(unsigned degree) {
    this->degree = degree;
    this->coeff = new float[degree + 1];
    for (int i = 0; i < degree + 1; ++i)
      this->coeff[i] = 0;
  }
  // One term polynomial
  Polynomial(unsigned power, float coeff) {
    this->degree = power;
    this->coeff = new float[degree + 1];
    for (int i = 0; i < degree; ++i)
      this->coeff[i] = 0;
    this->coeff[power] = coeff;
  }
  Polynomial(unsigned degree, float coeff[]) {
    this->degree = degree;
    this->coeff = new float[degree + 1];
    for (int i = 0; i < degree; ++i)
      this->coeff[i] = coeff[i];
  }
  Polynomial(const Polynomial& p) {
    this->degree = p.degree;
    this->coeff = new float[p.degree + 1];
    for (int i = 0; i < degree + 1; ++i)
      this->coeff[i] = p.coeff[i];
  }
  ~Polynomial() {
    degree = 0;
    delete[] coeff;
    coeff = nullptr;
  }
  
  Polynomial& greaterDegree(Polynomial& a) {
    if (a.degree > this->degree) 
      return a;
    return *this;
  }
  Polynomial& lesserDegree(Polynomial& a) {
    if (this->degree < a.degree) 
      return *this;
    return a;
  }
  Polynomial add(float a) {
    Polynomial sum = Polynomial(*this);
    sum.coeff[0] += a;
    return sum;
  }
  Polynomial subtract(float s) {
    Polynomial difference = Polynomial(*this);
    difference.coeff[0] += s;
    return difference;
  }
  Polynomial multiply(float a) {
    Polynomial product = Polynomial(*this);
    for (int i = 0; i < product.degree + 1; ++i)
      product.coeff[i] *= a;
    return product;
  }
  Polynomial divide(float d) {
    Polynomial quotient = Polynomial(*this);
    if (d == 0) 
      for (int i = 0; i < quotient.degree + 1; ++i)
        quotient.coeff[i] = std::numeric_limits<float>::quiet_NaN();
    for (int i = 0; i < quotient.degree + 1; ++i)
      quotient.coeff[0] /= d;
    return quotient;
  }
  Polynomial add(const Polynomial& a) {
    // Two alternate methods
    /*
    Polynomial sum = Polynomial(max<float>(this->degree, a.degree));
    for (int i = 0; i < this->degree + 1; ++i) 
      sum.coeff[i] += this->coeff[i];
    for (int i = 0; i < a.degree + 1; ++i) 
      sum.coeff[i] += a.coeff[i];
    return sum;
    */
    /*
    Polynomial sum = Polynomial(this->greaterDegree(a));
    for (int i = 0; i < this->lesserDegree(a).degree + 1; --i)
      sum.coeff[i] += this->lesserDegree(a).coeff[i];
    return sum;
    */
    
    Polynomial sum = Polynomial();
    if (this->degree > a.degree) {
      sum = Polynomial(*this);
      for (int i = 0; i < a.degree + 1; ++i)
        sum.coeff[i] += a.coeff[i];
      return sum;
    }
    sum = Polynomial(a);
    for (int i = 0; i < this->degree + 1; ++i)
      sum.coeff[i] += this->coeff[i];
    return sum;
  }
  Polynomial subtract(const Polynomial& a) {
    // Two alternate methods
    /*
    Polynomial difference = Polynomial(max<float>(this->degree, a.degree));
    for (int i = 0; i < this->degree + 1; ++i) 
      difference.coeff[i] += this->coeff[i];
    for (int i = 0; i < a.degree + 1; ++i) 
      difference.coeff[i] -= a.coeff[i];
    return difference;
    */
    /*
    Polynomial difference = Polynomial(this->greaterDegree(a));
    for (int i = 0; i < this->lesserDegree(a).degree + 1; --i)
      difference.coeff[i] -= this->lesserDegree(a).coeff[i];
    if (a.degree > this->degree)
      difference.multiply(-1);
    return difference;
    */
    
    Polynomial difference = Polynomial();
    if (this->degree > a.degree) {
      difference = Polynomial(*this);
      for (int i = 0; i < a.degree + 1; ++i)
        difference.coeff[i] -= a.coeff[i];
      return difference;
    }
    difference = Polynomial(a);
    for (int i = 0; i < this->degree + 1; ++i)
      difference.coeff[i] += this->coeff[i];
    difference.multiply(-1);
    return difference;
  }
  Polynomial multiply(const Polynomial& m) {
    Polynomial product = Polynomial(this->degree + m.degree);
    for (int i = 0; i < this->degree + 1; ++i) 
      for (int j = 0; j < m.degree + 1; ++j)
        product.coeff[i + j] += this->coeff[i] * m.degree;
    return product;
  }
  Polynomial* division(const Polynomial& d) {
    Polynomial* quo_rem = new Polynomial[2];
    
    if (d.degree < this->degree) {
      quo_rem[0] = Polynomial(0);
      quo_rem[1] = d;
      return quo_rem;
    }
    
    float multiplier;
    quo_rem[0] = Polynomial(d.degree - this->degree);
    quo_rem[1] = Polynomial(d);
    for (int i = d.degree - this->degree; i > -1; --i) {
      multiplier = quo_rem[1].coeff[i + this->degree] /  this->coeff[this->degree];
      quo_rem[0].coeff[i] = multiplier;
      quo_rem[1] = quo_rem[1].subtract(this->multiply(Polynomial(i, multiplier)));
    }
    
    return quo_rem;
  }
  float valueAt(float x) {
    float value = 0;
    for (int i = 0; i < this->degree + 1; ++i) 
      value += this->coeff[i] * pow_int<float>(x, i);
    return value;
  }
  Polynomial derivative() {
    Polynomial dp_dx = Polynomial(this->degree - 1);
    for (int i = 0; i < this->degree; ++i) 
      dp_dx.coeff[i] = this->coeff[i + 1] * (i + 1);
    return dp_dx;
  }
  Polynomial integral(float constant_of_integration = 0) {
    Polynomial p_dx = Polynomial(this->degree + 1);
    p_dx.coeff[0] = constant_of_integration;
    for (int i = 1; i < this->degree + 2; ++i) 
      p_dx.coeff[i] = this->coeff[i - 1] / i;
    return p_dx;
  }
};

int main() {
  Polynomial poly_arr[2];
  for (int i = 0; i < 2; ++i) {
    cout << "Enter polynomial " << (i+1) << " : \n";
    cout << "\tDegree : "; cin >> poly_arr[i].degree;
    for (int j = 0; j < poly_arr[i].degree + 1; j++) {
      cout << "\tCoefficient of x^" << j << " : "; cin >> poly_arr[i].coeff[j];
    }
  }
}
