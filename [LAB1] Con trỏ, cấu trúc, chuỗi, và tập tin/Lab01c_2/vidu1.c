#include <stdio.h>
#include <string.h>

#define MAX 100

// Định nghĩa cấu trúc sách
typedef struct SachTag
{
    char maSach[11];
    char tenSach[21];
    int gia;
} Sach;

// Hàm nhập một quyển sách
void Nhap1QuyenSach(Sach *s)
{
    printf("Ma sach: ");
    scanf("%10s", s->maSach); // Đọc chuỗi an toàn
    getchar();                // Loại bỏ ký tự '\n' còn lại

    printf("Ten sach: ");
    fgets(s->tenSach, sizeof(s->tenSach), stdin);
    s->tenSach[strcspn(s->tenSach, "\n")] = '\0'; // Xóa ký tự '\n' cuối dòng

    printf("Gia: ");
    scanf("%d", &s->gia);
    getchar(); // Xóa bộ đệm sau khi nhập số
}

// Hàm xuất một quyển sách
void Xuat1QuyenSach(Sach s)
{
    printf("Ma sach: %s\n", s.maSach);
    printf("Ten sach: %s\n", s.tenSach);
    printf("Gia: %d\n", s.gia);
}

// Hàm nhập danh sách sách
void NhapMangSach(Sach a[], int *n)
{
    printf("Nhap so luong sach: ");
    scanf("%d", n);
    getchar(); // Xóa bộ đệm sau khi nhập số

    for (int i = 0; i < *n; i++)
    {
        printf("Nhap quyen sach thu %d:\n", i + 1);
        Nhap1QuyenSach(&a[i]);
    }
}

// Hàm tìm sách theo mã
int TimSachTheoMa(Sach a[], int n, char ma[], Sach *kq)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(ma, a[i].maSach) == 0)
        {
            *kq = a[i];
            return 1; // Tìm thấy
        }
    }
    return 0; // Không tìm thấy
}

int main()
{
    Sach a[MAX];
    int n;

    // Nhập danh sách sách
    NhapMangSach(a, &n);

    // Nhập mã sách cần tìm
    char ma[11];
    printf("Nhap ma sach muon tim: ");
    scanf("%10s", ma); // Nhập chuỗi an toàn

    // Tìm kiếm sách
    Sach kq;
    if (TimSachTheoMa(a, n, ma, &kq))
    {
        printf("Quyen sach tim duoc la:\n");
        Xuat1QuyenSach(kq);
    }
    else
    {
        printf("Khong tim thay quyen sach co ma da cho.\n");
    }

    return 0;
}
