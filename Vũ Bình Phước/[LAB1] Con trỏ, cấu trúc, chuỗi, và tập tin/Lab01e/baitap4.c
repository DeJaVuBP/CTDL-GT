#include <stdio.h>
#include <stdlib.h>

#define MAX 10000
#define INPUT_FILE "CapSo.INP"
#define OUTPUT_FILE "CapSo.OUT"

// Hàm đọc dữ liệu từ file
void DocDuLieu(int a[], int *n, int *k)
{
    FILE *fi = fopen(INPUT_FILE, "r");
    if (fi == NULL)
    {
        printf("Khong the mo file %s!\n", INPUT_FILE);
        exit(1);
    }

    fscanf(fi, "%d %d", n, k);
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

// Hàm tìm và ghi cặp số có tổng bằng k
void TimCapSo(int a[], int n, int k)
{
    FILE *fo = fopen(OUTPUT_FILE, "w");
    if (fo == NULL)
    {
        printf("Khong the tao file %s!\n", OUTPUT_FILE);
        exit(1);
    }

    int timThay = 0;

    // Duyệt tất cả các cặp số (ai, aj) với i < j
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == k)
            {
                fprintf(fo, "%d %d\n", a[i], a[j]);
                timThay = 1;
            }
        }
    }

    // Nếu không tìm thấy cặp số nào, ghi 0 vào file
    if (!timThay)
    {
        fprintf(fo, "0\n");
    }

    fclose(fo);
}

// Chương trình chính
int main()
{
    int a[MAX], n, k;

    DocDuLieu(a, &n, &k);
    TimCapSo(a, n, k);

    printf("Ket qua da duoc ghi vao file %s\n", OUTPUT_FILE);
    return 0;
}
