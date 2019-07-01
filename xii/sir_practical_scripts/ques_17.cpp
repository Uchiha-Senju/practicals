#include <iostream>
using namespace std;

class FeetInches {
  public :
  
  int feet;
  short inches;
  
  FeetInches() {
    this->feet = 0;
    this->inches = 0;
  }
  FeetInches(int f, short i) {
    this->feet = f;
    this->inches = i;
    this->Adjust();
  }
  
  FeetInches Adjust() {
    if (this->inches > 0) {
    this->feet += this->inches / 12;
    this->inches %= 12;
    } else {
    this->feet += -1 + this->inches / 12;
    this->inches = ((this->inches % 12) + 12) % 12;
    }
  }
  FeetInches getInput(istream& input_stream) {
    while (!(input_stream >> this->feet))
      input_stream.clear();
    while (!(input_stream >> this->inches))
      input_stream.clear();
    this->Adjust();
  }
  FeetInches printSelf(ostream& display_stream) {
    display_stream << this->feet << "\' " << this->inches << '\"';
  }
  
  FeetInches operator+(FeetInches f) {
    return FeetInches(this->feet + f.feet, this->inches + f.inches);
  }
  FeetInches operator+=(FeetInches f) {
    this->feet += f.feet;
    this->inches += f.inches;
    this->Adjust();
    return *this;
  }
};

FeetInches add(FeetInches a, FeetInches b) {
  return a + b;
}

int main () {
  FeetInches dist1, dist2;
  cout << "Enter dist1 (feet,inches) : "; dist1.getInput(cin);
  cout << "Enter dist2 (feet,inches) : "; dist2.getInput(cin);
  
  cout << "\n\ndist1 = "; dist1.printSelf(cout);
  cout << "\ndist2 = "; dist2.printSelf(cout);
  
  cout << "\ndist1 + dist2 = "; add(dist1, dist2).printSelf(cout);
  
  while(getchar() != '\n');
  getchar();
  
  return 0;
}
