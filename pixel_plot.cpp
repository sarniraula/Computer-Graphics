#include "pixel_plot.h"

void setPixel(float x, float y, float r, float g, float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}
void setPixel(float x, float y,Color c)
{
    setPixel(x,y,c.R,c.G,c.B);
}

