#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char MSMH[11];
    char TenMH[31];
    int SoLuong;
    float DonGia;
} MatHang;

void NhapDanhSach(MatHang ds[], int *n)
{
    printf("Nhap so luong mat hang: ");
    scanf("%d", n);
    getchar(); // Xóa bộ đệm

    for (int i = 0; i < *n; i++)
    {
        printf("Nhap thong tin mat hang thu %d:\n", i + 1);
        printf("Ma so mat hang: ");
        fgets(ds[i].MSMH, 11, stdin);
        ds[i].MSMH[strcspn(ds[i].MSMH, "\n")] = 0; // Xóa ký tự xuống dòng

        printf("Ten mat hang: ");
        fgets(ds[i].TenMH, 31, stdin);
        ds[i].TenMH[strcspn(ds[i].TenMH, "\n")] = 0;

        printf("So luong: ");
        scanf("%d", &ds[i].SoLuong);

        printf("Don gia: ");
        scanf("%f", &ds[i].DonGia);
        getchar(); // Xóa bộ đệm
    }
}

void TimKiemMatHang(MatHang ds[], int n)
{
    char ten[31];
    printf("Nhap ten mat hang can tim: ");
    fgets(ten, 31, stdin);
    ten[strcspn(ten, "\n")] = 0;

    int timThay = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(ds[i].TenMH, ten) == 0)
        {
            printf("\nThong tin mat hang:\n");
            printf("MSMH: %s\n", ds[i].MSMH);
            printf("TenMH: %s\n", ds[i].TenMH);
            printf("SoLuong: %d\n", ds[i].SoLuong);
            printf("DonGia: %.2f\n", ds[i].DonGia);
            timThay = 1;
            break;
        }
    }
    if (!timThay)
    {
        printf("Khong co mat hang dang tim.\n");
    }
}

void TinhTongSoLuong(MatHang ds[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += ds[i].SoLuong;
    }
    printf("Tong so luong cac mat hang: %d\n", tong);
}

int main()
{
    MatHang ds[MAX];
    int n, luaChon;

    do
    {
        printf("\n==== MENU ====\n");
        printf("1. Nhap danh sach mat hang\n");
        printf("2. Tim kiem mat hang theo ten\n");
        printf("3. Tinh tong so luong cac mat hang\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        getchar(); // Xóa bộ đệm

        switch (luaChon)
        {
        case 1:
            NhapDanhSach(ds, &n);
            break;
        case 2:
            TimKiemMatHang(ds, n);
            break;
        case 3:
            TinhTongSoLuong(ds, n);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 0);

    return 0;
}
