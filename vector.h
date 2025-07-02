#ifndef __VECTOR__H__
#define __VECTOR__H__

#include <cmath>
#include <iostream> //just in case

class vector {
public:
    double x, y, z = 0;
    vector(double x, double y, double z) : x(x), y(y), z(z) {};
    
    //for 3D
    vector computeNormal(vector vecA, vector vecB) { 

        //Refer to notes of Graphics series
        double normal_x = vecA.y*vecB.z - vecA.z*vecB.y;
        double normal_y = vecA.z*vecB.x - vecA.x*vecB.z;
        double normal_z = vecA.x*vecB.y - vecA.y*vecB.x;

        return vector(normal_x, normal_y, normal_z);
    }

    vector& operator+= (vector vec2) {
        x += vec2.x;
        y += vec2.y;
        z += vec2.z;

        return *this;
    }

    vector& operator-= (vector vec2) {
        x -= vec2.x;
        y -= vec2.y;
        z -= vec2.z;

        return *this;
    }

    vector& operator*= (double scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        
        return *this;
    }
};

#endif  //!__VECTOR__H__
