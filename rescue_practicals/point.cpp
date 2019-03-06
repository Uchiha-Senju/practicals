#include <iostream>
#include <math.h>
using namespace std;

class Point {
    public:
    float x, y, z;
    float distanceTo(Point b) {
        return sqrt(pow((b.x - x), 2) + pow((b.y - y), 2) + pow((b.z - z), 2));
    }
};

int main() {
    int no_of_points;
    cout << "Number of points? "; cin >> no_of_points;
    Point points[no_of_points];
    for (int i = 0; i < no_of_points; ++i) {
        cout << "\nEnter details of point " << i << " : \n";
        cout << "\tx : "; cin >> points[i].x;
        cout << "\ty : "; cin >> points[i].y;
        cout << "\tz : "; cin >> points[i].z;
    }
    cout << "\n\n";
    for (int i = 0; i < no_of_points; ++i)
        for (int j = i + 1; j < no_of_points; ++j)
            cout << "Distance between points " << i << " and " << j << " : " << points[i].distanceTo(points[j]) << endl;
    
    while (getchar() != '\n');
    getchar();
}
