#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"
#include <iostream>

const int ROWS = 4;
const int COLUMNS = 4;

class Matrix
{
public:
    Matrix();
    Matrix(float m[][ROWS]);
    void display();
    Matrix operator *(Matrix);

    friend const Vector_3d operator *(const Matrix &m,const Vector_3d &p);
private:
    float m[COLUMNS][ROWS];
};

#endif // MATRIX_H
