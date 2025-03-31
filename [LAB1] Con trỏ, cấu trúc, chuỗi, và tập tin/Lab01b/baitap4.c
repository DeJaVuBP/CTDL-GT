#include <stdio.h>

// Hàm trộn hai mảng tăng dần thành một mảng tăng dần
void tronMang(float *a, int n, float *b, int m, float *c, int *p)
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (*(a + i) < *(b + j))
        {
            *(c + k) = *(a + i);
            i++;
        }
        else
        {
            *(c + k) = *(b + j);
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng a
    while (i < n)
    {
        *(c + k) = *(a + i);
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng b
    while (j < m)
    {
        *(c + k) = *(b + j);
        j++;
        k++;
    }

    *p = k; // Cập nhật số lượng phần tử của mảng c
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

    float a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu %d: ", i);
        scanf("%f", a + i); // Nhập trực tiếp vào con trỏ
    }

    // Nhập số lượng phần tử của mảng b
    printf("+ Day so b\nMoi ban nhap so luong phan tu: ");
    scanf("%d", &m);

    if (m <= 0 || m > 100)
    {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    float b[m];
    for (int i = 0; i < m; i++)
    {
        printf("Phan tu %d: ", i);
        scanf("%f", b + i);
    }

    // Mảng c có tối đa n + m phần tử
    float c[n + m];

    // Gộp hai mảng vào mảng c
    tronMang(a, n, b, m, c, &p);

    // Xuất mảng c
    printf("+ Day so c\nDay so co %d phan tu: ", p);
    for (int i = 0; i < p; i++)
    {
        printf("%.1f ", *(c + i));
    }
    printf("\n");

    return 0;
}
