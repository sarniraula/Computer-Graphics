#include "light.h"
#include "obj_parser.h"
#include "camera.h"
#include "illumination.h"
#include "projection.h"

void draw3D(Vertex Vertices[],int faces_size, Faces Faces[], Material mtl)
{
    for(int i=0;i<faces_size;i++)
    {
        Color c1 = get_vertex_color(Vertices[Faces[i].w], mtl);
        Color c2 = get_vertex_color(Vertices[Faces[i].x], mtl);
        Color c3 = get_vertex_color(Vertices[Faces[i].y], mtl);

        extern Display r;
        r.DrawTriangle(Vertices[(int)Faces[i].w].position,c1,Vertices[(int)Faces[i].x].position
                , c2, Vertices[(int)Faces[i].y].position, c3);

    }
}
