#include <iostream>
#include <random>
#include <time.h>
using namespace std;

const int no_of_years = 10;

int main() {
  srand((unsigned)time(nullptr));
  int YEAR[no_of_years];
  
  for (int i = 0; i < no_of_years; ++i)
    cout << (YEAR[i] = no_of_years * (rand() / RAND_MAX)) << ", ";
  
  int no_emp_sum = 0, exp_emp_sum = 0;
  cout << "\nYears where no employees were appointed (0-" << no_of_years - 1 << " AD) : ";
  for (int i = 0; i < no_of_years - 5; ++i)  
    if (YEAR[i] == 0)
      (cout << i << ", "), no_emp_sum++, exp_emp_sum += YEAR[i];
  for (int i = no_of_years - 5; i < no_of_years; ++i)  
    if (YEAR[i] == 0)
      (cout << i << ", "), no_emp_sum++;
  cout << "\nNo. of years where no employees where appointed (0-" << no_of_years - 1 << " AD) : " << no_emp_sum;
  
  cout << "\nNo. of employees appointed 5 years or before : " << exp_emp_sum;
  
  while (getchar() != '\n');
  getchar();
}