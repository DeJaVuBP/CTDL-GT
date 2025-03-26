#include <stdio.h>

// Hàm tách mảng a thành mảng b (số chẵn) và mảng c (số lẻ)
void tachMang(int *a, int n, int *b, int *m, int *c, int *p)
{
    *m = 0; // Đếm số phần tử của mảng b (chẵn)
    *p = 0; // Đếm số phần tử của mảng c (lẻ)

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0)
        { // Nếu số chẵn
            *(b + *m) = *(a + i);
            (*m)++;
        }
        else
        { // Nếu số lẻ
            *(c + *p) = *(a + i);
            (*p)++;
        }
    }
}

int main()
{
    int n, m, p;

    // Nhập số lượng phần tử của mảng a
    printf("+ Day so a\nMoi ban nhap so luong phan tu: ");
    scanf("%d", &n);

    // Kiểm tra điều kiện hợp lệ
    if (n <= 0 || n > 100)
    {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    int a[n], b[n], c[n]; // Mảng b và c có thể chứa tối đa n phần tử

    // Nhập mảng a
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu %d: ", i);
        scanf("%d", a + i);
    }

    // Gọi hàm tách mảng
    tachMang(a, n, b, &m, c, &p);

    // Xuất mảng b (chứa số chẵn)
    printf("+ Day so b chua so chan\n");
    printf("Day so co %d phan tu: ", m);
    for (int i = 0; i < m; i++)
    {
        printf("%d ", *(b + i));
    }
    printf("\n");

    // Xuất mảng c (chứa số lẻ)
    printf("+ Day so c chua so le\n");
    printf("Day so co %d phan tu: ", p);
    for (int i = 0; i < p; i++)
    {
        printf("%d ", *(c + i));
    }
    printf("\n");

    return 0;
}
