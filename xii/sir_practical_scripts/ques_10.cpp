#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main() {
  int m, n;
  cout << "Size of matrix (m x n)? "; cin >> m >> n;
  int matrix[m][n];

  cout <<  "Enter matrix : \n";
  for (int i = 0; i < m; ++i) {
    cout << '\t';
    for (int j = 0; j < n; ++j)
      cin >> matrix[i][j];
  }

  cout << "\nColumn sums : \n\t";
  for (int j = 0; j < n; ++j) {
    int col_sum = 0;
    for (int i = 0; i < m; ++i)
      col_sum += matrix[i][j];
    cout << setw(10) << col_sum << ' ';
  }

  cout << "\nRow sums :    \n";
  for (int i = 0; i < m; ++i) {
    int row_sum = 0;
    for (int j = 0; j < n; ++j)
      row_sum += matrix[i][j];
    cout << '\t' << setw(10) << row_sum << '\n';
  }

  cout << "\nMain diagonal sum : ";
  int diag_sum = 0;
  for (int i = 0, j = 0; i < m and j < n; i++, j++)
    diag_sum += matrix[i][j];
  cout << diag_sum << '\n';

  cout << "\nBack diagonal sum : ";
  diag_sum = 0;
  for (int i = 0, j = n - 1; i < m and  j >= 0; i++, j--)
    diag_sum += matrix[i][j];
  cout << diag_sum << '\n';

  cout << "Transpose : \n";
  for (int j = 0; j < n; ++j) {
    cout << '\t';
    for (int i = 0; i < m; ++i)
      cout << setw(10) << matrix[i][j];
    cout << '\n';
  }

  cout << "\nUpper Triangle : \n";
  for (int i = 0; i < m; ++i) {
    cout << '\t';
    for (int j = 0; j < n; ++j) {
      if (i > j)
        cout << setw(10) << '0';
      else
        cout << setw(10) << matrix[i][j];
    }
    cout << '\n';
  }

  cout << "\nLower Triangle : \n";
  for (int i = 0; i < m; ++i) {
    cout << '\t';
    for (int j = 0; j < n; ++j) {
      if (i < j)
        cout << setw(10) << '0';
      else
        cout << setw(10) << matrix[i][j];
    }
    cout << '\n';
  }

  while (getchar() != '\n');
  getchar();
  return 0;
}
