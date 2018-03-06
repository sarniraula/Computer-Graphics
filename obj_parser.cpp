#include "obj_parser.h"
#include "surface_rendering.h"
#include "light.h"

bool Object::load_obj_file(const char * filepath)
{
    int vertex_count=0, face_count=0, normal_count=0;
    Vector_3d vertex_normal[20000];
    Vector_3d vertex_sum(0,0,0);
    std::cout << "Loading OBJ file: " << filepath << std::endl;

    FILE * file = fopen(filepath, "r");
    if( file == NULL ){
        std::cout << "Cannot open the file: " << filepath << std::endl;
        return false;
    }

    while( 1 ){

        char lineHeader[128];
        // read the first word of the line
        bool quit = fscanf(file, "%s", lineHeader)==EOF?1:0;
        if (quit)
            break; // if end of file, break the loop.

        if ( strcmp( lineHeader, "v" ) == 0 ){
            Vector_3d vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            vertices[vertex_count].position = Vector_3d(vertex.x,vertex.y,vertex.z);
            vertex_sum = vertex_sum + vertices[vertex_count].position;
            vertex_count++;
        }
        else if (strcmp( lineHeader, "vn" ) == 0)
        {
            fscanf(file, "%f %f %f\n", &vertex_normal[normal_count].x, &vertex_normal[normal_count].y, &vertex_normal[normal_count].z );
            normal_count++;
        }
        else if (strcmp(lineHeader, "f") == 0){
            unsigned int vertexIndex[3];
            unsigned int normalIndex[3];
            fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], &vertexIndex[1],
                    &normalIndex[1], &vertexIndex[2], &normalIndex[2]);
            faces[face_count] = Faces((vertexIndex[0]-1),(vertexIndex[1]-1),(vertexIndex[2]-1));

            //trying to calculate average value of vertex normal
            for(int i=0; i<3; i++)
            {
                Vector_3d tmp = vertices[vertexIndex[i]-1].normal;
                tmp = (tmp + vertex_normal[normalIndex[i]-1])/2;
                vertices[vertexIndex[i]-1].normal = tmp;
            }
            face_count++;
        }
    }
    total_face = face_count;
    total_vertex=vertex_count;

    return true;
}

void Object::set_material(float k_d, float k_s, float n_s, Color c)
{
    mtl.diffuse_coeff = k_d;
    mtl.specular_coeff = k_s;
    mtl.reflecion_param = n_s;
    mtl.color = c;
}

