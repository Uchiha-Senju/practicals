#include <math.h>
#include <limits>

template <typename num_type = float, typename arg_type = float>
class Vector2 {
  public: 
  num_type x,y;
  
  Vector2 () {
    this->x = 0;
    this->y = 0;
  }
  Vector2 (num_type n) {
    this->x = n; this->y = n;
  }
  Vector2 (num_type x, num_type y) {
    this->x = x; this->y = y;
  }
  
  // Traditional functions
  bool equals (Vector2<num_type, arg_type> e) {
    if (e.x == this->x and e.y == this->y) 
      return true;
    return false;
  }
  Vector2<num_type, arg_type> setAs(arg_type new_x, arg_type new_y) {
    this->x = new_x;
    this->y = new_y;
    return *this;
  }
  Vector2<num_type, arg_type> setAs(Vector2<num_type, arg_type> e) {
    this->x = e.x;
    this->y = e.y;
    return *this;
  }
  num_type sqrMagnitude() {
    return (this->x*this->x + this->y*this->y);
  }
  num_type magnitude() {
    return sqrt( this->sqrMagnitude() );
  }
  Vector2<num_type, arg_type> add(Vector2<num_type, arg_type> a) {
    Vector2<num_type, arg_type> new_vec;
    new_vec.x = this->x + a.x;
    new_vec.y = this->y + a.y;
    return new_vec;
  }
  Vector2<num_type, arg_type> scale(arg_type s) {
    Vector2<num_type, arg_type> scaled_vec;
    scaled_vec.x = this->x * s;
    scaled_vec.y = this->y * s;
    return scaled_vec;
  }
  Vector2<num_type, arg_type> from(Vector2<num_type, arg_type> s) {
    //return this->add(s.scale(-1));
    
    Vector2<num_type, arg_type> new_vec;
    new_vec.x = this->x - s.x;
    new_vec.y = this->y - s.y;
    return new_vec;
  }
  Vector2<num_type, arg_type> normalized() {
    return this->scale( 1/this->magnitude() );
  }
  Vector2<num_type, arg_type> setMagnitude(arg_type m) {
    return this->scale( m / this->magnitude() );
  }
  Vector2<num_type, arg_type> clamp(arg_type m) {
    if (this->sqrMagnitude() > m*m) 
      return this->setMagnitude(m);
    else
      return *this;
  }
  num_type dotProduct(Vector2<num_type, arg_type> d) {
    return (this->x * d.x + this->y * d.y);
  }
  num_type crossProduct(Vector2<num_type, arg_type> c) {
    return (this->x * c.y - this->y * c.x);
  }
  float angleFrom(Vector2<num_type, arg_type> a) {
    float dot = this->normalized().dotProduct(a.normalized());
    return acos(dot);
  }
  // Operator function definitions
  Vector2<num_type, arg_type> operator+(Vector2<num_type, arg_type> a) {
    return this->add(a);
  }
  Vector2<num_type, arg_type> operator-(Vector2<num_type, arg_type> s) {
    return this->from(s);
  }
  Vector2<num_type, arg_type> operator*(arg_type m) {
    return this->scale(m);
  }
  friend Vector2<num_type, arg_type> operator*(arg_type m, Vector2<num_type, arg_type> vec) {
    return vec * m;
  }
  Vector2<num_type, arg_type> operator/(arg_type d) {
    if (d == 0) 
      return Vector2<num_type, arg_type>(std::numeric_limits<num_type>::quiet_NaN());
    return *this * (1/d);
  }
  bool operator==(Vector2<num_type, arg_type> e) {
    return this->equals(e);
  }
  bool operator>(Vector2<num_type, arg_type> c) {
    return this->sqrMagnitude() > c.sqrMagnitude();
  }
  bool operator<(Vector2<num_type, arg_type> c) {
    return this->sqrMagnitude() < c.sqrMagnitude();
  }
  bool operator>=(Vector2<num_type, arg_type> c) {
    return this->sqrMagnitude() >= c.sqrMagnitude();
  }
  bool operator<=(Vector2<num_type, arg_type> c) {
    return this->sqrMagnitude() <= c.sqrMagnitude();
  }
  Vector2<num_type, arg_type> operator+=(Vector2<num_type, arg_type> a) {
    this->setAs(*this + a);
    return *this;
  }
  Vector2<num_type, arg_type> operator-=(Vector2<num_type, arg_type> s) {
    this->setAs(*this - s);
    return *this;
  }
  Vector2<num_type, arg_type> operator*=(num_type m) {
    this->setAs(m * *this);
    return *this;
  }
  Vector2<num_type, arg_type> operator/=(num_type d) {
    this->setAs(*this / d);
    return *this;
  }
  num_type operator[](unsigned int i) {
    if (i == 0)
      return this->x;
    else if (i == 1)
      return this->y;
    else
      return std::numeric_limits<num_type>::quiet_NaN();
  }
};


template <typename num_type = float, typename arg_type = float>
class Vector3 {
  public:
  num_type x, y, z;
  
