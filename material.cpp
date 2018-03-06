#include "material.h"

Material::Material(float k_d, float k_s, float n_s, Color c)
{
    diffuse_coeff = k_d;
    specular_coeff = k_s;
    reflecion_param = n_s;

    color = c;
}

void Material::set_param(float k_d, float k_s, float n_s, Color c)
{
    diffuse_coeff = k_d;
    specular_coeff = k_s;
    reflecion_param = n_s;

    color = c;
}
