/** @file include/light.h
 *  This file contains functions and class to define
 *  a light source in the scene
 */

// read the above info and make proper changes, amen

#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"
#include "surface_rendering.h"
#include "projection.h"
#include "obj_parser.h"
#include "camera.h"

class Light
{
public:
    Vector_3d position;
    Vector_3d fall_at;
    float intensity;
    Camera cam = Camera(position, fall_at, Vector_3d(0, 1, 0)); //light source as camera;

    Light(Vector_3d position, Vector_3d fall_at, float intensity = 0.5)
    {
        this->position = position;
        this->fall_at = fall_at;
        this->intensity = intensity;
    }

    void set_position(Vector_3d pos)
    {
        this->position = pos;
    }

    void set_intensity(float intensity)
    {
        this->intensity = intensity;
    }
};


void DrawTriangle(Vector_3d c1,Color color1,Vector_3d c2,Color color2,Vector_3d c3,Color color3);
void draw3D(Vertex Vertices[],int faces_size, Faces Faces[], Material mtl);

#endif // LIGHT_H
