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
#include <iomanip>
using namespace std;

class Student {
    public :
        char f_name[32], l_name[32];
        // int _class, age;
        int marks[3];
        // char section;
        int total(void) {
            return marks[0] + marks[1] + marks[2];
        }
        char grade(void) {
            int t = total();
            if (t >= 270) return 'A';
            else if (t >= 240) return 'B';
            else if (t >= 210) return 'C';
            else if (t >= 180) return 'D';
            else if (t >= 150) return 'E';
            else return 'F';
        }
};

void strcpy(char* s1, const char* s2) {
    int i;
    for (i = 0; s2[i] != '\0'; ++i) 
        s1[i] = s2[i];
    s1[i] = '\0';
}

void strcat(char* s1, const char* s2) {
    int i;
    for (i = 0; s1[i] != '\0'; i++);
    for (int j = 0; s2[j] != '\0'; ++j, ++i) 
        s1[i] = s2[j];
    s1[i] = '\0';
}

void sortByBubble(Student* stu_list, int size, bool ascending) {
    Student temp_stu;
    bool sorted = false;
    if (ascending) {
        while (!sorted) {
            for (int i = 0; i < size - 1; ++i) 
                if (stu_list[i].total() > stu_list[i + 1].total()) {
                    temp_stu = stu_list[i];
                    stu_list[i] = stu_list[i + 1];
                    stu_list[i + 1] = temp_stu;
                }
            
            sorted = (stu_list[0].total() <= stu_list[1].total());
            for (int i = 1; i < size - 1; ++i) 
                sorted &= (stu_list[i].total() <= stu_list[i + 1].total());
        }
    } else {
        while (!sorted) {
            for (int i = 0; i < size - 1; ++i) 
                if (stu_list[i].total() < stu_list[i + 1].total()) {
                    temp_stu = stu_list[i];
                    stu_list[i] = stu_list[i + 1];
                    stu_list[i + 1] = temp_stu;
                }
            
            sorted = (stu_list[0].total() >= stu_list[1].total());
            for (int i = 1; i < size - 1; ++i) 
                sorted &= (stu_list[i].total() >= stu_list[i + 1].total());
        }
    }
}

void sortBySelection (Student* stu_list, int size, bool ascending) {
    Student temp_stu;
    int max_marks_index = 0;
    bool sorted = false;
    if (ascending) {
        for (int s = size - 1; s > -1; --s) {
            max_marks_index = 0;
            for (int i = s; i > -1; --i) 
                if (stu_list[i].total() > stu_list[max_marks_index].total()) 
                    max_marks_index = i;
            
            temp_stu = stu_list[s];
            stu_list[s] = stu_list[max_marks_index];
            stu_list[max_marks_index] = temp_stu;
        }
    } else {
        for (int s = 0; s < size; ++s) {
            int max_marks_index = s;
            for (int i = s; i < size; ++i) 
                if (stu_list[i].total() > stu_list[max_marks_index].total()) 
                    max_marks_index = i;
            
            temp_stu = stu_list[s];
            stu_list[s] = stu_list[max_marks_index];
            stu_list[max_marks_index] = temp_stu;
        }
    }
}

int main () {
    //Get student input
    int no_stu = 0;
    while (no_stu < 1) {
        cout << "Enter no. of students : "; cin >> no_stu;
    }
    Student stu_list[no_stu];
    for (int i = 0; i < no_stu; ++i) stu_list[i].marks[0] = (stu_list[i].marks[1] = (stu_list[i].marks[2] = -1)); // Init marks to -1
    for (int i = 0; i < no_stu; ++i) {
        // Actual
        cout << "\nEnter details of student " << i + 1 << " : \n";
        cout << "\tGiven name : ";cin >> stu_list[i].f_name;
        cout << "\tFamily name : ";cin >> stu_list[i].l_name;
        cout << "\tMarks : \n";
        while (stu_list[i].marks[0] < 0 or stu_list[i].marks[0] > 100) { cout << "\t\tPolo : "; cin >> stu_list[i].marks[0]; }
        while (stu_list[i].marks[1] < 0 or stu_list[i].marks[1] > 100) { cout << "\t\tSurvival : "; cin >> stu_list[i].marks[1];}
        while (stu_list[i].marks[2] < 0 or stu_list[i].marks[2] > 100) { cout << "\t\tInterospection : "; cin >> stu_list[i].marks[2];}
        // Test
        // stu_list[i].f_name[0] = char(rand() % 26 + 65); stu_list[i].l_name[0] = char(rand() % 26 + 65);
        // stu_list[i].f_name[1] = (stu_list[i].l_name[1] = '\0');
        // stu_list[i].marks[0] = rand();
        // stu_list[i].marks[1] = rand();
        // stu_list[i].marks[2] = rand();
    }
    
    // Sort here
    sortBySelection(stu_list, no_stu, false);
    
    
    cout << "\n\n";
    char full_name[66];
    // Print the ranks
    for (int i = 0, offset = 0; i < no_stu; ++i) {
        strcpy(full_name, (stu_list[i].l_name) );
        strcat(full_name, (", ") );
        strcat(full_name, (stu_list[i].f_name) ); 
        cout << setw(3) << (i + 1 - offset) << ". " << setw(66) << full_name << "  " << setw(4) << stu_list[i].total() << setw(3) << stu_list[i].grade() << endl;
        if ((i + 1) != no_stu and stu_list[i].total() == stu_list[i + 1].total()) ++offset;
        else offset = 0;
        
        // cout << stu_list[i].l_name << ", " << stu_list[i].f_name << "   " << stu_list[i].total() << "   " << (i + 1) - offset << endl;
        // if ((i + 1) != no_stu and stu_list[i].total() == stu_list[i + 1].total()) ++offset;
        // else offset = 0;
    }
    
    //Wait for input to exit
    {while (getchar() != '\n');
    getchar();}
}
