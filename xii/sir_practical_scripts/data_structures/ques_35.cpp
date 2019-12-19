#include <iostream>
#include <random>
#include <time.h>
using namespace std;

const int no_of_years = 100;
const int max_emp_per_year = 50;

int main() {
  srand((unsigned)time(nullptr));
  int YEAR[no_of_years];
  
  cout << "Year-wise hiring data = [";
  for (int i = 0; i < no_of_years - 1; ++i)
    cout << (YEAR[i] = max_emp_per_year * (float(rand()) / RAND_MAX)) << ", ";
  cout << (YEAR[no_of_years - 1] = max_emp_per_year * (float(rand()) / RAND_MAX)) << "]\n";
  
  int no_emp_sum = 0, exp_emp_sum = 0;
  cout << "\nYears where no employees were appointed (0-" << no_of_years - 1 << " AD) : ";
  for (int i = 0; i < no_of_years - 5; ++i)  
    if ((exp_emp_sum += YEAR[i]), YEAR[i] == 0)
      (cout << i << ", "), no_emp_sum++;
  for (int i = no_of_years - 5; i < no_of_years; ++i)  
    if (YEAR[i] == 0)
      (cout << i << ", "), no_emp_sum++;
  cout << "\nNo. of years where no employees where appointed (0-" << no_of_years - 1 << " AD) : " << no_emp_sum;
  
  cout << "\nNo. of employees appointed 5 years or before : " << exp_emp_sum;
  
  while (getchar() != '\n');
  getchar();
}