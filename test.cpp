#include "matxlib.hpp"

int main()
{
    MATRIX *m = new MATRIX(3, 3);
    m->RandomizeMatrixInt(1, 10);
    m->PrintMatrix();
    delete m;
    return 0;
}