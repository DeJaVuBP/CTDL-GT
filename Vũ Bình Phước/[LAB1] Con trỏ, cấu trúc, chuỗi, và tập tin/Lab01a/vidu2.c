#include <stdio.h>
#include <stdlib.h>

// [1] Truyền tham trị (Pass by value)
void HoanVi_ThamTri(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// [2] Truyền tham chiếu bằng con trỏ (Pass by pointer)
void HoanVi_ThamChieu(int *a, int *b)
{
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}

int main()
{
    int x = 5, y = 10;

    // Trước khi hoán đổi
    printf("Trước khi hoán đổi: x=%d, y=%d\n", x, y);

    // Truyền tham trị (không thay đổi giá trị của x và y trong main)
    HoanVi_ThamTri(x, y);
    printf("Sau khi hoán đổi (tham trị): x=%d, y=%d\n", x, y);

    // Truyền tham chiếu bằng con trỏ (thay đổi giá trị của x và y trong main)
    HoanVi_ThamChieu(&x, &y);
    printf("Sau khi hoán đổi (tham chiếu): x=%d, y=%d\n", x, y);

    return 0;
}
