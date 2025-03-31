#include <stdio.h>
#include <stdlib.h>
/*
Hoan vi hai so nguyen duong
+ Vao: &a, &b
+ Ra : *a, *b
+ Vi du: a[][MAXC] = {{1,2,3},{4,5,6}}, nd = 2, nc=3
*/
void HoanVi(int *a, int *b)
{
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}
int main()
{
    /* Khai bao bien */
    int x, y;
    /* Nhap du lieu */
    printf("Moi ban nhap so a: ");
    scanf("%d", &x);
    printf("Moi ban nhap so b: ");
    scanf("%d", &y);
    /* Xu ly*/
    printf("Truoc khi hoan vi, a = %d va b = %d.\n", x, y);
    HoanVi(&x, &y);
    printf("Sau khi hoan vi, a = %d va b = %d.\n", x, y);
    /* Dung man hinh xem ket qua */
    system("PAUSE");
    return 0;
} // main