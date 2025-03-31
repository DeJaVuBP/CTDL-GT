#include <stdio.h>
#include <math.h>

// Hàm giải phương trình bậc hai, sử dụng con trỏ để trả kết quả
void giaiPTBacHai(double *a, double *b, double *c, double *x1, double *x2, int *soNghiem)
{
    // Trường hợp đặc biệt: a = 0 (phương trình bậc nhất hoặc vô nghiệm)
    if (*a == 0)
    {
        if (*b == 0)
        {
            *soNghiem = (*c == 0) ? -1 : 0; // -1: Vô số nghiệm, 0: Vô nghiệm
        }
        else
        {
            *soNghiem = 1;
            *x1 = -(*c) / (*b);
        }
        return;
    }

    // Tính biệt số Delta
    double delta = (*b) * (*b) - 4 * (*a) * (*c);

    if (delta < 0)
    {
        *soNghiem = 0; // Vô nghiệm
    }
    else if (delta == 0)
    {
        *soNghiem = 1; // Nghiệm kép
        *x1 = -(*b) / (2 * (*a));
    }
    else
    {
        *soNghiem = 2; // Hai nghiệm phân biệt
        *x1 = (-(*b) + sqrt(delta)) / (2 * (*a));
        *x2 = (-(*b) - sqrt(delta)) / (2 * (*a));
    }
}

int main()
{
    double a, b, c, x1, x2;
    int soNghiem;

    // Nhập hệ số a, b, c
    printf("Nhập hệ số a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Gọi hàm giải phương trình
    giaiPTBacHai(&a, &b, &c, &x1, &x2, &soNghiem);

    // Xuất kết quả
    if (soNghiem == -1)
    {
        printf("Phương trình có vô số nghiệm.\n");
    }
    else if (soNghiem == 0)
    {
        printf("Phương trình vô nghiệm.\n");
    }
    else if (soNghiem == 1)
    {
        printf("Phương trình có nghiệm duy nhất: x = %.2lf\n", x1);
    }
    else
    {
        printf("Phương trình có hai nghiệm phân biệt:\n");
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    }

    return 0;
}
