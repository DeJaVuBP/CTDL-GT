#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Hàm kiểm tra tính đan dấu
bool isAlternatingSign(double *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] * a[i + 1] >= 0) // Hai số cùng dấu
            return false;
    }
    return true;
}

// Hàm kiểm tra tính đơn điệu (tăng hoặc giảm)
bool isMonotonic(double *a, int n)
{
    bool increasing = true, decreasing = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            increasing = false;
        if (a[i] < a[i + 1])
            decreasing = false;
    }
    return increasing || decreasing;
}

// Hàm kiểm tra tính đối xứng
bool isSymmetric(double *a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    int n;
    double a[MAX];

    // Nhập số phần tử
    printf("Nhập số phần tử của dãy (n <= 100): ");
    scanf("%d", &n);

    // Kiểm tra giới hạn n
    if (n <= 0 || n > MAX)
    {
        printf("Số phần tử không hợp lệ!\n");
        return 1;
    }

    // Nhập mảng
    printf("Nhập dãy số:\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

    // Kiểm tra các tính chất
    printf("\nKiểm tra các tính chất của dãy số:\n");

    if (isAlternatingSign(a, n))
        printf("- Dãy có tính đan dấu.\n");
    else
        printf("- Dãy không có tính đan dấu.\n");

    if (isMonotonic(a, n))
        printf("- Dãy có tính đơn điệu.\n");
    else
        printf("- Dãy không có tính đơn điệu.\n");

    if (isSymmetric(a, n))
        printf("- Dãy có tính đối xứng.\n");
    else
        printf("- Dãy không có tính đối xứng.\n");

    return 0;
}
