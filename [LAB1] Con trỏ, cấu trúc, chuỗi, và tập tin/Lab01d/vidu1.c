#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000 // so luong ky tu toi da
/*
Kiem tra chuoi co chua ky tu so
+ Vao: chuoi s
+ Ra : co = 0 (khong co) / 1 (co
+ Vi du: *s = "abc12def" => co = 1
*/
int CoKyTuSo(char *s)
{
    int co;
    int len;
    len = strlen(s);                   // lay so ky tu chuoi s
    co = 0;                            // gia su chuoi s khong co chua ky tu
    for (int i = 0; i <= len - 1; i++) // duyet tu vi tri dau den cuoi
    {
        if (s[i] >= '0' && s[i] <= '9') // ky tu s[i] la ky tu so
        {
            co = 1; // bao hieu tim thay
            break;  // thoat lap
        } // if
    } // for
    return co;
} // CoKyTuSo
int main()
{
    /* Khai bao bien */
    char sChuoi[MAX + 1] = {0}; // khoi tao chuoi rong
    int kq;
    /* Nhap chuoi */
    printf("Moi ban nhap chuoi s: ");
    fflush(stdin); // xoa cache ban phim
    gets(sChuoi);
    /* Xu ly*/
    kq = CoKyTuSo(sChuoi);
    /* Xuat du lieu */
    printf("Chuoi \"%s\" co chua ky tu so.", sChuoi);
    /* Dung man hinh xem ket qua */
    system("PAUSE");
    return 0;
} // main