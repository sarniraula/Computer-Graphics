#include "camera.h"
#include "surface_rendering.h"

extern bool rendering;

Camera::Camera()
{
}

Camera::Camera(Vector_3d lookFrom, Vector_3d lookAt, Vector_3d lookUp)
{
    lookfrom_point = lookFrom;
    lookat_point = lookAt;
    lookup_vector = lookUp;
}

Matrix Camera::generateRotationMatrix()
{
    Vector_3d N = (lookfrom_point-lookat_point);
    Vector_3d n = N.getUnitVector();

    Vector_3d u = (lookup_vector.crossProduct(N)).getUnitVector();

    Vector_3d v = (n.crossProduct(u));
    float camera[4][4] = {{u.x,u.y,u.z,0},
                          {v.x,v.y,v.z,0},
                          {n.x,n.y,n.z,0},
                          {0,0,0,1}};
    Matrix R(camera);
    return R;
}

Vector_3d Camera::get_lookfrom_point()
{
    return this->lookfrom_point;
}

void Camera::set_lookfrom_point(Vector_3d p)
{
    this->lookfrom_point = p;
}

void Camera::set_lookat_point(Vector_3d p)
{
    this->lookat_point=p;
}

//trying to implement new rendering function
//void Camera::render(Color c, Object *objs, int total_objects)
//{
//    for(int i=0; i<total_objects; i++)
//        draw3D(objs[i].vertices,objs[i].total_face,objs[i].faces,objs[i].mesh,c);
//    rendering = false;
//}

void Camera::render(Object *objs, int total_objects)
{
    for(int i=0; i<total_objects; i++)
        draw3D(objs[i].vertices,objs[i].total_face,objs[i].faces, objs[i].mtl);
}
