#include <stdio.h>
#define FI "Data.inp"

// Hàm đọc dữ liệu từ file
void inputData(int &n)
{
    FILE *fi;
    fi = fopen(FI, "rt");
    if (fi == NULL)
    {
        printf("Khong the doc file\n");
        return;
    }
    fscanf(fi, "%d", &n);
    fclose(fi);
}

int main()
{
    int n;
    inputData(n);
    printf("n = %d\n", n);
    return 0;
}
