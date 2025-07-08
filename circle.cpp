#include <iostream>
#include <cmath>
#include <vector>
#include "Vector.h"
#include "console.h"

using namespace std;

int main(int argc, char const *argv[])
{
    console console;
    int viewPortWidth = console.getConsoleWidth();
    int viewPortHeight = console.getConsoleHeight();

    double const pi = 3.14159;
    double const torusRadius = 50;
    double const tubeRadius = 20;
    double const torusLocation = 150;

    vector<vector<char>> viewPort(viewPortWidth, vector<char>(viewPortHeight, ' '));

    cout << "Coords: ";
    for(double rotation_angle = 0; rotation_angle < 2*pi; rotation_angle += pi/180){
        console.clearConsole();
        for(double phi = 0; phi <= 2*pi; phi += pi/180){ 
            Vector mainCircle(torusRadius*cos(phi) + torusLocation, torusRadius*sin(phi) + torusLocation, 0);
            for(double theta = 0; theta <= 2*pi; theta += pi/180){
                Vector torusPoints(tubeRadius*cos(theta) + mainCircle.x, tubeRadius*sin(theta) + mainCircle.y, mainCircle.y + tubeRadius*sin(theta)); //before applying rotation
                //console.PrintToXY(torusPoints.x, torusPoints.y*cos(rotation_angle), 'o'); // #Needs improvement
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


