#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"
#include "matrix.h"
#include "obj_parser.h"

class Camera
{
public:
    Camera();
    Camera(Vector_3d lookFrom, Vector_3d lookAt, Vector_3d lookUp);

    void setParameters(Vector_3d lookFrom, Vector_3d lookAt, Vector_3d lookUp);

    Matrix generateRotationMatrix();
    Vector_3d get_lookfrom_point();

    void set_lookfrom_point(Vector_3d);
    void set_lookat_point(Vector_3d);

    void render(Object* objs, int total_objects);

private:
    Vector_3d lookfrom_point;
    Vector_3d lookat_point;
    Vector_3d lookup_vector;
};

#endif // CAMERA_H
