#include <stdio.h>
#define MAX 100
#define FILE_NAME "DaySoNguyen.inp"

// Hàm đọc mảng số nguyên từ file
void DocMangTuFile(int a[], int *n)
{
    FILE *fi = fopen(FILE_NAME, "r");
    if (fi == NULL)
    {
        printf("Khong the mo file!\n");
        return;
    }

    // Đọc số lượng phần tử n
    fscanf(fi, "%d", n);
    if (*n <= 0 || *n > MAX)
    {
        printf("So luong phan tu khong hop le!\n");
        fclose(fi);
        return;
    }

    // Đọc n số nguyên
    for (int i = 0; i < *n; i++)
    {
        fscanf(fi, "%d", &a[i]);
    }

    fclose(fi);
}

// Hàm xuất mảng ra màn hình
void XuatMang(int a[], int n)
{
    printf("Mang doc duoc tu file: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Chương trình chính
int main()
{
    int a[MAX], n;

    DocMangTuFile(a, &n);
    XuatMang(a, n);

    return 0;
}
