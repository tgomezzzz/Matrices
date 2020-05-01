#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <vector>
using namespace std;

class Matrix {

    public:
        Matrix();
        Matrix(vector<vector<double>>);

        Matrix operator+=(const Matrix m);
        Matrix operator*=(const double constant);
        vector<double>& operator[](int i);

        friend ostream& operator<<(ostream& os, const Matrix& s);

        inline int numRows() {
            return rows;
        }

        inline int numCols() {
            return cols;
        }
        
        inline int sameSize(const Matrix m) {
            return rows == m.rows && cols == m.cols;
        }

        inline int oppositeSize(const Matrix m) {
            return rows == m.cols && cols == m.rows;
        }

    private:
        void buildMatrix();
        vector<vector<double>> data;
        int rows, cols;

};

Matrix operator+(Matrix l, Matrix r);
Matrix operator*(Matrix l, Matrix r);

#endif