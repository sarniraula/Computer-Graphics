/** @file include/projection.h
 * Deals with projection of an object in the viewport
 * according to supplied camera information
 */

#ifndef PROJECTION_H
#define PROJECTION_H

#include "vector.h"
#include "camera.h"

Vector_3d project_point(Vector_3d P, Camera cam);

#endif // PROJECTION_H
