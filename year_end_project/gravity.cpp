#include <iostream>
#include <math.h>
#include "point_mass.h"
using namespace std;

void applyGravity(PointMass a, PointMass b) {
    float G = 66.7408; //Yes Gravity has been made much stronger
    float f_grav = -1 * G * a.mass * b.mass / pow(a.position.from(b.position).magnitude(), 2);   // F = G * m * m / r^2
    a.addForce( a.position.from(b.position).normalized().scale(f_grav) );                  // F-> = - F * r^
    b.addForce( b.position.from(a.position).normalized().scale(f_grav) );
}

void applyCoulumbs(PointMass a, PointMass b) {
    float k_c = 8.987551787;
    float f_elec = k_c * a.charge * b.charge / pow(a.position.from(b.position).magnitude(), 2);   // F = G * m * m / r^2
    a.addForce( a.position.from(b.position).normalized().scale(k_c) );                  // F-> = - F * r^
    b.addForce( b.position.from(a.position).normalized().scale(k_c) );
}

int main() {
    int no_of_point_masses; float finish_time, time, time_step;
    cout << "Number of point masses in simulation? "; cin >> no_of_point_masses;
    if (no_of_point_masses <= 0) return 0;
    do {cout << "Time length of simulation? "; cin >> finish_time;} while (finish_time <= 0);
    do {cout << "Time step? "; cin >> time_step;} while(time_step <= 0);
    PointMass point_mass_list[no_of_point_masses];
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
        for (int i = 0; i < no_of_point_masses; ++i) 
            for (int j = i + 1; j < no_of_point_masses; ++j)
                applyGravity(point_mass_list[i], point_mass_list[j]);
        for (int i = 0; i < no_of_point_masses; ++i) {
            point_mass_list[i].update(time_step);
            cout << i << "  : (" << point_mass_list[i].position.x << ", " << point_mass_list[i].position.y << ", " << point_mass_list[i].position.z << ")\n"; 
        }
        cout << "\n";
    }
    
    while (getchar() != '\n');
    getchar();
}