  Vector3 () {
    this->x = 0;
    this->y = 0;
    this->x = 0;
  }
  Vector3 (num_type n) {
    this->x = n; this->y = n; this->z = n;
  }
  Vector3 (num_type x, num_type y, num_type z) {
    this->x = x; this->y = y; this->z = z;
  }
  Vector3 (Vector2<num_type, arg_type> vec) {
    this->x = vec.x; this->y = vec.y; this->z = 0;
  }
  
  bool equals(Vector3<num_type, arg_type> e) {
    if (e.x == this->x && e.y == this->y && e.z == this->z)
      return true;
    return false;
  }
  void setAs(arg_type new_x, arg_type new_y, arg_type new_z) {
    this->x = new_x;
    this->y = new_y;
    this->z = new_z;
  }
  void setAs(Vector3<num_type, arg_type> e) {
    this->x = e.x; this->y = e.y; this->z = e.z;
  }
  num_type sqrMagnitude() {
    return (this->x*this->x + this->y*this->y + this->z*this->z);
  }
  num_type magnitude() {
    return sqrt( this->sqrMagnitude() );
  }
  Vector3<num_type, arg_type> add(Vector3<num_type, arg_type> a) {
    Vector3<num_type, arg_type> new_vec;
    new_vec.x = this->x + a.x;
    new_vec.y = this->y + a.y;
    new_vec.z = this->z + a.z;
    return new_vec;
  }
  Vector3<num_type, arg_type> scale(arg_type s) {
    Vector3<num_type, arg_type> new_vec;
    new_vec.x = this->x * s;
    new_vec.y = this->y * s;
    new_vec.z = this->z * s;
    return new_vec;
  }
  Vector3<num_type, arg_type> from(Vector3<num_type, arg_type> s) {
    return this->add(s.scale(-1));
  }
  Vector3<num_type, arg_type> normalized() {
    return this->scale(1/this->magnitude());
  }
  Vector3<num_type, arg_type> setMagnitude(arg_type m) {
    return this->scale( m / this->magnitude() );
  }
  Vector3<num_type, arg_type> clamp(arg_type m) {
    if (this->sqrMagnitude() > m*m) 
      return this->setMagnitude(m);
    else
      return *this;
  }
  num_type dotProduct(Vector3<num_type, arg_type> d) {
    return (this->x * d.x + this->y * d.y + this->z * d.z);
  }
  Vector3<num_type, arg_type> crossProduct(Vector3<num_type, arg_type> c) {
    Vector3<num_type, arg_type> new_vec;
    new_vec.x = (this->y * c.z - this->z * c.y);
    new_vec.y = (this->z * c.x - this->x * c.z);
    new_vec.z = (this->x * c.y - this->y * c.x);
    return new_vec;
  }
  float angleTo(Vector3<num_type, arg_type> a) {
    float dot = this->normalized().dotProduct(a.normalized());
    return acos(dot);
  }
  // Operator function definitions
  Vector3<num_type, arg_type> operator+(Vector3<num_type, arg_type> a) {
    return this->add(a);
  }
  Vector3<num_type, arg_type> operator-(Vector3<num_type, arg_type> s) {
    return this->from(s);
  }
  Vector3<num_type, arg_type> operator*(arg_type m) {
    return this->scale(m);
  }
  friend Vector3<num_type, arg_type> operator*(arg_type m, Vector3<num_type, arg_type> vec) {
    return vec * m;
  }
  Vector3<num_type, arg_type> operator/(arg_type d) {
    if (d == 0) 
      return Vector3<num_type, arg_type>(std::numeric_limits<num_type>::quiet_NaN());
    return *this * (1/d);
  }
  bool operator==(Vector3<num_type, arg_type> e) {
    return this->equals(e);
  }
  bool operator>(Vector3<num_type, arg_type> c) {
    return this->sqrMagnitude() > c.sqrMagnitude();
  }
  bool operator<(Vector3<num_type, arg_type> c) {
    return this->sqrMagnitude() < c.sqrMagnitude();
  }
  bool operator>=(Vector3<num_type, arg_type> c) {
    return this->sqrMagnitude() >= c.sqrMagnitude();
  }
  bool operator<=(Vector3<num_type, arg_type> c) {
    return this->sqrMagnitude() <= c.sqrMagnitude();
  }
  Vector3<num_type, arg_type> operator+=(Vector3<num_type, arg_type> a) {
    this->setAs(*this + a);
    return *this;
  }
  Vector3<num_type, arg_type> operator-=(Vector3<num_type, arg_type> s) {
    this->setAs(*this - s);
    return *this;
  }
  Vector3<num_type, arg_type> operator*=(num_type m) {
    this->setAs(m * *this);
    return *this;
  }
  Vector3<num_type, arg_type> operator/=(num_type d) {
    this->setAs(*this / d);
    return *this;
  }
  num_type operator[](unsigned int i) {
    if (i == 0)
      return this->x;
    else if (i == 1)
      return this->y;
    else
      return std::numeric_limits<num_type>::quiet_NaN();
  }
};
