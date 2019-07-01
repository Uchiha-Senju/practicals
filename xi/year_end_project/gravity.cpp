#include <iostream>
#include "point_mass.h"
using namespace std;

// void applyGravity(PointMass a, PointMass b) {
  // float G = 66.7408; //Yes Gravity has been made much stronger
  // Vector3 r = a.position.from(b.position);
  
  // float f_grav = -1 * G * a.mass * b.mass / r.sqrMagnitude();   // F = G * m * m / r^2
  
  // a.addForce( r.normalized().scale(f_grav) );          // F-> = - F * r^
  // b.addForce( r.normalized().scale(-f_grav) );         // F_21-> = -F_12->
// }

// void applyElectric(PointMass a, PointMass b) {
  // float k_c = 8.987551787;
  // Vector3 r = a.position.from(b.position);
  
  // float f_elec = k_c * a.charge * b.charge / r.sqrMagnitude();   // F = G * m * m / r^2
  
  // a.addForce( r.normalized().scale(k_c) );          // F-> = - F * r^
  // b.addForce( r.normalized().scale(-k_c) );         // F_21-> = -F_12->
// }

// void applyMagnetic(PointMass a, PointMass b) {
  // float mu_0 = 1.25663706;
  // Vector3 r = a.position.from(b.position);
  // Vector3 F_mag = a.velocity.crossProduct(  b.velocity.crossProduct( r.normalized() )  ).scale(a.charge * b.charge / r.sqrMagnitude());
  // F_mag = F_mag.scale(mu_0 / (4 * PI));
  
  // a.addForce(F_mag);
  // b.addForce(F_mag.scale(-1));
// }

int main() {
  int no_of_point_masses; float finish_time, time, time_step;
  cout << "Number of point masses in simulation? "; cin >> no_of_point_masses;
  if (no_of_point_masses <= 0) return 0;
  
  do {cout << "Time length of simulation? "; cin >> finish_time;} while (finish_time <= 0);
  do {cout << "Time step? "; cin >> time_step;} while(time_step <= 0);
  
  PointMass* point_mass_list = new PointMass[no_of_point_masses];
  for (int i = 0; i < no_of_point_masses; ++i) {
    cout << "\nDetails of mass " << i << " : \n";
    cout << "\tMass : "; cin >> point_mass_list[i].mass;
    cout << "\tCharge : "; cin >> point_mass_list[i].charge;
    // cout << "\tDipole moment : "; cin >> point_mass_list[i].dipole_moment;
    cout << "\tPosition : \n";
    cout << "\t\tx : "; cin >> point_mass_list[i].position.x;
    cout << "\t\ty : "; cin >> point_mass_list[i].position.y;
    cout << "\t\tz : "; cin >> point_mass_list[i].position.z;
    cout << "\tVelocity : \n";
    cout << "\t\tx : "; cin >> point_mass_list[i].velocity.x;
    cout << "\t\ty : "; cin >> point_mass_list[i].velocity.y;
    cout << "\t\tz : "; cin >> point_mass_list[i].velocity.z;
  }
  
  
  cout << "\n\nBegin simulation of Gravity : \n\n";
  
  
  for (time = 0; time < finish_time; time += time_step) {
    for (int i = 0; i < no_of_point_masses; ++i) { 
      Vector3 g_field = Vector3<>(),
              e_field = Vector3<>(), 
              m_field = Vector3<>();
      for (int j = 0; j < no_of_point_masses; ++j) 
        if (i != j) {
          g_field += point_mass_list[j].getGravitationalField(point_mass_list[i].position);
          e_field += point_mass_list[j].getElectricField(point_mass_list[i].position);
          m_field += point_mass_list[j].getMagneticField(point_mass_list[i].position);
        }
      point_mass_list[i].applyGravForce(g_field);
      point_mass_list[i].applyElecForce(e_field);
      point_mass_list[i].applyMagForce(m_field);
    }
    for (int i = 0; i < no_of_point_masses; ++i) {
      point_mass_list[i].update(time_step);
      cout << i << "  : (" << point_mass_list[i].position.x << ", " << point_mass_list[i].position.y << ", " << point_mass_list[i].position.z << ")\n"; 
    }
    cout << "\n";
  }
  
  while (getchar() != '\n');
  getchar();
}
