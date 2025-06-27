#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    double const pi = 3.14159;
    double const R = 3;
    double const r = 1.5;
    
    cout << "Coords: ";
    for(double phi = 0; phi <= 2*pi; phi += pi/180)
    { 
        double x = R*cos(phi), y = R*sin(phi); 
        for(double theta = 0; theta <= 2*pi; theta += pi/100){
            double u = r*cos(theta) + x, v = r*sin(theta) + y, w = 0;
            cout << "( " << u*cos(pi/2) << ", " << v << ", " << u * sin(pi/2) << " )";
        }
       
    }
    return 0;
}
