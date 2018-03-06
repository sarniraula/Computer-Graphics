#include "color.h"

Color Color::operator +(const Color &c) const {
    return Color(R + c.R, G + c.G, B + c.B, A + c.A);
}

Color Color::operator -(const Color &c) const {
    return Color(R - c.R, G - c.G, B - c.B, A - c.A);
}

Color Color::operator *(float f) const {
    return Color(R * f, G * f, B * f, A * f);
}

Color Color::operator +(float f) const {
    return Color(R + f, G + f, B + f, A + f);
}

