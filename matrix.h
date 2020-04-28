#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
using namespace std;

class Matrix {

    public:
        Matrix();
        ~Matrix();
        Matrix(const Matrix& m);
        Matrix& operator=(const Matrix m);

        int sameSize(const Matrix m);

        Matrix operator+=(const Matrix m);
        Matrix operator*=(const Matrix m);

    private:
        double** data;
        int rows, cols;

};

Matrix operator+(const Matrix l, const Matrix r);
Matrix operator*(const Matrix l, const Matrix r);

#endif