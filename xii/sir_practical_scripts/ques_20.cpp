#include <iostream>
#include <math.h>
using namespace std;

class Point {
  public : 
  float x, y;
  
  Point (float x, float y) {
    this->x = x;
    this->y = y;
  }
  Point() {
    *this = Point(0, 0);
  }
  Point(const Point& p) {
    *this = Point(p.x, p.y);
  }
  
  float sqrDistanceFrom(const Point& b) const {
    return ((this->x - b.x)*(this->x - b.x) + (this->y - b.y)*(this->y - b.y));
  }
  float distanceFrom(const Point& b) const {
    return sqrt( this->sqrDistanceFrom(b) );
  }
  float dotProduct(const Point& b) const {
    return (this->x * b.x + this->y * b.y);
  }
  float crossProduct(const Point& b) const {
    return (this->x * b.y - this->y * b.x);
  }
  
  friend istream& operator>>(istream& input_stream, Point& p) {
    while (!(input_stream >> p.x)) {
      input_stream.ignore(1);
      input_stream.clear();
    }
    while (!(input_stream >> p.y)) {
      input_stream.ignore(1);
      input_stream.clear();
    }
    return input_stream;
  }
  friend ostream& operator<<(ostream& display_stream, const Point& p) {
    display_stream << '(' << p.x << ", " << p.y << ')';
    return display_stream;
  }
};

class Triangle {
  public : 
  Point points[3];
  
  Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    this->points[0] = Point(x1, y1);
    this->points[1] = Point(x2, y2);
    this->points[2] = Point(x3, y3);
  }
  Triangle(const Point& p1, const Point& p2, const Point& p3) {
    this->points[0] = p1;
    this->points[1] = p2;
    this->points[2] = p3;
  }
  Triangle() {
    *this = Triangle(0, 0, 0, 0, 0, 0);
  }
  
  float perimeter() const {
    return this->points[0].distanceFrom(this->points[1]) 
         + this->points[1].distanceFrom(this->points[2]) 
         + this->points[2].distanceFrom(this->points[0]);
  }
  float area() const {
    return 0.5 * abs(this->points[0].crossProduct(this->points[1]) 
                   + this->points[1].crossProduct(this->points[2]) 
                   + this->points[2].crossProduct(this->points[0]));
  }
  
  inline friend istream& operator>>(istream& input_stream, Triangle& t) {
    return input_stream >> t.points[0] >> t.points[1] >> t.points[2];
  }
  inline friend ostream& operator<<(ostream& display_stream, const Triangle& t) {
    return display_stream << "( " << t.points[0] << ", " << t.points[1] << ", " << t.points[2] << ")";
  }
  
};

int main() {
  Triangle quadrilateral;
  cout << "Enter the points of the triangle : "; cin >> quadrilateral;
  
  cout << "\nThe points you have entered are " << quadrilateral;
  
  cout << "\n\nPerimeter = " << quadrilateral.perimeter();
  cout << "\nArea = " << quadrilateral.area();
  
  while(getchar() != '\n');
  getchar();
  
  return 0;
}
