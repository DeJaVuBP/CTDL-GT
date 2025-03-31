#include <stdio.h>
#include <math.h>

// Hàm kiểm tra số chính phương
int isPerfectSquare(int *n)
{
    int sqrtN = (int)sqrt(*n);    // Tính căn bậc hai và ép kiểu về số nguyên
    return (sqrtN * sqrtN == *n); // Kiểm tra bình phương lại có bằng n không
}

int main()
{
    int n;
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    // Kiểm tra nếu n <= 0
    if (n <= 0)
    {
        printf("Vui lòng nhập số nguyên dương!\n");
        return 1; // Thoát chương trình với mã lỗi
    }

    // Kiểm tra số chính phương
    if (isPerfectSquare(&n))
    {
        printf("%d là số chính phương.\n", n);
    }
    else
    {
        printf("%d không phải là số chính phương.\n", n);
    }

    return 0;
}
