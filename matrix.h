#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <vector>
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

        friend ostream& operator<<(ostream& os, const Matrix& s);

    private:
        vector<vector<double>> data;
        int rows, cols;

};

Matrix operator+(const Matrix l, const Matrix r);
Matrix operator*(const Matrix l, const Matrix r);

#endif