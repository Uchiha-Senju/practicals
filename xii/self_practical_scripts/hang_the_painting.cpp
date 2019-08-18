#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class HangPattern {
  public :
    string pattern;
    
    HangPattern() : pattern() {};
    HangPattern(const char c) : pattern() {
      pattern += c;
    }
    HangPattern(const char* str) : pattern(str) {
    }
    HangPattern(const string str) : pattern(str) {
    }
    HangPattern& operator=(const HangPattern& hp) {
      pattern = hp.pattern;
    }
    HangPattern(const HangPattern& hp) {
      *this = hp;
    }
   
    unsigned long length() {
      return pattern.length();
    }
    HangPattern inverse() {
      HangPattern p = HangPattern();
      for (int i = pattern.length() - 1; i > -1; --i) {
        char c = pattern[i];
        if (c >= 'a' and c <= 'z')
          c -= 32;
        else
          c += 32;
        p.append(c);
      }
      return p;
    }
    HangPattern shift(unsigned shift_value) {
      HangPattern p = HangPattern();
      for (int i = 0; i < pattern.length(); ++i) {
        p.pattern.push_back( pattern[i] + shift_value );
      }
      return p;
    }
   private :
    void append(char c) {
      pattern += c;
    }
    void append(string str) {
      pattern += str;
    }
    HangPattern& operator+=(char c) {
      this->append(c);
      return *this;
    }
    HangPattern& operator+=(string str) {
      this->append(str);
      return *this;
    }
   public :
    void append(const HangPattern& hp) {
      pattern += hp.pattern;
    }
    HangPattern& operator+=(const HangPattern& hp) {
      this->append(hp);
      return *this;
    }
    friend ostream& operator<<(ostream& output_stream, const HangPattern& hp) {
      for (int i = 0; i < hp.pattern.length(); ++i) 
        output_stream << hp.pattern[i];
      return output_stream;
    }
    
    friend HangPattern evenSplitSolution(unsigned, unsigned);
    friend HangPattern appendSolution(unsigned, unsigned);
    friend HangPattern superSplitSolution(unsigned);
};

// Produce a solution such that, when interpreted as clockwise 
// and counter-clockwise turns around hooks, allows one to hang 
// something in such a way such that if one hook is removed, the
// entire strinc comes loose

// Evenly split the hooks into super hooks A, B, solution is AbaB, ~=n^2
HangPattern evenSplitSolution(unsigned hook_end, unsigned hook_start = 0) {
  HangPattern final_pattern;
  if (hook_end <= hook_start) 
    final_pattern = HangPattern();
  else if (hook_end == hook_start + 1)
    final_pattern = HangPattern( char(65 + hook_start) );
  else if (hook_end == hook_start + 2) {
    final_pattern = HangPattern( char(65 + hook_start) );
    final_pattern += char(65 + 32 + 1 + hook_start);
    final_pattern += char(65 + 32 + hook_start);
    final_pattern += char(65 + 1 + hook_start);
  } else {
    HangPattern hp_1 = evenSplitSolution( ((hook_start + hook_end) / 2) , hook_start ),
                hp_2 = evenSplitSolution( hook_end, ((hook_start + hook_end) / 2) );
    final_pattern = hp_1;
    final_pattern += hp_2.inverse();
    final_pattern += hp_1.inverse();
    final_pattern += hp_2;
  }
  
  return final_pattern;
}

// Generate a solution based on the previous one, a 1:(n-1) split, = 3*2^(n-1) - 2
HangPattern appendSolution(unsigned hook_end, unsigned hook_start = 0) {
  HangPattern final_pattern;
  if (hook_end <= hook_start) 
    final_pattern = HangPattern();
  else if (hook_end == hook_start + 1)
    final_pattern = HangPattern( char(65 + hook_start) );
  else if (hook_end == hook_start + 2) {
    final_pattern = HangPattern( char(65 + hook_start) );
    final_pattern += char(65 + 32 + 1 + hook_start);
    final_pattern += char(65 + 32 + hook_start);
    final_pattern += char(65 + 1 + hook_start);
  } else {
    HangPattern hp_1 = appendSolution( hook_end - 1 , hook_start ),
                hp_2 = HangPattern(char(65 + hook_end - 1));
    final_pattern = hp_1;
    final_pattern += hp_2.inverse();
    final_pattern += hp_1.inverse();
    final_pattern += hp_2;
  }
  
  return final_pattern;
}

