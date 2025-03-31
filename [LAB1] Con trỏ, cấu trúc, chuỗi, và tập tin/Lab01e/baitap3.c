#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define INPUT_FILE "NT.INP"
#define OUTPUT_FILE "NT.OUT"

// Hàm kiểm tra số nguyên tố
int LaSoNguyenTo(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Hàm đọc dữ liệu từ file
void DocDuLieu(int a[], int *n)
{
    FILE *fi = fopen(INPUT_FILE, "r");
    if (fi == NULL)
    {
        printf("Khong the mo file %s!\n", INPUT_FILE);
        exit(1);
    }

    fscanf(fi, "%d", n);
    if (*n <= 1 || *n > MAX)
    {
        printf("So luong phan tu khong hop le!\n");
        fclose(fi);
        exit(1);
    }

    for (int i = 0; i < *n; i++)
    {
        fscanf(fi, "%d", &a[i]);
    }

    fclose(fi);
}

// Hàm ghi kết quả ra file
void GhiKetQua(int prime[], int m)
{
    FILE *fo = fopen(OUTPUT_FILE, "w");
    if (fo == NULL)
    {
        printf("Khong the tao file %s!\n", OUTPUT_FILE);
        exit(1);
    }

    fprintf(fo, "%d\n", m);
    for (int i = 0; i < m; i++)
    {
        fprintf(fo, "%d ", prime[i]);
    }

    fclose(fo);
}

// Hàm tìm và lưu các số nguyên tố
void XuLySoNguyenTo(int a[], int n)
{
    int prime[MAX], m = 0;

    // Tìm số nguyên tố
    for (int i = 0; i < n; i++)
    {
        if (LaSoNguyenTo(a[i]))
        {
            prime[m++] = a[i];
        }
    }

    // Sắp xếp mảng số nguyên tố theo thứ tự tăng dần
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (prime[i] > prime[j])
            {
                int temp = prime[i];
                prime[i] = prime[j];
                prime[j] = temp;
            }
        }
    }

    // Ghi kết quả ra file
    GhiKetQua(prime, m);
}

// Chương trình chính
int main()
{
    int a[MAX], n;

    DocDuLieu(a, &n);
    XuLySoNguyenTo(a, n);

    printf("Ket qua da duoc ghi vao file %s\n", OUTPUT_FILE);
    return 0;
}
