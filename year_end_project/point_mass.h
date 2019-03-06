#include "vector.h"

class PointMass {
    public:
    float mass;
    // float dipole_moment;
    float charge;
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    Vector3 force;
    
    // PointMass (float m, Vector3 pos, Vector3 vel, float chrg, float dpm) {
        // mass = m;
        // position = pos;
        // velocity = vel;
        // charge = chrg;
        // dipole_moment = dpm;
    // }
    void addForce(Vector3 f) {
        force = force.add(f);
    }
    void update(float time_step) {
        acceleration = force.scale(1/mass);
        velocity = velocity.add(acceleration.scale(time_step));
        position = position.add(velocity.scale(time_step)); 
    }
};