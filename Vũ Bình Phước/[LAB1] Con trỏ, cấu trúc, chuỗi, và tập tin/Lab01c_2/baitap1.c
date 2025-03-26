#include <stdio.h>
#include <string.h>

#define MAX 100

// Định nghĩa cấu trúc Điện thoại
typedef struct
{
    char maDT[11];     // Mã điện thoại (tối đa 10 ký tự)
    char nhanHieu[21]; // Nhãn hiệu (tối đa 20 ký tự)
    int gia;           // Giá
} DienThoai;

// Hàm thêm điện thoại vào danh sách
int ThemDienThoai(DienThoai ds[], int *n, DienThoai dt)
{
    if (*n >= MAX)
    {
        printf("Danh sach da day, khong the them dien thoai moi!\n");
        return 0;
    }

    // Kiểm tra trùng mã
    for (int i = 0; i < *n; i++)
    {
        if (strcmp(ds[i].maDT, dt.maDT) == 0)
        {
            printf("Dien thoai voi ma '%s' da ton tai!\n", dt.maDT);
            return 0;
        }
    }

    ds[*n] = dt;
    (*n)++;
    printf("Them dien thoai thanh cong!\n");
    return 1;
}

// Hàm tìm điện thoại theo mã
int TimDienThoai(DienThoai ds[], int n, char ma[], DienThoai *dt)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(ds[i].maDT, ma) == 0)
        {
            *dt = ds[i];
            return 1;
        }
    }
    return 0;
}

// Hàm cập nhật giá điện thoại theo mã
int CapNhatGia(DienThoai ds[], int n, char ma[], int giaMoi)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(ds[i].maDT, ma) == 0)
        {
            ds[i].gia = giaMoi;
            printf("Cap nhat gia thanh cong!\n");
            return 1;
        }
    }
    printf("Khong tim thay dien thoai voi ma '%s'!\n", ma);
    return 0;
}

// Hàm xóa điện thoại theo mã
int XoaDienThoai(DienThoai ds[], int *n, char ma[])
{
    for (int i = 0; i < *n; i++)
    {
        if (strcmp(ds[i].maDT, ma) == 0)
        {
            for (int j = i; j < *n - 1; j++)
            {
                ds[j] = ds[j + 1];
            }
            (*n)--;
            printf("Xoa dien thoai thanh cong!\n");
            return 1;
        }
    }
    printf("Khong tim thay dien thoai voi ma '%s'!\n", ma);
    return 0;
}

// Hàm xuất danh sách điện thoại
void XuatDanhSach(DienThoai ds[], int n)
{
    if (n == 0)
    {
        printf("Danh sach trong!\n");
        return;
    }
    printf("\nDANH SACH DIEN THOAI:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Ma: %s | Nhãn hiệu: %s | Gia: %d\n", ds[i].maDT, ds[i].nhanHieu, ds[i].gia);
    }
}

// Hàm hiển thị menu
void Menu()
{
    printf("\n========== MENU ==========\n");
    printf("1. Them dien thoai\n");
    printf("2. Tim dien thoai theo ma\n");
    printf("3. Cap nhat gia dien thoai\n");
    printf("4. Xoa dien thoai\n");
    printf("5. Xuat danh sach dien thoai\n");
    printf("0. Thoat chuong trinh\n");
    printf("==========================\n");
}

int main()
{
    DienThoai ds[MAX];
    int n = 0; // Số lượng điện thoại trong danh sách
    int luaChon;

    do
    {
        Menu();
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);
        getchar(); // Xóa bộ nhớ đệm sau scanf

        if (luaChon == 1)
        { // Thêm điện thoại
            DienThoai dt;
            printf("Nhap ma dien thoai: ");
            scanf("%10s", dt.maDT);
            getchar(); // Xóa '\n' trong buffer

            printf("Nhap nhan hieu: ");
            fgets(dt.nhanHieu, sizeof(dt.nhanHieu), stdin);
            dt.nhanHieu[strcspn(dt.nhanHieu, "\n")] = '\0'; // Xóa '\n'

            printf("Nhap gia: ");
            scanf("%d", &dt.gia);

            ThemDienThoai(ds, &n, dt);
        }
        else if (luaChon == 2)
        { // Tìm điện thoại theo mã
            char ma[11];
            printf("Nhap ma dien thoai can tim: ");
            scanf("%10s", ma);

            DienThoai dt;
            if (TimDienThoai(ds, n, ma, &dt))
            {
                printf("Thong tin dien thoai: Ma: %s | Nhãn hiệu: %s | Gia: %d\n", dt.maDT, dt.nhanHieu, dt.gia);
            }
            else
            {
                printf("Khong tim thay dien thoai voi ma '%s'!\n", ma);
            }
        }
        else if (luaChon == 3)
        { // Cập nhật giá
            char ma[11];
            int giaMoi;

            printf("Nhap ma dien thoai can cap nhat gia: ");
            scanf("%10s", ma);
            printf("Nhap gia moi: ");
            scanf("%d", &giaMoi);

            CapNhatGia(ds, n, ma, giaMoi);
        }
        else if (luaChon == 4)
        { // Xóa điện thoại
            char ma[11];
            printf("Nhap ma dien thoai can xoa: ");
            scanf("%10s", ma);

            XoaDienThoai(ds, &n, ma);
        }
        else if (luaChon == 5)
        { // Xuất danh sách
            XuatDanhSach(ds, n);
        }
        else if (luaChon == 0)
        {
            printf("Thoat chuong trinh.\n");
        }
        else
        {
            printf("Lua chon khong hop le, vui long chon lai!\n");
        }

    } while (luaChon != 0);

    return 0;
}
