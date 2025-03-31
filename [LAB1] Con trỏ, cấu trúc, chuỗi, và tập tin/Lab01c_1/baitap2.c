#include <stdio.h>
#include <string.h>

#define MAX 20

// Khai báo cấu trúc loại hoa
typedef struct
{
    char Ten[50];
    int SoLuong;
    char DVT[10];
    float DonGia;
} LoaiHoa;

// Khai báo danh sách loại hoa
typedef struct
{
    LoaiHoa dsHoa[MAX];
    int SoLuongHoa;
} DanhSachLoaiHoa;

// Hàm nhập danh sách loại hoa
void NhapDanhSach(DanhSachLoaiHoa *ds)
{
    printf("Nhap so luong loai hoa: ");
    scanf("%d", &ds->SoLuongHoa);
    while (ds->SoLuongHoa <= 0 || ds->SoLuongHoa > MAX)
    {
        printf("So luong khong hop le! Nhap lai: ");
        scanf("%d", &ds->SoLuongHoa);
    }
    getchar(); // Xóa bộ nhớ đệm

    for (int i = 0; i < ds->SoLuongHoa; i++)
    {
        printf("\nNhap thong tin loai hoa thu %d:\n", i + 1);
        printf("Ten loai: ");
        fgets(ds->dsHoa[i].Ten, 50, stdin);
        strtok(ds->dsHoa[i].Ten, "\n");

        printf("So luong: ");
        scanf("%d", &ds->dsHoa[i].SoLuong);

        printf("Don vi tinh: ");
        scanf("%s", ds->dsHoa[i].DVT);

        printf("Don gia: ");
        scanf("%f", &ds->dsHoa[i].DonGia);
        getchar();
    }
}

// Hàm xuất danh sách loại hoa
void XuatDanhSach(DanhSachLoaiHoa ds)
{
    printf("\nDanh sach loai hoa trong cua hang:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Ten loai", "So luong", "DVT", "Don gia");
    for (int i = 0; i < ds.SoLuongHoa; i++)
    {
        printf("%-20s %-10d %-10s %-10.2f\n",
               ds.dsHoa[i].Ten,
               ds.dsHoa[i].SoLuong,
               ds.dsHoa[i].DVT,
               ds.dsHoa[i].DonGia);
    }
}

// Hàm tìm loại hoa theo tên
int TimLoaiHoa(DanhSachLoaiHoa ds, char *tenloai)
{
    for (int i = 0; i < ds.SoLuongHoa; i++)
    {
        if (strcmp(ds.dsHoa[i].Ten, tenloai) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Hàm xử lý bán hoa
void XuLyBanHoa(DanhSachLoaiHoa *ds, char *tenloai, int soluong)
{
    int index = TimLoaiHoa(*ds, tenloai);
    if (index == -1)
    {
        printf("\nLoai hoa %s khong co trong cua hang.\n", tenloai);
    }
    else
    {
        if (ds->dsHoa[index].SoLuong >= soluong)
        {
            float tongTien = soluong * ds->dsHoa[index].DonGia;
            ds->dsHoa[index].SoLuong -= soluong;
            printf("\nBan thanh cong %d %s, tong tien: %.2f\n", soluong, ds->dsHoa[index].DVT, tongTien);
        }
        else
        {
            printf("\nKhong du so luong %s de ban!\n", tenloai);
        }
    }
}

// Hàm main
int main()
{
    DanhSachLoaiHoa ds;
    NhapDanhSach(&ds);
    XuatDanhSach(ds);

    char tenHoa[50];
    int soLuongMua;
    printf("\nNhap ten loai hoa can mua: ");
    fgets(tenHoa, 50, stdin);
    strtok(tenHoa, "\n");
    printf("Nhap so luong can mua: ");
    scanf("%d", &soLuongMua);

    XuLyBanHoa(&ds, tenHoa, soLuongMua);
    XuatDanhSach(ds);

    return 0;
}
