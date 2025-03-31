#include <stdio.h>
#include <ctype.h> // Thư viện xử lý ký tự

// Hàm kiểm tra ký tự có phải nguyên âm không
int laNguyenAm(char c)
{
    c = tolower(c); // Chuyển về chữ thường để kiểm tra
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Hàm lọc nguyên âm vào mảng b
void locNguyenAm(char *a, int n, char *b, int *m)
{
    *m = 0; // Số phần tử của mảng b ban đầu là 0
    for (int i = 0; i < n; i++)
    {
        if (laNguyenAm(*(a + i)))
        {
            *(b + (*m)) = *(a + i); // Thêm nguyên âm vào mảng b
            (*m)++;                 // Tăng số lượng phần tử của b
        }
    }
}

int main()
{
    int n;

    // Nhập số lượng phần tử
    printf("Moi ban nhap so luong phan tu: ");
    scanf("%d", &n);
    getchar(); // Loại bỏ ký tự xuống dòng sau khi nhập số

    // Kiểm tra điều kiện hợp lệ
    if (n <= 0 || n > 100)
    {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    char a[n], b[n]; // Mảng gốc và mảng chứa nguyên âm
    int m;           // Số lượng phần tử trong mảng b

    // Nhập dãy ký tự
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu %d: ", i);
        scanf("%c", a + i); // Nhập ký tự vào mảng bằng con trỏ
        getchar();          // Xử lý ký tự xuống dòng
    }

    // Lọc nguyên âm vào mảng b
    locNguyenAm(a, n, b, &m);

    // Xuất mảng b (các nguyên âm)
    printf("Cac ky tu nguyen am trong day: ");
    if (m == 0)
    {
        printf("Khong co ky tu nguyen am.");
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            printf("%c ", *(b + i));
        }
    }
    printf("\n");

    return 0;
}