// Don't stick to a 2-part split, do multiple
HangPattern superSplitSolution(unsigned hooks) {
  HangPattern final_pattern;
  if (hooks <= 0) 
    final_pattern = HangPattern();
  else if (hooks == 1)
    final_pattern = HangPattern( char(65 + 0) );
  else if (hooks == 2) 
    final_pattern = HangPattern( "AbaB" );
  else if (hooks == 3) 
    final_pattern = HangPattern( "AbaBcaBAbC" );
  else {
    final_pattern = HangPattern();
    int splits = floor(sqrt(hooks));
    int last_split_length = hooks - splits * (splits - 1);

    HangPattern hp = superSplitSolution( splits );
    HangPattern hp_last = superSplitSolution( last_split_length );

    for (int i = 0; i < hp.pattern.length(); ++i) {
      char c = hp.pattern[i];
      if ('A' <= c and c <= 'Z') {
        if (c == char(splits + 64)) 
          final_pattern += hp_last.shift( (c - 65) * splits );
        else 
          final_pattern += hp.shift( (c - 65) * splits );
      } else {
        if (c == char(splits + 64 + 32)) 
          final_pattern += hp_last.inverse().shift( (c - 65 - 32) * splits);
        else 
          final_pattern += hp.inverse().shift( (c - 65 - 32) * splits );
      }
        
    }
  }
  
  return final_pattern;
}

int main() {
  unsigned short no_of_hooks;
  char choice;
  HangPattern hp;
  
  while (true) {
    cout << "No of hooks? "; cin >> no_of_hooks;
    
    cout << '\n';
    cout << "\tAppend Method - 1\n"
         << "\tEven Split Method - 2\n"
         << "\tSuper Split Method - 3\n";
         
    cout << "Enter your choice : "; cin >> choice;
    
    switch (choice) {
      case '1' :
        if ( no_of_hooks < 20) { // Solution size is 1.5 MB
          hp = appendSolution(no_of_hooks);
          cout << "\nSolution length - " << 3 * pow(2, no_of_hooks - 1) - 2 << '\n';
          cout << "Solution - " << hp << "\n\n";
        } else {
          cout << "\nSolution length - " << 3 * pow(2, no_of_hooks - 1) - 2 << '\n';
          cout << "Projected solution length is too large, not going to calculate\n\n";
        }
        break;
      case '2' : 
        if ( no_of_hooks < 1200) { // Solution size is 1.5 MB
          hp = evenSplitSolution(no_of_hooks);
          cout << "\nSolution length - " << hp.length() << '\n';
          cout << "Solution - " << hp << "\n\n";
        } else {
          cout << "\nProjected Solution length - " << 0.835 * pow(no_of_hooks, 2.075) << '\n';
          cout << "Projected solution length is too large, not going to calculate\n\n";
        }
        break;
      case '3' :
        if ( no_of_hooks < 1050) { // Solution size is 1.5 MB
          hp = superSplitSolution(no_of_hooks);
          cout << "\nSolution length - " << hp.length() << '\n';
          cout << "Solution - " << hp << "\n\n";
        } else {
          cout << "\nProjected Solution length - " << 0.1944 * pow(no_of_hooks, 2.556) << '\n';
          cout << "Projected solution length is too large, not going to calculate\n\n";
        }
        break;
      case 'q' : case 'Q' : case 'e' : case 'E' : case 'b' : case 'B' :
        return 0;
        break;
    }
  }
  // for (int i = 1; i < 50; ++i)
    // cout << i <</* " --- " << evenSplitSolution(i).length() << " :*/"," << evenSplitSolution(i).length() << '\n';
}