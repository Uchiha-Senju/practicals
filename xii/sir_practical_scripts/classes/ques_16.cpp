#include <iostream>
#include <iomanip>
#include <limits>
#include <windows.h>
using namespace std;


// source - http://www.cplusplus.com/articles/4z18T05o/
#if defined _WIN32
    #include <windows.h>

  void ClearScreen() {
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
      hStdOut,
      (TCHAR) ' ',
      cellCount,
      homeCoords,
      &count
      )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
      hStdOut,
      csbi.wAttributes,
      cellCount,
      homeCoords,
      &count
      )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
  }
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) ||  defined (__APPLE__)
  #include <unistd.h>
  #include <term.h>

  void ClearScreen() {
    if (!cur_term)
      {
      int result;
      setupterm( NULL, STDOUT_FILENO, &result );
      if (result <= 0) return;
      }

    putp( tigetstr( "clear" ) );
  }

#endif

void gotoxy(int x, int y) {
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

struct Student {
  char name[20];
  unsigned int marks;
};

void quickSort(Student* arr, unsigned int start, unsigned int end, bool ascending = true) {
  if (end <= start + 1 or arr == nullptr)
    return;
  int pivotIndex = start;
  Student temp;
  for (int i = start; i < end - 1; ++i) {
    if (arr[i].marks < arr[end - 1].marks xor not ascending) {
      temp = arr[i];
      arr[i] = arr[pivotIndex];
      arr[pivotIndex] = temp;
      pivotIndex++;
    }
  }
  temp = arr[pivotIndex];
  arr[pivotIndex] = arr[end - 1];
  arr[end - 1] = temp;
  quickSort(arr, start, pivotIndex, ascending);
  quickSort(arr, pivotIndex + 1, end, ascending);
  return;
}

int main () {
  Student stu_arr[20];
  int no_of_students;
  bool ascending = false;
  char choice;
  do {
    cout << "No. of students? ";
    cin >> no_of_students;
  } while (no_of_students > 20);
  cout << "Enter student details : \n";
  for (int i = 0; i < no_of_students; ++i) {
    cout << "\tStudent " << i << " : \n";
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
    cout << "\t\tName : "; cin.getline(stu_arr[i].name, 20, '\n');
    cout << "\t\tAggregate marks : "; cin >> stu_arr[i].marks;
  }
  
  // Normal code
  // cout << " S.No.   Name                 Marks\n"
       // << " -----   -------------------  -----\n";
  // for (int i = 0; i < no_of_students; ++i) {
    // cout << ' ' << setw(2) << i << ".     ";
    // cout << setw(19) << stu_arr[i].name << "  ";
    // cout << setw(4) << stu_arr[i].marks << '\n';
  // }
  
  cout << "\n\nDisplay in ascending (y/n)?";
  cin >> choice;
  if (choice == 'y' or choice == 'Y') ascending = true;
  quickSort(stu_arr, 0 , no_of_students, ascending);
  
  ClearScreen();
  
  gotoxy(1, 0);
  cout << "S.No.   Name                 Marks\n";
  gotoxy(1, 1);
  cout << "-----   -------------------  -----\n";
  for (int i = 0; i < no_of_students; ++i) {
    gotoxy(1, 2 + i);
    cout << setw(2) << (i + 1) << '.';
    
    gotoxy(9, 2 + i);
    cout << setw(19) << stu_arr[i].name;
    gotoxy(30, 2 + i);
    cout << setw(4) << stu_arr[i].marks;
  }
  
  while (getchar() != '\n');
  getchar();
}
