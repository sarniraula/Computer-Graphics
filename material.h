#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

class Material
{
public:
    Material(float k_d = .7, float k_s = .1, float n_s = 10, Color c = Color(.5,.5,.5));
    void set_param(float k_d, float k_s, float n_s, Color c);

    float diffuse_coeff;
    float specular_coeff;
    float reflecion_param;

    Color color;
};

#endif // MATERIAL_H
