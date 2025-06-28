#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    double const pi = 3.14159;
    double const R = 3;
    double const r = 1.5;
    
    cout << "Coords: ";

    //basically, we have the OG coords as:
    // x = R*cos(phi)
    // y = R*sin(phi)
    // z = 0

    for(double rotation_angle = 0; rotation_angle < pi; rotation_angle += pi/180){ //animating rotate for 180 degrees around x axis
        for(double phi = 0; phi <= 2*pi; phi += pi/180){ 
            double x = R*cos(phi), y = R*sin(phi)*cos(rotation_angle) - 0*sin(rotation_angle), z = R*sin(phi)*sin(rotation_angle) + 0*cos(rotation_angle);
            for(double theta = 0; theta <= 2*pi; theta += pi/100){
                double u = r*cos(theta) + x, v = r*sin(theta) + y, w = 0; //TODO: change this, to compute the coordinates of a point in  3d space

                cout << "( " << u*cos(pi/2) << ", " << v << ", " << u * sin(pi/2) << " )";
            }
        }
    }
    
    return 0;
}
