#include "surface_rendering.h"
#include "pixel_plot.h"

extern Light bulb;
extern Camera cam1;

void Display::DrawSpan(const Span &span, int y) {
    int xdiff = span.X2 - span.X1;
    if (xdiff == 0)
        return;

    Color colordiff = span.Color2 - span.Color1;

    float factor = 0.0f;
    float factorStep = 1.0f / (float) xdiff;
    // draw each pixel in the span
    for (int x = span.X1; x < span.X2; x++) {
        depth = (-D-A*x-B*y)/C;
        if((x<=WINDOW_X/2 && x>=-WINDOW_X/2) && (y<=WINDOW_Y/2 && y>=-WINDOW_Y/2))
        {
            if(depth  < z[x+600][y+350]){
                z[x+600][y+350]=depth;
                setPixel(x, y,span.Color1 + (colordiff * factor));
            }
            else
                ;
            factor += factorStep;
        }

    }
}

void Display::clearZbuffer(){
    for(int i=0;i<1200;i++)
    {
        for(int j=0;j<700;j++)
        {
            z[i][j]=999;
        }
    }
}

void Display::DrawSpansBetweenEdges(const Edge &e1, const Edge &e2) {
    // calculate difference between the y coordinates
    // of the first edge and return if 0

    float e1ydiff = (float) (e1.Y2 - e1.Y1);
    if (e1ydiff == 0.0f)
        return;

    // calculate difference between the y coordinates
    // of the second edge and return if 0
    float e2ydiff = (float) (e2.Y2 - e2.Y1);
    if (e2ydiff == 0.0f)
        return;

    // calculate differences between the x coordinates
    // and colors of the points of the edges
    float e1xdiff = (float) (e1.X2 - e1.X1);
    float e2xdiff = (float) (e2.X2 - e2.X1);
    Color e1colordiff = (e1.Color2 - e1.Color1);
    Color e2colordiff = (e2.Color2 - e2.Color1);

    // calculate factors to use for interpolation
    // with the edges and the step values to increase
    // them by after drawing each span
    float factor1 = (float) (e2.Y1 - e1.Y1) / e1ydiff;
    float factorStep1 = 1.0f / e1ydiff;
    float factor2 = 0.0f;
    float factorStep2 = 1.0f / e2ydiff;

    // loop through the lines between the edges and draw spans
    for (int y = e2.Y1; y < e2.Y2; y++) {
        // create and draw span
        Span span(e1.X1 + (int) (e1xdiff * factor1),e1.Color1 + (e1colordiff * factor1),
                  e2.X1 + (int) (e2xdiff * factor2),e2.Color1 + (e2colordiff * factor2));
        DrawSpan(span, y);

        // increase factors
        factor1 += factorStep1;
        factor2 += factorStep2;
    }
}

void Display::DrawTriangle(Vector_3d v1,const Color &color1,Vector_3d v2,const Color &color2
                              ,Vector_3d v3,const Color &color3) {



    Vector_3d c1 = project_point(v1, cam1);
    Vector_3d c2 = project_point(v2, cam1);
    Vector_3d c3 = project_point(v3, cam1);

    Vector_3d V1 = c2-c1;
    Vector_3d V2 = c3-c2;
    Vector_3d ABC = V1.crossProduct(V2);

     A = ABC.x;
     B = ABC.y;
     C = ABC.z;
     D = -A*c1.x-B*c1.y-C*c1.z;


    // create edges for the triangle
    Edge edges[3] = { Edge(c1,color1,c2,color2), Edge(c2,color2,c3,color3),Edge(c3,color3,c1,color1)};

    int maxLength = 0;
    int longEdge = 0;

    // find edge with the greatest length in the y axis
    for (int i = 0; i < 3; i++) {
        int length = edges[i].Y2 - edges[i].Y1;
        if (length > maxLength) {
            maxLength = length;
            longEdge = i;
        }
    }

    int shortEdge1 = (longEdge + 1) % 3;
    int shortEdge2 = (longEdge + 2) % 3;

    // draw spans between edges; the long edge can be drawn
    // with the shorter edges to draw the full triangle
    DrawSpansBetweenEdges(edges[longEdge], edges[shortEdge1]);
    DrawSpansBetweenEdges(edges[longEdge], edges[shortEdge2]);
}
