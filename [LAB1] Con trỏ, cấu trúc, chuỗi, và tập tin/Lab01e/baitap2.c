#include <stdio.h>
#define MAX 100
#define FILE_NAME "MangSo.inp"

// Hàm đọc mảng 2 chiều từ file
void DocMangTuFile(int a[MAX][MAX], int *n, int *m)
{
    FILE *fi = fopen(FILE_NAME, "r");
    if (fi == NULL)
    {
        printf("Khong the mo file!\n");
        return;
    }

    // Đọc số dòng và số cột
    fscanf(fi, "%d %d", n, m);
    if (*n <= 0 || *n > MAX || *m <= 0 || *m > MAX)
    {
        printf("Kich thuoc mang khong hop le!\n");
        fclose(fi);
        return;
    }

    // Đọc n dòng, mỗi dòng có m số nguyên
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            fscanf(fi, "%d", &a[i][j]);
        }
    }

    fclose(fi);
}

// Hàm xuất mảng 2 chiều ra màn hình
void XuatMang(int a[MAX][MAX], int n, int m)
{
    printf("Mang 2 chieu doc duoc tu file:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Chương trình chính
int main()
{
    int a[MAX][MAX], n, m;

    DocMangTuFile(a, &n, &m);
    XuatMang(a, n, m);

    return 0;
}
