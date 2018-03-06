/** @file include/color.h
 *  contains class to store RGBA value of pixel
 *  with basic functions to add, subtract multiply and divide
 *  2 color values or color value with constant
 */

#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    Color(float r = 1, float g = 1, float b = 1, float a = 1) : R(r), G(g), B(b), A(a){}

    Color operator +(const Color &c) const;
    Color operator -(const Color &c) const;
    Color operator *(float f) const;
    Color operator +(float f) const;

//private: //member variables should have been made private
    float R, G, B, A;
};

#endif // COLOR_H
