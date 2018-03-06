#ifndef ILLUMINATION_H
#define ILLUMINATION_H

#include "light.h"
#include "vector.h"
#include "vertex.h"

#include <iostream>
using namespace std;

extern Camera cam1;
extern Light bulb;

Color get_vertex_color(Vertex vtx, Material mtl)
{
    float I_amb = .8;
    Vector_3d L = (bulb.position - vtx.position).getUnitVector();
    Vector_3d V = (cam1.get_lookfrom_point() - vtx.position).getUnitVector();
    Vector_3d H = (L + V).getUnitVector();
    Vector_3d N = vtx.normal.getUnitVector();

    float intensity = I_amb*mtl.diffuse_coeff +
            bulb.intensity*(mtl.diffuse_coeff*(N.dotProduct(L)));
             //+ mtl.specular_coeff*pow((N.dotProduct(H)),mtl.reflecion_param);

    return mtl.color*intensity;
}



#endif // ILLUMINATION_H
