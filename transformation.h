/** @file include/transformation.h
  * Return 4x4 transformation matrix according to the given parameters *
  */

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "matrix.h"


Matrix translate(Vector_3d translation_vector);

Matrix rotate_xaxis(float angle);
Matrix rotate_yaxis(float angle);
Matrix rotate_zaxis(float angle);

Matrix rotate_oaxis(Vector_3d c1,Vector_3d c2, float angle);

Matrix scale(Vector_3d scaling_factor);

#endif // TRANSFORMATION_H
