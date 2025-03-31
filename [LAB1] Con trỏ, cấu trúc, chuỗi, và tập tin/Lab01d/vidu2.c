#include <stdio.h>
#include <string.h>

void KiemTraDoiXung(char *s)
{
    char *pDau = s;
    char *pCuoi = s + strlen(s) - 1;
    int doixung = 1; // Giả sử chuỗi đối xứng

    while (pDau < pCuoi)
    {
        if (*pDau != *pCuoi)
        {
            doixung = 0; // Không đối xứng
            break;
        }
        pDau++;
        pCuoi--;
    }

    if (doixung)
    {
        printf("Chuoi \"%s\" la doi xung.\n", s);
    }
    else
    {
        printf("Chuoi \"%s\" khong doi xung.\n", s);
    }
}

int main()
{
    char s[1001]; // Định nghĩa mảng có thể chứa chuỗi tối đa 1000 ký tự
    printf("Moi ban nhap chuoi s: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng nếu có

    KiemTraDoiXung(s);
    return 0;
}
