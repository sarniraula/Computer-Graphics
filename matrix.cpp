#include "matrix.h"

Matrix::Matrix()
{
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            m[i][j] = 0;
        }
    }
}

Matrix::Matrix(float mat[][ROWS])
{
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            m[i][j] = mat[i][j];
        }
    }
}

void Matrix::display()
{
    for(int i=0; i < COLUMNS; i++)
    {
        for(int j=0;j<ROWS;j++)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

Matrix Matrix::operator *(Matrix x) //matrix multiplication
{
    Matrix result;
    for(int i=0; i<COLUMNS; i++)
    {
        for(int j=0; j<ROWS; j++)
        {
            result.m[i][j] = 0;
            for(int k=0; k<COLUMNS; k++) // k < columns or rows?? check and correct
            {
                result.m[i][j]+=m[i][k]*x.m[k][j];
            }
        }
    }
    return(result);
}

const Vector_3d operator *(const Matrix &mat, const Vector_3d &p)
{
    float ar[4], tem[4], sum;
    ar[0] = p.x;
    ar[1] = p.y;
    ar[2] = p.z;
    ar[3] = p.p;

    for (int i = 0; i < 4; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += mat.m[i][j] * ar[j];
        }
        tem[i] = sum;
    }
    return (Vector_3d(tem[0], tem[1], tem[2], tem[3]));
}
