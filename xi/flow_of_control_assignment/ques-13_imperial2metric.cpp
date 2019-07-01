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

enum MetricUnits {picometer,nanometer,micrometer,millimeter, centimeter, meter, kilometer};
enum ImperialUnits {inch,foot, yard, furlong, mile};

class Metric {
    public :
        float value;
        MetricUnits mode;
        void convert(MetricUnits mode_f) {
            if (mode_f - mode > 0) 
                for (int i = mode; i < mode_f; ++i) 
                    switch (i) {
                        case 0: 
                        case 1: 
                        case 2: 
                        case 5: value /= 1000;
                            break;
                        case 3: value /= 10;
                            break;
                        case 4: value /= 100;
                            break;
                    }
            if (mode_f - mode < 0) 
                for (int i = mode; i > mode_f; --i) 
                    switch (i) {
                        case 1: 
                        case 2: 
                        case 3: 
                        case 6: value *= 1000; break;
                        case 4: value *= 10; break;
                        case 5: value *= 100; break;
                    }
            mode = mode_f;
        }   
};

class Imperial {
    public :
        float value;
        ImperialUnits mode;
        void convert(ImperialUnits mode_f) {
            if (mode_f > mode) 
                for (int i = mode; i < mode_f; ++i) 
                    switch (i) {
                        case 0: value /= 12; break;
                        case 1: value /= 3; break;
                        case 2: value /= 220; break;
                        case 3: value /= 8; break;
                    }
            if (mode_f < mode) 
                for (int i = mode; i > mode_f; --i) 
                    switch (i) {
                        case 1: value *= 12; break;
                        case 2: value *= 3; break;
                        case 3: value *= 220; break;
                        case 4: value *= 8; break;
                    }
            mode = mode_f;
        }
};

Imperial convertToImperial(Metric met_len) {
    Imperial imp_len;
    met_len.convert(centimeter);
    imp_len.mode = inch;
    imp_len.value = met_len.value / 2.54;
    return imp_len;
}

Metric convertToMetric(Imperial imp_len) {
    Metric met_len;
    imp_len.convert(inch);
    met_len.mode = centimeter;
    met_len.value = imp_len.value * 2.54;
    return met_len;
}

int main() {
    char choice; int mode;
    Metric met_len;
    Imperial imp_len;
    cout << "Metric or Imperial (M/I)? "; cin >> choice;
    if (choice >= 'a' || choice <= 'z') choice -= 32;
    //set type of mode
    if (choice == 'M') {
        cout << "Enter id of starting unit (0 - picometer, 1 - nanometer, 2 - micrometer, 3 - millimeter,  4 - centimeter, 5 - meter,  6 - kilometer) : ";
        cin >> mode;
        met_len.mode = MetricUnits(mode); 
        cout << "Enter value of the unit : "; cin >> met_len.value;
        
        cout << "\nValue is : " << met_len.value; 
        // Convert
        cout << "\nEnter id of the imperial unit (0 - inch, 1 - foot, 2 - yard, 3 - furlong, 4 - mile) : ";
        cin >> mode;
        imp_len = convertToImperial(met_len);
        imp_len.convert(ImperialUnits(mode));
        cout << "\nConverted value is : " << imp_len.value;
    } else if (choice == 'I') {
        cout << "Enter id of starting unit (0 - inch, 1 - foot, 2 - yard, 3 - furlong, 4 - mile) : ";
        cin >> mode;
        imp_len.mode = ImperialUnits(mode); 
        cout << "Enter value of the unit : "; cin >> imp_len.value;
        
        cout << "\nValue is : " << imp_len.value; 
        // Convert
        cout << "\nEnter id of the imperial unit (0 - picometer, 1 - nanometer, 2 - micrometer, 3 - millimeter,  4 - centimeter, 5 - meter,  6 - kilometer) : ";
        cin >> mode;
        met_len = convertToMetric(imp_len);
        met_len.convert(MetricUnits(mode));
        cout << "\nConverted value is : " << met_len.value;
    } else return 1;
    
    while (getchar() != '\n');
    getchar();
}
