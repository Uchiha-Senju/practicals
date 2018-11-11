/*#####################################
##  
##  
##  
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
#include <string.h>
using namespace std;


struct Metric {
    float value;
    unsigned int mode;
    const string mode_id = ["picometer","nanometer","micrometer","millimeter", "centimeter", "meter", "kilometer"];
    const int mode_no = 7;
};

struct Imperial {
    float value;
    unsigned int mode;
    const string mode_id = ["inch","foot", "yard", "furlong", "mile"];
    const int mode_no = 5;
};

void convertMetric(Metric &length, unsigned int mode_f) {
    if (mode_f - length.mode > 0) 
        for (int i = 0; i < mode_f - length.mode; ++i) 
            switch (i + length.mode) {
                case 0: 
                case 1: 
                case 2: 
                case 5: length.value /= 1000;
                    break;
                case 3: length.value /= 10;
                    break;
                case 4: length.value /= 100;
                    break;
            }
    if (mode_f - length.mode < 0) 
        for (int i = 0; i > mode_f - length.mode; --i) 
            switch (i + length.mode) {
                case 1: 
                case 2: 
                case 3: 
                case 6: length.value *= 1000; break;
                case 4: length.value *= 10; break;
                case 5: length.value *= 100; break;
            }
    length.mode = mode_f % length.mode_no;
}

void convertImperial(Imperial &length, unsigned int mode_f) {
    if (mode_f - length.mode > 0) 
        for (int i = 0; i < mode_f - length.mode; ++i) 
            switch (i + length.mode) {
                case 0: length.value /= 12; break;
                case 1: length.value /= 3; break;
                case 2: length.value /= 220; break;
                case 3: length.value /= 8; break;
            }
    if (mode_f - length.mode < 0) 
        for (int i = 0; i > mode_f - length.mode; --i) 
            switch (i + length.mode) {
                case 1: length.value *= 12; break;
                case 2: length.value *= 3; break;
                case 3: length.value *= 220; break;
                case 4: length.value *= 8; break;
            }
    length.mode = mode_f % length.mode_no;
}

int main() {
    char choice, cont; int mode;
    cout << "Metric or Imperial (M/I)? "; cin >> choice;
    if (choice >= 'a' || choice <= 'z') choice -= 32;
    //set type of mode
    if (choice == 'M') {
        Metric length;
        cout << "Enter id of starting unit (";
        for (int i = 0; i < length.mode_no; ++i) {
            cout << i << " - " << length.mode_id[i] << (i == length.mode_no - 1)?" ":", ";
        }
        cout << ") : "; cin >> length.mode;
        // mode input validation
        if (length.mode < 0) length.mode *= -1;
        length.mode &= length.mode_no;
        
        cout << "Enter value of the unit : "; cin >> length.value;
        
        cout << "\nValue is : " << length.value << " " << length.mode_id[length.mode]; 
        // Convert
        while (true) {
            cout << "Enter id of the unit to be converted to (";
            for (int i = 0; i < length.mode_no; ++i) {
                cout << i << " - " << length.mode_id[i] << (i == length.mode_no - 1)?" ":", ";
            }
            cout << ") : "; cin >> mode;
            if (mode < 0) mode *= -1;
            mode &= length.mode_no;
            convertMetric(length, mode);
            cout << "\nConverted alue is : " << length.value << " " << length.mode_id[length.mode];
            
            cout << "Continue? "; cin >> cont;
            if (cont >= 'a' || cont <= 'z') cont -= 32;
            if (cont == 'N') break;
        }
    } else if (choice == 'I') {
        Imperial length;
        cout << "Enter id of starting unit (";
        for (int i = 0; i < length.mode_no; ++i) {
            cout << i << " - " << length.mode_id[i] << (i == length.mode_no - 1)?" ":", ";
        }
        cout << ") : "; cin >> length.mode;
        // mode input validation
        if (length.mode < 0) length.mode *= -1;
        length.mode &= length.mode_no;
        
        cout << "Enter value of the unit : "; cin >> length.value;
        
        cout << "\nValue is : " << length.value << " " << length.mode_id[length.mode]; 
        // Convert
        while (true) {
            cout << "Enter id of the unit to be converted to (";
            for (int i = 0; i < length.mode_no; ++i) {
                cout << i << " - " << length.mode_id[i] << (i == length.mode_no - 1)?" ":", ";
            }
            cout << ") : "; cin >> mode;
            if (mode < 0) mode *= -1;
            mode &= length.mode_no;
            convertImperial(length, mode);
            cout << "\nConverted alue is : " << length.value << " " << length.mode_id[length.mode];
            
            cout << "Continue? "; cin >> cont;
            if (cont >= 'a' || cont <= 'z') cont -= 32;
            if (cont == 'N') break;
        }
    } else return 1;
    
    while (getchar() != '\n');
    getchar();
}
