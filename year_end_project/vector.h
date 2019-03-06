#include <math.h>

class Vector3 {
    public:
    float x, y, z;
    
    // Vector3 (float x1, float y1, float z1) {
        // x = x1; y = y1; z = z1;
    // }
    bool equals(Vector3 e) {
        if (e.x == x && e.y == y && e.z == z)
                    return true;
        return false;
    }
    void setAs(float new_x, float new_y, float new_z) {
        x = new_x; y = new_y; z = new_z;
    }
    float magnitude() {
        return sqrt(x*x + y*y + z*z);
    }
    Vector3 add(Vector3 a) {
        Vector3 new_vec;
        new_vec.x = x + a.x;
        new_vec.y = y + a.y;
        new_vec.z = z + a.z;
        return new_vec;
    }
    Vector3 scale(float s) {
        Vector3 new_vec;
        new_vec.x = x * s;
        new_vec.y = y * s;
        new_vec.z = z * s;
        return new_vec;
    }
    Vector3 from(Vector3 s) {
        return add(s.scale(-1));
    }
    Vector3 normalized() {
        return scale(1/magnitude());
    }
    float dotProduct(Vector3 d) {
        return (x * d.x + y * d.y + z * d.z);
    }
    Vector3 crossProduct(Vector3 c) {
        Vector3 new_vec;
        new_vec.x = (c.y * z - c.z * y);
        new_vec.y = (c.z * x - c.x * z);
        new_vec.z = (c.x * y - c.y * x);
        return new_vec;
    }
    float angleTo(Vector3 a) {
        float dot = normalized().dotProduct(a.normalized());
        return acos(dot);
    }
};