#ifndef VERTEX_H
#define VERTEX_H

#include "vector.h"

class Vertex
{
public:
    Vertex();

    Vector_3d position;
    Vector_3d normal;
};

class Edge {
public:
    Color Color1, Color2;
    int X1, Y1, X2, Y2,Z1,Z2;
    Edge(Vector_2d c1,const Color &, Vector_2d c2,const Color &);
    Edge(Vector_2d c1, Vector_2d c2);
};

class Span {
public:
    Color Color1,Color2;
    int X1, X2 , Z1 , Z2;
    Span(int x1,const Color &color1, int x2,const Color &color2);
};

class Faces
{
public:
    int w,x,y,z;
    Faces(int a=0,int b=0,int c=0,int d=0);


    void display()
    {
        std::cout<<std::endl<<"("<<w<<","<<x<<","<<y<<","<<z<<")";
    }
};

#endif // VERTEX_H
