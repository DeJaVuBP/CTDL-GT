#include <stdio.h>
#include <string.h>

// Hàm chèn ký tự vào vị trí k
void ChenKyTuTaiViTri(char *s, int k, char c)
{
    int len = strlen(s);

    // Kiểm tra vị trí hợp lệ
    if (k < 0 || k > len)
    {
        printf("Vi tri khong hop le!\n");
        return;
    }

    // Dịch các ký tự sang phải để tạo khoảng trống
    for (int i = len; i >= k; i--)
    {
        s[i + 1] = s[i];
    }

    // Chèn ký tự c vào vị trí k
    s[k] = c;
}

// Hàm main
int main()
{
    char s[1002]; // Giới hạn chuỗi tối đa 1001 ký tự (1000 + 1 cho '\0')
    int k;
    char c;

    // Nhập chuỗi
    printf("Moi ban nhap chuoi s: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng nếu có

    // Nhập vị trí cần chèn
    printf("Moi ban nhap vi tri can chen: ");
    scanf("%d", &k);

    // Nhập ký tự cần chèn
    printf("Moi ban nhap ky tu chen: ");
    scanf(" %c", &c); // Khoảng trắng trước %c để bỏ qua ký tự xuống dòng còn lại trong bộ đệm

    // Gọi hàm chèn ký tự
    ChenKyTuTaiViTri(s, k, c);

    // Xuất chuỗi sau khi chèn
    printf("Chuoi sau khi them ky tu \"%c\" vao vi tri %d: %s\n", c, k, s);

    return 0;
}
