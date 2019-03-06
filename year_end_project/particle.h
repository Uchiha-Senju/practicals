#include "vector.h"

class Particle {
    public:
    float charge;
    // float dipole_moment;
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    
    // Particle (Vector3 pos, Vector3 vel, float chrg, float dpm) {
        // position = pos;
        // velocity = vel;
        // charge = chrg;
        // dipole_moment = dpm;
    // }
    void addAcceleration(Vector3 a) {
        acceleration = acceleration.add(a);
    }
    void update(float time_step) {
        velocity = velocity.add(acceleration.scale(time_step));
        position = position.add(velocity.scale(time_step)); 
    }
};