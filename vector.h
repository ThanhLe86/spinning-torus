#ifndef __VECTOR__H__
#define __VECTOR__H__

#include <cmath>
#include <iostream> //just in case

class Vector {
public:
    double x, y, z = 0;
    Vector(double x, double y, double z) : x(x), y(y), z(z) {};
    
    //for 3D
    Vector computeNormal(Vector vecA, Vector vecB) { 

        //Refer to notes of Graphics series
        double normal_x = vecA.y*vecB.z - vecA.z*vecB.y;
        double normal_y = vecA.z*vecB.x - vecA.x*vecB.z;
        double normal_z = vecA.x*vecB.y - vecA.y*vecB.x;

        return Vector(normal_x, normal_y, normal_z);
    }

    Vector& operator+= (Vector vec2) {
        x += vec2.x;
        y += vec2.y;
        z += vec2.z;

        return *this;
    }

    Vector& operator-= (Vector vec2) {
        x -= vec2.x;
        y -= vec2.y;
        z -= vec2.z;

        return *this;
    }

    Vector& operator*= (double scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        
        return *this;
    }
};

#endif  //!__VECTOR__H__
