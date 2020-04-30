#include "matrix.h"

using namespace std;

int main() {
    Matrix m;
    Matrix n;
    Matrix b(m);
    cout << b;
    b = n;
    cout << b;
    return 0;
}