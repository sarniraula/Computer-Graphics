#include "projection.h"
#include "transformation.h"

//perspective projection
Vector_3d project_point(Vector_3d point, Camera cam)
{
    float zprp = -5000; //projection reference point
    float zvp=0; //view plane
    float dp=zprp-zvp;

    Matrix T = translate(cam.get_lookfrom_point());
    Matrix R = cam.generateRotationMatrix();

    float h=(zprp-point.z)/dp;
    float perspective[4][4] = {{1/h,0,0,0},{0,1/h,0,0},{0,0,1,0},{0,0,0,1}};
    Matrix Tpersp(perspective);
    return (Tpersp*R*T*point);
}
