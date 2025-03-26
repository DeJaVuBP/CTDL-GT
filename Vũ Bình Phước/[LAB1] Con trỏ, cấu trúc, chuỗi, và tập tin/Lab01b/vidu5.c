#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

// Hàm kiểm tra số nguyên tố
bool isPrime(int num)
{
    if (num < 2)
        return false;
    if (num == 2 || num == 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{
    int a[MAX], b[MAX], n, m = 0;
    int *pa = a, *pb = b; // Con trỏ trỏ đến mảng a và b

    // Nhập số phần tử
    printf("Nhập số phần tử của dãy (n ≤ 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Số phần tử không hợp lệ!\n");
        return 1;
    }

    // Nhập dãy số a
    printf("Nhập dãy số:\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", (pa + i)); // Dùng con trỏ nhập dữ liệu
    }

    // Tạo dãy b chứa số nguyên tố
    for (int i = 0; i < n; i++)
    {
        if (isPrime(*(pa + i)))
        {                          // Kiểm tra số nguyên tố
            *(pb + m) = *(pa + i); // Gán vào mảng b
            m++;
        }
    }

    // Xuất dãy b
    printf("\nDãy số nguyên tố:\n");
    if (m == 0)
    {
        printf("Không có số nguyên tố trong dãy!\n");
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", *(pb + i)); // Xuất dãy b bằng con trỏ
        }
        printf("\n");
    }

    return 0;
}
