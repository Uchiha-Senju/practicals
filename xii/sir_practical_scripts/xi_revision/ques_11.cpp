#include <iostream>
using namespace std;

enum  {MORNING, NOON, EVENING, NIGHT};

int main() {
  float temp[3][7], min_max_temp[3][2] = {0, 0, 0, 0, 0, 0}, av_temp[3] = {0,0,0}, av_temp_week;

  cout << "Enter temperatures : \n";
  for (int i = MORNING; i < NIGHT; ++i) {
    cout << '\t';
    for (int j = 0; j < 7; ++j)
      cin >> temp[i][j];
    cout << '\n';
  }

  for (int i = MORNING; i < NIGHT; ++i) {
    min_max_temp[i][0] = temp[i][0];
    min_max_temp[i][1] = temp[i][0];
  }

  for (int i = MORNING; i < NIGHT; ++i) {
    for (int j = 0; j < 7; ++j) {
      if (min_max_temp[i][0] > temp[i][j])
        min_max_temp[i][0] = temp[i][j];
      if (min_max_temp[i][1] < temp[i][j])
        min_max_temp[i][1] = temp[i][j];
      av_temp[i] += temp[i][j];
      av_temp_week += temp[i][j];
    }
    av_temp[i] /= 7;
  }
  av_temp_week /= 7 * 3;
  
  cout << "Minimum morning temperature : " << min_max_temp[MORNING][0] << '\n';
  cout << "Minimum noon temperature : " << min_max_temp[NOON][0] << '\n';
  cout << "Minimum evening temperature : " << min_max_temp[EVENING][0] << '\n';
  cout << "Maximum morning temperature : " << min_max_temp[MORNING][1] << '\n';
  cout << "Maximum noon temperature : " << min_max_temp[NOON][1] << '\n';
  cout << "Maximum evening temperature : " << min_max_temp[EVENING][1] << '\n';
  
  cout << "Average morning temperature : " << av_temp[MORNING] << '\n';
  cout << "Average noon temperature : " << av_temp[NOON] << '\n';
  cout << "Average evening temperature : " << av_temp[EVENING] << '\n';
  
  cout << "Average weekly temperature : " << av_temp_week << '\n';

  while(getchar() != '\n');
  getchar();  
}
