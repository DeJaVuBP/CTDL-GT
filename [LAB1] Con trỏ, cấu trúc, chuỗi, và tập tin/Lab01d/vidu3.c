#include <stdio.h>
#include <string.h>
#include <ctype.h>

void DemSoTu(char *s)
{
    int len = strlen(s);
    int i, dau = -1, cuoi = -1, soTu = 0;

    printf("Cac tu trong chuoi: ");

    for (i = 0; i < len; i++)
    {
        // Nếu là ký tự đầu của một từ
        if (!isspace(s[i]) && (i == 0 || isspace(s[i - 1])))
        {
            dau = i;
        }

        // Nếu là ký tự cuối của một từ
        if (!isspace(s[i]) && (i == len - 1 || isspace(s[i + 1])))
        {
            cuoi = i;
            soTu++;

            // In từ vừa tìm được
            printf("\"");
            for (int j = dau; j <= cuoi; j++)
            {
                printf("%c", s[j]);
            }
            printf("\", ");
        }
    }

    printf("\nChuoi \"%s\" co %d tu.\n", s, soTu);
}

int main()
{
    char s[1001]; // Định nghĩa mảng có thể chứa chuỗi tối đa 1000 ký tự
    printf("Moi ban nhap chuoi s: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng nếu có

    DemSoTu(s);
    return 0;
}
