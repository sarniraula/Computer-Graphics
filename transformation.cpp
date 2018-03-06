#include "transformation.h"

Matrix translate(Vector_3d translation_vector)
{
    float translation[4][4] = {{1,0,0,translation_vector.x},{0,1,0,translation_vector.y},{0,0,1,translation_vector.z},{0,0,0,1}};
    Matrix T(translation);
    return (T);
}

Matrix rotate_xaxis(float angle)
{
    float thita = angle*PI/180;
    float rotation_x[4][4] = {{1,0,0,0},{0,(float)cos(thita),(float)-sin(thita),0},{0,(float)sin(thita),(float)cos(thita),0},{0,0,0,1}};
    return (Matrix(rotation_x));
}

Matrix rotate_yaxis(float angle)
{
    float thita = angle*PI/180;
    float rotation_y[4][4] = {{(float)cos(thita),0,(float)sin(thita),0},{0,1,0,0},{(float)-sin(thita),0,(float)cos(thita),0},{0,0,0,1}};
    return (Matrix(rotation_y));
}

Matrix rotate_zaxis(float angle)
{
    float thita = angle*PI/180;
    float rotation_z[4][4] = {{(float)cos(thita),(float)-sin(thita),0,0},{(float)sin(thita),(float)cos(thita),0,0},{0,0,1,0},{0,0,0,1}};
    return (Matrix(rotation_z));
}

Matrix scale(Vector_3d scaling_factor)
{
    float scaling[4][4] = {{scaling_factor.x,0,0,0},{0,scaling_factor.y,0,0},{0,0,scaling_factor.z},{0,0,0,1}};
    return (Matrix(scaling));
}
