#include <stdio.h>
#define MAX 100
#define FO "Data.out"

// Hàm nhập mảng một chiều
void NhapMang1C(int a[], int &n)
{
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    while (n <= 0 || n > MAX)
    {
        printf("So luong khong hop le! Nhap lai: ");
        scanf("%d", &n);
    }

    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// Hàm ghi mảng vào file
void OutputData(int a[], int n)
{
    FILE *fo;
    fo = fopen(FO, "wt"); // Sửa lỗi biến 'fi'
    if (fo == NULL)
    {
        printf("Khong the tao file\n");
        return;
    }

    fprintf(fo, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(fo, "%d\n", a[i]);

    fclose(fo);
    printf("Ghi file thanh cong!\n");
}

int main()
{
    int a[MAX];
    int n;

    NhapMang1C(a, n);
    OutputData(a, n);

    return 0;
}
