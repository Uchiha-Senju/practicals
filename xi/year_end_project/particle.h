#include "vector.h"

class Particle {
  public:
  float charge_mass_ratio;
  // float dipole_moment;
  Vector3<> position;
  Vector3<> velocity;
  Vector3<> acceleration;
  
  Particle() {
    this->position = Vector3<>();
    this->velocity = Vector3<>();
    this->acceleration = Vector3<>();
  }
  Particle (Vector3 position, Vector3 velocity, float charge_mass_ratio, float dpm) {
    this->position = pos;
    this->velocity = vel;
    this->charge_mass_ratio = charge_mass_ratio;
    // this->dipole_moment = dpm;
    this->acceleration = Vector3<>();
  }
  
  void addAcceleration(Vector3<> a) {
    this->acceleration += a;
  }
  void update(float time_step) {
    this->position += this->velocity * time_step + this->acceleration * time_step * time_step / 2;  // dx = v * dt but approximately deltax = v * dt + a * dt^2 /2 
    this->velocity += this->acceleration * time_step; // dv = a * dt
    
    this->acceleration = Vector3<>(); // set acceleration to null vector
  }
  
  void applyGravForce(Vector3<> grav_field) {
    this->addAcceleration(grav_field );
  }
  void applyElecForce(Vector3<> elec_field) {
    this->addAcceleration( this->charge_mass_ratio * elec_field );
  }
  void applyMagForce(Vector3<> mag_field) {
    this->addAcceleration( this->charge_mass_ratio * this->velocity.crossProduct(mag_field) );
  }
};