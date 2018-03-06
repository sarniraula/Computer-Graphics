//should contain rendering algorithms phong, fast phong or whatever else there is

#ifndef SURFACE_RENDERING_H
#define SURFACE_RENDERING_H

#include "color.h"
#include "vector.h"
#include "light.h"
#include "vertex.h"
#include "obj_parser.h"

#define WINDOW_X 1200
#define WINDOW_Y 700




class Display {
public:
    float A,B,C,D;
    Vector_2d n;
    float k;
    float depth;
    float z[WINDOW_X][WINDOW_Y];

    Display(){}
    void DrawSpan(const Span &span, int y);
    void DrawSpansBetweenEdges(const Edge &e1, const Edge &e2);
    void clearZbuffer();
    void DrawTriangle(Vector_3d,const Color &color1,Vector_3d,const Color &color2,Vector_3d,const Color &color3);
};


#endif // SURFACE_RENDERING_H
