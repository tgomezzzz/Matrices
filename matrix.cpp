#include "matrix.h"
#include <string>
#include <sstream>

using namespace std;

Matrix::Matrix() {
    buildMatrix();
}

Matrix::~Matrix() {
    cout << "destructor said fuck that bih" << endl;
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