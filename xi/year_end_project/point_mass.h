#include "vector.h"
#define M_PI 3.14159265358979323846


class PointMass {
  public:
  float mass;
  // float dipole_moment;
  float charge;
  Vector3<> position;
  Vector3<> velocity;
  Vector3<> acceleration;
  Vector3<> force;
  
  PointMass (float m, Vector3<> pos, Vector3<> vel, float chrg/*, float dpm*/) {
    this->mass = m;
    this->position = pos;
    this->velocity = vel;
    this->charge = chrg;
    // this->dipole_moment = dpm;
  }
  PointMass () {
    mass = 1; // prevent division errors
    position = Vector3<>(); // set to null vector
    velocity = Vector3<>();
    charge = 0;
    force = Vector3<>();
  }
  
  void addForce(Vector3<> f) {
    this->force += f;
  }
  void update(float time_step) {
    this->acceleration = this->force / this->mass; // F = m * a
    this->position += this->velocity * time_step + this->acceleration * time_step * time_step / 2;  // dx = v * dt but approximately deltax = v * dt + a * dt^2 /2 
    this->velocity += this->acceleration * time_step; // dv = a * dt
    
    this->force = Vector3<>(); // set force to null vector
    this->acceleration = Vector3<>(); // set force to null vector
  }
  Vector3<> getGravitationalField(Vector3<> position) {
    float G = 66.7408; //Yes Gravity has been made much stronger
    // Vector3<> r = position.from(this->position);
    
    float grav_field = -1 * G * this->mass / (position - this->position).sqrMagnitude();   // g = - G * m / r^2
    
    return grav_field * (position - this->position);
  }
  Vector3<> getElectricField(Vector3<> position) {
    float e_0 = 0.885418782; 
    // Vector3<> r = position.from(this->position);
    
    float elec_field = (1 / (4 * M_PI * e_0)) * this->charge / (position - this->position).sqrMagnitude();   // E = 1/(4pi * e_0) * q / r^2
    
    return elec_field * (position - this->position);
  }
  Vector3<> getMagneticField(Vector3<> position) {
    float mu_0 = 1.25663706;
    // Vector3<> r = position.from(this->position);
    
    float mag_field = (mu_0 / (4 * M_PI)) * this->charge / (position - this->position).sqrMagnitude();   // B-> = mu_0 / 4pi * q * v->Xr^ / r^2
    
    return mag_field * this->velocity.crossProduct( (position - this->position).normalized() );
  }
  
  void applyGravForce(Vector3<> grav_field) {
    this->addForce( this->mass * grav_field );
  }
  void applyElecForce(Vector3<> elec_field) {
    this->addForce( this->charge * elec_field );
  }
  void applyMagForce(Vector3<> mag_field) {
    this->addForce( this->charge * this->velocity.crossProduct(mag_field) );
  }
};
