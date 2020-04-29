#include "matrix.h"
#include <string>
#include <sstream>

Matrix::Matrix() {
    cout << "Please enter the entries of the matrix row by row." << endl;
    cout << "Remember to separate each entry with a space, and press enter to move onto the next row." << endl;
    cout << "When you're finished, enter [d]." << endl;

    string line;
    int numCols;
    cout << "Entering row " << data.size() + 1 << ": ";
    getline(cin, line);
    while (line.compare("d")) {
        vector<double> row;
        stringstream ss(line);
        while (!ss.eof()){
            string token; 
            ss >> token;
            double num;
            if (stringstream(token) >> num) {
                row.push_back(num);
            } else {
                cout << "Oops! Entry '" << token << "' is invalid! (Only decimal values are accepted)" << endl;
                continue;
            }
        }
        if (data.size() == 0) {
            numCols = row.size();
        } 
        if (row.size() != numCols) {
            cout << "Oops! All rows must be length " << numCols << endl;
        } else {
            data.push_back(row);
        }
        cout << "Entering row " << data.size() + 1 << ": ";
        getline(cin, line);
    }

}

Matrix::~Matrix() {

}

Matrix::Matrix(const Matrix& m) {

}

Matrix& Matrix::operator=(const Matrix m) {

}

int Matrix::sameSize(const Matrix m) {

}

Matrix Matrix::operator+=(const Matrix m) {

}

Matrix Matrix::operator*=(const Matrix m) {

}

ostream& operator<<(ostream& os, const Matrix& m) {
    for (auto itRow = m.data.begin(); itRow != m.data.end(); itRow++) {
        os << "[";
        for (auto itCol = itRow->begin(); itCol != itRow->end(); itCol++) {
            os << *itCol;
            if (itCol != itRow->end() - 1) {
                os << " ";
            }
        }
        os << "]" << endl;
    }
    return os;
}

Matrix operator+(const Matrix l, const Matrix r) {

}
Matrix operator*(const Matrix l, const Matrix r) {

}