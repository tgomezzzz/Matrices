#include "matrix.h"

using namespace std;

int main() {
    Matrix m;
    Matrix n;
    Matrix c = m * n;
    cout << m << endl;
    cout << n << endl;
    cout << c << endl;
    c *= 2.5;
    cout << c;
    return 0;
}