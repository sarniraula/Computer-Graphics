#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>
#include <cmath>
#include "color.h"

const int PI = 3.141529;

class Vector_3d;

class Vector_2d //2D vector; Also used for storing 2D coordinate in this case
{
public:
    float x, y, z, m;
    Vector_2d();
    Vector_2d(float,float,float c=1);
    Vector_2d(Vector_3d);
    Vector_2d scale(float);

    float dotProduct(Vector_2d v);
    Vector_2d crossProduct(Vector_2d v);
    Vector_2d getUnitVector();
    Vector_2d operator +(const Vector_2d &c) const;
    Vector_2d operator -(const Vector_2d &c) const;

    void display(){
        std::cout<<"("<<x<<","<<y<<","<<")"<<std::endl;
    }
};

class Vector_3d //3D vector also used for storing 3D coordinate in this case
{
public:

    Vector_3d();

    Vector_3d(float, float, float, float d=1,Color c=Color(1,1,1,1));

    Vector_3d scale(float);

    float dotProduct(Vector_3d v);
    Vector_3d crossProduct(Vector_3d v);
    Vector_3d getUnitVector();
    Vector_3d operator +(const Vector_3d &c) const;
    Vector_3d operator -(const Vector_3d &c) const;
    Vector_3d operator /(float f) const;
    Vector_3d operator *(float f) const;

    void display(){
        std::cout<<"("<<x<<","<<y<<","<<z<<")"<<p<<std::endl;
    }

    float x, y, z, p;
    Color color;
    float magnitude;
};


#endif // VECTOR_H

