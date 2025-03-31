#include <stdio.h>
#include <string.h>

#define MAX 100

// Khai báo cấu trúc nhân viên
typedef struct
{
    char MaSo[11];
    char Ho[11];
    char Ten[51];
    int Phai; // 0: Nữ, 1: Nam
    int ThamNien;
} NhanVien;

// Khai báo cấu trúc phòng ban
typedef struct
{
    NhanVien aNhanVien[MAX];
    int SoLuong;
} PhongBan;

// Hàm nhập danh sách nhân viên
void NhapPhongBan(PhongBan *pb)
{
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &pb->SoLuong);
    while (pb->SoLuong <= 0 || pb->SoLuong > MAX)
    {
        printf("So luong khong hop le! Nhap lai: ");
        scanf("%d", &pb->SoLuong);
    }
    getchar(); // Xóa bộ nhớ đệm

    for (int i = 0; i < pb->SoLuong; i++)
    {
        printf("\nNhap thong tin nhan vien thu %d:\n", i + 1);
        printf("Ma so: ");
        fgets(pb->aNhanVien[i].MaSo, 11, stdin);
        strtok(pb->aNhanVien[i].MaSo, "\n");

        printf("Ho lot: ");
        fgets(pb->aNhanVien[i].Ho, 11, stdin);
        strtok(pb->aNhanVien[i].Ho, "\n");

        printf("Ten: ");
        fgets(pb->aNhanVien[i].Ten, 51, stdin);
        strtok(pb->aNhanVien[i].Ten, "\n");

        printf("Phai (0 - Nu, 1 - Nam): ");
        scanf("%d", &pb->aNhanVien[i].Phai);
        while (pb->aNhanVien[i].Phai != 0 && pb->aNhanVien[i].Phai != 1)
        {
            printf("Nhap sai! Moi nhap lai (0 - Nu, 1 - Nam): ");
            scanf("%d", &pb->aNhanVien[i].Phai);
        }

        printf("Tham nien: ");
        scanf("%d", &pb->aNhanVien[i].ThamNien);
        while (pb->aNhanVien[i].ThamNien < 0)
        {
            printf("Nhap sai! Moi nhap lai: ");
            scanf("%d", &pb->aNhanVien[i].ThamNien);
        }
        getchar(); // Xóa bộ nhớ đệm
    }
}

// Hàm xuất danh sách nhân viên
void XuatPhongBan(PhongBan pb)
{
    printf("\nDanh sach nhan vien trong phong ban:\n");
    printf("%-10s %-10s %-15s %-5s %-10s\n", "MaSo", "Ho", "Ten", "Phai", "ThamNien");
    for (int i = 0; i < pb.SoLuong; i++)
    {
        printf("%-10s %-10s %-15s %-5s %-10d\n",
               pb.aNhanVien[i].MaSo,
               pb.aNhanVien[i].Ho,
               pb.aNhanVien[i].Ten,
               pb.aNhanVien[i].Phai == 1 ? "Nam" : "Nu",
               pb.aNhanVien[i].ThamNien);
    }
}

// Hàm đếm sĩ số nhân viên nam và nữ
void DemSiSo(PhongBan pb, int *sonam, int *sonu)
{
    *sonam = 0;
    *sonu = 0;
    for (int i = 0; i < pb.SoLuong; i++)
    {
        if (pb.aNhanVien[i].Phai == 1)
        {
            (*sonam)++;
        }
        else
        {
            (*sonu)++;
        }
    }
}

// Hàm sắp xếp danh sách nhân viên theo thâm niên tăng dần
void SapXepTangTheoThamNien(PhongBan *pb)
{
    for (int i = 0; i < pb->SoLuong - 1; i++)
    {
        for (int j = i + 1; j < pb->SoLuong; j++)
        {
            if (pb->aNhanVien[i].ThamNien > pb->aNhanVien[j].ThamNien)
            {
                NhanVien temp = pb->aNhanVien[i];
                pb->aNhanVien[i] = pb->aNhanVien[j];
                pb->aNhanVien[j] = temp;
            }
        }
    }
}

// Hàm main
int main()
{
    PhongBan pb;
    int sonam, sonu;

    NhapPhongBan(&pb);
    XuatPhongBan(pb);

    DemSiSo(pb, &sonam, &sonu);
    printf("\nPhong ban co %d nam va %d nu.\n", sonam, sonu);

    printf("\nDanh sach nhan vien sau khi sap xep tang theo tham nien:\n");
    SapXepTangTheoThamNien(&pb);
    XuatPhongBan(pb);

    return 0;
}
