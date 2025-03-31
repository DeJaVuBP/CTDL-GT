#include <stdio.h>
#include <string.h>

// Hàm xóa ký tự tại vị trí k
void XoaKyTuTaiViTri(char *s, int k)
{
    int len = strlen(s);

    // Kiểm tra vị trí hợp lệ
    if (k < 0 || k >= len)
    {
        printf("Vi tri khong hop le!\n");
        return;
    }

    // Dịch các ký tự sang trái từ vị trí k
    for (int i = k; i < len - 1; i++)
    {
        s[i] = s[i + 1];
    }
    s[len - 1] = '\0'; // Đặt ký tự kết thúc chuỗi
}

int main()
{
    char s[1001]; // Giới hạn chuỗi tối đa 1000 ký tự
    int k;

    // Nhập chuỗi
    printf("Moi ban nhap chuoi s: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng nếu có

    // Nhập vị trí cần xóa
    printf("Moi ban nhap vi tri can xoa: ");
    scanf("%d", &k);

    XoaKyTuTaiViTri(s, k);

    printf("Chuoi sau khi xoa ky tu tai vi tri %d: %s\n", k, s);

    return 0;
}
