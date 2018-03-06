#include "vector.h"

//2D vector
Vector_2d::Vector_2d() :x(0), y(0) {}
Vector_2d::Vector_2d(float a, float b,float c) :x(a), y(b) , z(c){}
Vector_2d::Vector_2d(Vector_3d p):x(p.x),y(p.y),z(p.z),m(sqrt(x*x+y*y+z*z)){}
Vector_2d Vector_2d::operator +(const Vector_2d &c) const {
    return Vector_2d(x + c.x, y + c.y, z + c.z);
}

Vector_2d Vector_2d::operator -(const Vector_2d &c) const {
    return Vector_2d(x - c.x, y - c.y, z - c.z);
}

Vector_2d Vector_2d::scale(float a)
{
    return (Vector_2d(a*x,a*y,a*z));
}

Vector_2d Vector_2d::crossProduct(Vector_2d v)
{
    return (Vector_2d(y*v.z-z*v.y  ,v.x*z-x*v.z  ,x*v.y-y*v.x));
}

Vector_2d Vector_2d::getUnitVector()
{
    return (Vector_2d(x/m,y/m,z/m));
}

float Vector_2d::dotProduct(Vector_2d v)
{
    return (float(x*v.x + y*v.y+ z*v.z));
}



Vector_3d::Vector_3d():x(0), y(0), z(0), p(1) ,magnitude(sqrt(x*x+y*y+z*z)){}
Vector_3d::Vector_3d(float a, float b, float c, float d,Color e)
    :x(a), y(b), z(c), p(d),color(e),magnitude(sqrt(x*x+y*y+z*z)) {}

Vector_3d Vector_3d::operator +(const Vector_3d &c) const {
    return Vector_3d(x + c.x, y + c.y, z + c.z);
}

Vector_3d Vector_3d::operator -(const Vector_3d &c) const {
    return Vector_3d(x - c.x, y - c.y, z - c.z);
}

Vector_3d Vector_3d::operator /(float f) const{
    return Vector_3d(x/f,y/f,z/f);
}

Vector_3d Vector_3d::operator *(float f) const
{
    return Vector_3d(x*f, y*f, z*f);
}




//3D vector

Vector_3d Vector_3d::scale(float a)
{
    return (Vector_3d(a*x,a*y,a*z));
}

Vector_3d Vector_3d::crossProduct(Vector_3d v)
{
    return (Vector_3d(y*v.z-z*v.y  ,v.x*z-x*v.z  ,x*v.y-y*v.x));
}

Vector_3d Vector_3d::getUnitVector()
{
    return (Vector_3d(x/magnitude,y/magnitude,z/magnitude));
}

float Vector_3d::dotProduct(Vector_3d v)
{
    return (float(x*v.x + y*v.y+ z*v.z));
}
