#include <iostream>
#include <cmath>
#include "vector.h"

using namespace std;

int main(int argc, char const *argv[])
{
    double const pi = 3.14159;
    double const R = 3;
    double const r = 1.5;
    
    cout << "Coords: ";

    for(double rotation_angle = 0; rotation_angle < pi; rotation_angle += pi/180){ //animating rotate for 180 degrees around x axis
        for(double phi = 0; phi <= 2*pi; phi += pi/180){ 
            vector circlePoints(R*cos(phi), R*sin(phi)*cos(rotation_angle) - 0*sin(rotation_angle), R*sin(phi)*sin(rotation_angle) + 0*cos(rotation_angle));
            for(double theta = 0; theta <= 2*pi; theta += pi/100){
                vector torusPoints(circlePoints.x*cos(theta) + circlePoints.x, r*sin(theta) + circlePoints.y, 0); //TODO: change this, to compute the coordinates of a point in  3d space

                cout << "( " << torusPoints.x*cos(pi/2) << ", " << torusPoints.y << ", " << torusPoints.z * sin(pi/2) << " )";
            }
        }
    }
    
    return 0;
}


//TODO: properly document code in a markdown
//basically, we have the OG coords of the torus circle:
// x = R*cos(phi)
// y = R*sin(phi)
// z = 0

//phi: angle for rotating around the center 
//theta: angle for rotating around each point on the main torus circle
//rotation_angle: main rotation angle for rotating the entire torus
