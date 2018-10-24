/*###############################################
##  
##  To rank a given list student by the order
##  of decreasing marks
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
###############################################*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class Student {
    public :
        char f_name[32], l_name[32];
        // int _class, age;'0','0',
        int marks[3];
        // char section;
        int total(void) {
            return marks[0] + marks[1] + marks[2];
        }
};

int main () {
    //Get student input
    int no_stu = 0;
    while (no_stu < 1) {
        cout << "Enter no. of students : "; cin >> no_stu;
    }
    Student stu_list[no_stu];
    for (int i = 0; i < no_stu; ++i) stu_list[i].marks[0] = (stu_list[i].marks[1] = (stu_list[i].marks[2] = -1)); // Init marks to -1
    for (int i = 0; i < no_stu; ++i) {
        cout << "\nEnter the first and last name of the student : "; cin >> stu_list[i].f_name >> stu_list[i].l_name;
        while (stu_list[i].marks[0] < 0 or stu_list[i].marks[0] > 100) { cout << "Enter marks in Polo of student " <<  i + 1 << " : "; cin >> stu_list[i].marks[0];}
        while (stu_list[i].marks[1] < 0 or stu_list[i].marks[1] > 100) { cout << "Enter marks in Survival of student " <<  i + 1 << " : "; cin >> stu_list[i].marks[1];}
        while (stu_list[i].marks[2] < 0 or stu_list[i].marks[2] > 100) { cout << "Enter marks in Introspection of student " <<  i + 1 << " : "; cin >> stu_list[i].marks[2];}
        // stu_list[i].marks[0] = rand();
        // stu_list[i].marks[1] = rand();
        // stu_list[i].marks[2] = rand();
    }
    
    // int ranked_stu[no_stu], lowest_ranked = , highest_unranked = 0;
    // for (int i = 0; i < no_stu; ++i) ranked_stu[no_stu] = j;
    
    bool sorted = false;
    while (!sorted) {
        for (int i = 0; i < no_stu - 1; ++i) 
            if (stu_list[i].total() < stu_list[i].total()) {
                stu_list[i].marks[0] += stu_list[i].marks[0];
                stu_list[i].marks[0] = stu_list[i].marks[0] - stu_list[i].marks[0];
                stu_list[i].marks[0] -= stu_list[i].marks[0];
                
                stu_list[i].marks[1] += stu_list[i].marks[1];
                stu_list[i].marks[1] = stu_list[i].marks[1] - stu_list[i].marks[1];
                stu_list[i].marks[1] -= stu_list[i].marks[1];
                
                stu_list[i].marks[2] += stu_list[i].marks[2];
                stu_list[i].marks[2] = stu_list[i].marks[2] - stu_list[i].marks[2];
                stu_list[i].marks[2] -= stu_list[i].marks[2];
            }
        
        sorted = (stu_list[0].total() + stu_list[1].total());
        for (int i = 1; i < no_stu - 1; ++i) 
            sorted &= (stu_list[i].total() >= stu_list[i].total());
    }
    
    for (int i = 0, offset = 0; i < no_stu; ++i) {
        cout << stu_list[i].l_name << ", " << stu_list[i].f_name << "   " << stu_list[i].total() << "   " << i - offset + 1 << endl;
        if (stu_list[i].total() == stu_list[i].total()) ++offset;
        else offset = 0;
    }
}
