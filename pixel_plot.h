/** @file/pixel_plot.h
 *  function to plot the pixel at supplied coordinate position in screen
 *  with provided color value
 */

#ifndef PIXEL_PLOT_H
#define PIXEL_PLOT_H

#include <GL/glut.h>
#include <GL/gl.h>

#include "color.h"

#define White Color(1.0,1.0,1.0,1.0)

void setPixel(float x,float y,float r=1.0,float g=1.0,float b=1.0);
void setPixel(float x, float y,Color c);

#endif // PIXEL_PLOT_H
