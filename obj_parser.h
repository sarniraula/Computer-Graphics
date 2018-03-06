/** @file include/obj_parser.h
 *  Parses the provided obj file and store required information
 *  (vertices, faces, face normals, vertex normals...) in the Object class
 */

#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#include <stdio.h>
#include <cstring>

#include "vector.h"
#include "material.h"
#include "vertex.h"


class Object
{
public:
    Vertex vertices[2000000]; //why waste space?! allocate memeory dynamically

    Faces faces[2000000];
    unsigned int total_face;
    unsigned int total_vertex;
    Material mtl;

    bool load_obj_file(const char * filepath);
    void set_material(float k_d = .7, float k_s = .1, float n_s = 10, Color c = Color(.5,.5,.5));

};

#endif // OBJ_PARSER_H
