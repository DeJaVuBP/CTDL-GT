#include <stdio.h>
#include <math.h>

typedef struct
{
    int tuSo;
    int mauSo;
} PhanSo;

void NhapPhanSo(const char *info, PhanSo *ps)
{
    do
    {
        printf("%s", info);
        scanf("%d%d", &ps->tuSo, &ps->mauSo);
        if (ps->mauSo == 0)
        {
            printf("Mau so phai khac 0. Moi nhap lai!\n");
        }
    } while (ps->mauSo == 0);
}

void XuatPhanSo(PhanSo ps)
{
    if (ps.mauSo == 1)
    {
        printf("[%d]", ps.tuSo);
    }
    else
    {
        printf("[%d/%d]", ps.tuSo, ps.mauSo);
    }
}

int TimUCLN(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

void RutGonPhanSo(PhanSo *ps)
{
    int ucln = TimUCLN(ps->tuSo, ps->mauSo);
    ps->tuSo /= ucln;
    ps->mauSo /= ucln;
    if (ps->mauSo < 0)
    { // Đảm bảo mẫu số dương
        ps->tuSo = -ps->tuSo;
        ps->mauSo = -ps->mauSo;
    }
}

int SoSanhPhanSo(PhanSo p1, PhanSo p2)
{
    int vp1 = p1.tuSo * p2.mauSo;
    int vp2 = p2.tuSo * p1.mauSo;
    if (vp1 > vp2)
        return 1;
    if (vp1 == vp2)
        return 0;
    return -1;
}

void CongPhanSo(PhanSo p1, PhanSo p2, PhanSo *pret)
{
    pret->tuSo = p1.tuSo * p2.mauSo + p1.mauSo * p2.tuSo;
    pret->mauSo = p1.mauSo * p2.mauSo;
    RutGonPhanSo(pret);
}

int main()
{
    PhanSo p1, p2, pret;
    NhapPhanSo("Moi ban nhap phan so 1: ", &p1);
    NhapPhanSo("Moi ban nhap phan so 2: ", &p2);

    RutGonPhanSo(&p1);
    RutGonPhanSo(&p2);

    printf("+ Rut gon: ");
    XuatPhanSo(p1);
    printf(" ");
    XuatPhanSo(p2);
    printf("\n");

    char aDau[3] = {'<', '=', '>'};
    int ret = SoSanhPhanSo(p1, p2);
    printf("+ So sanh: ");
    XuatPhanSo(p1);
    printf(" %c ", aDau[ret + 1]);
    XuatPhanSo(p2);
    printf("\n");

    CongPhanSo(p1, p2, &pret);
    printf("+ Cong: ");
    XuatPhanSo(p1);
    printf(" + ");
    XuatPhanSo(p2);
    printf(" = ");
    XuatPhanSo(pret);
    printf("\n");

    return 0;
}
