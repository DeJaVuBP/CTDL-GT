#include <stdio.h>
#include <string.h>

// Hàm hoán đổi 2 ký tự
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp chuỗi tăng dần
void SapXepChuoi(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (s[i] > s[j])
            {
                swap(&s[i], &s[j]);
            }
        }
    }
}

int main()
{
    char s[1001]; // Giới hạn chuỗi tối đa 1000 ký tự
    printf("Moi ban nhap chuoi s: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng nếu có

    SapXepChuoi(s);

    printf("Chuoi sau khi sap xep: %s\n", s);
    return 0;
}
