#include "vertex.h"

Vertex::Vertex()
{

}

Edge::Edge(Vector_2d c1,const Color &color1,Vector_2d c2,const Color &color2){
    if (c1.y < c2.y) {
        Color1 = color1;
        X1 = c1.x; Y1 = c1.y; Z1 = c1.z;
        Color2 = color2;
        X2 = c2.x; Y2 = c2.y; Z2 = c2.z;
    } else {
        Color1 = color2;
        X1 = c2.x; Y1 = c2.y; Z1 = c2.z;
        Color2 = color1;
        X2 = c1.x; Y2 = c1.y; Z2 = c1.z;
    }
}

Edge::Edge(Vector_2d c1,Vector_2d c2){
    if (c1.y < c2.y) {
        X1 = c1.x; Y1 = c1.y; Z1 = c1.z;
        X2 = c2.x; Y2 = c2.y; Z2 = c2.z;
    } else {
        X1 = c2.x; Y1 = c2.y; Z1 = c2.z;
        X2 = c1.x; Y2 = c1.y; Z2 = c1.z;
    }
}

Span::Span( int x1,const Color &color1, int x2,const Color &color2) {
    if (x1 < x2) {
        Color1 = color1;
        X1 = x1;
        Color2 = color2;
        X2 = x2;
    } else {
        Color1 = color2;
        X1 = x2;
        Color2 = color1;
        X2 = x1;
    }
}

//faces

Faces::Faces(int a,int b,int c,int d):w(a),x(b),y(c),z(d){}
