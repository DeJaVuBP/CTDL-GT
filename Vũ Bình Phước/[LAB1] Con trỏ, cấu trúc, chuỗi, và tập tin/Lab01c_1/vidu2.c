#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct SachTag
{
    char maSach[11];
    char tenSach[21];
    int gia;
} Sach;

void Nhap1QuyenSach(Sach *s)
{
    printf("Ma sach: ");
    fgets(s->maSach, sizeof(s->maSach), stdin);
    s->maSach[strcspn(s->maSach, "\n")] = '\0'; // Xóa ký tự xuống dòng

    printf("Ten sach: ");
    fgets(s->tenSach, sizeof(s->tenSach), stdin);
    s->tenSach[strcspn(s->tenSach, "\n")] = '\0';

    printf("Gia: ");
    scanf("%d", &s->gia);
    while (getchar() != '\n')
        ; // Xóa bộ đệm đầu vào
}

void Xuat1QuyenSach(Sach s)
{
    printf("Ma sach: %s \n", s.maSach);
    printf("Ten sach: %s \n", s.tenSach);
    printf("Gia: %d \n", s.gia);
}

void NhapMangSach(Sach a[], int *n)
{
    printf("Nhap so luong sach: ");
    scanf("%d", n);
    getchar(); // Xóa ký tự '\n' còn sót lại

    for (int i = 0; i < *n; i++)
    {
        printf("Nhap quyen sach thu %d: \n", i);
        Nhap1QuyenSach(&a[i]);
    }
}

int TimSachTheoMa(Sach a[], int n, char ma[], Sach *kq)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(ma, a[i].maSach) == 0)
        {
            *kq = a[i];
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    Sach a[MAX];
    int n;

    NhapMangSach(a, &n);

    char ma[11];
    printf("Nhap ma sach muon tim: ");
    fgets(ma, sizeof(ma), stdin);
    ma[strcspn(ma, "\n")] = '\0';

    Sach kq;
    if (TimSachTheoMa(a, n, ma, &kq))
    {
        printf("Quyen sach tim duoc la: \n");
        Xuat1QuyenSach(kq);
    }
    else
    {
        printf("Khong tim thay quyen sach co ma da cho\n");
    }

    return 0;
}
