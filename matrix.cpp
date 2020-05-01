#include "matrix.h"
#include <string>
#include <sstream>

using namespace std;

Matrix::Matrix() {
    buildMatrix();
}

Matrix::Matrix(vector<vector<double>> entries) {
    data = entries;
    rows = data.size();
    if (data.size()) {
        cols = data[0].size();
    } else {
        cols = 0;
    }
}

Matrix Matrix::operator+=(const Matrix m) {
    return *this + m;
}

Matrix Matrix::operator*=(const double constant) {
    for (auto rowIt = data.begin(); rowIt != data.end(); rowIt++) {
        for (auto colIt = rowIt->begin(); colIt != rowIt->end(); colIt++) {
            *colIt *= constant;
        }
    }
    return *this;
}

vector<double>& Matrix::operator[](int i) {
    return data[i];
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

Matrix operator+(Matrix l, Matrix r) {
    if (!l.sameSize(r)) {
        cout << "ERROR: can only add matrices with the same dimensions" << endl;
        return l;
    }
    vector<vector<double>> data;
    for (int i = 0; i < l.numRows(); i++) {
        vector<double> row;
        for (int j = 0; j < l.numCols(); j++) {
            row.push_back(l[i][j] + r[i][j]);
        }
        data.push_back(row);
    }
    return Matrix(data);
}

Matrix operator*(Matrix l, Matrix r) {
    if (!l.oppositeSize(r)) {
        cout << "ERROR: can only multiply matrices with opposite dimensions" << endl;
        return l;
    }
    vector<vector<double>> data;
    for (int i = 0; i < l.numRows(); i++) {
        vector<double> row;
        for (int j = 0; j < r.numCols(); j++) {
            int dotProduct = 0;
            for (int comp = 0; comp < l.numCols(); comp++) {
                dotProduct += (l[i][comp] * r[comp][j]);
            }
            row.push_back(dotProduct);
        }
        data.push_back(row);
    }
    return Matrix(data);
}

void Matrix::buildMatrix() {
    cout << "Please enter the entries of the matrix row by row." << endl;
    cout << "Remember to separate each entry with a space, and press enter to move onto the next row." << endl;
    cout << "When you're finished, enter [d]." << endl;

    string line;
    int numCols;
    while (1) {
        while (2) {
            int noError = 1;
            cout << "Entering row " << data.size() + 1 << ": ";
            getline(cin, line);
            if (line.compare("d") == 0) {
                break;
            }
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
                    noError = 0;
                }
            }
            if (data.size() == 0) {
                numCols = row.size();
            } 
            if (row.size() != numCols && noError) {
                cout << "Oops! All rows must be length " << numCols << endl;
            } else if (noError) {
                data.push_back(row);
            }
        }
        cout << "Is this the correct matrix?" << endl;
        cout << "Press [n] to re-enter the matrix, or anything to continue" << endl;
        cout << *this;
        getline(cin, line);
        if (line.compare("n") != 0) {
            break;
        }
        data.clear();
    }      
    rows = data.size();
    cols = numCols;
}