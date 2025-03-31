#include <stdio.h>
#include <string.h>

#define MAX 50

struct HocSinh
{
    char MaSo[11], Ho[11], Ten[51];
    int Phai, NamSinh;
};

struct LopHoc
{
    HocSinh aHocSinh[MAX];
    int SoLuong;
};

void NhapLopHoc(LopHoc *lop)
{
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &lop->SoLuong);
    while (lop->SoLuong <= 0 || lop->SoLuong > MAX)
    {
        printf("Nhap sai! Nhap lai: ");
        scanf("%d", &lop->SoLuong);
    }
    getchar(); // Xóa ký tự '\n' sau scanf

    for (int i = 0; i < lop->SoLuong; i++)
    {
        printf("Nhap thong tin hoc sinh %d: \n", i + 1);

        printf("+ Ma so: ");
        fgets(lop->aHocSinh[i].MaSo, sizeof(lop->aHocSinh[i].MaSo), stdin);
        lop->aHocSinh[i].MaSo[strcspn(lop->aHocSinh[i].MaSo, "\n")] = '\0';

        printf("+ Ho lot: ");
        fgets(lop->aHocSinh[i].Ho, sizeof(lop->aHocSinh[i].Ho), stdin);
        lop->aHocSinh[i].Ho[strcspn(lop->aHocSinh[i].Ho, "\n")] = '\0';

        printf("+ Ten: ");
        fgets(lop->aHocSinh[i].Ten, sizeof(lop->aHocSinh[i].Ten), stdin);
        lop->aHocSinh[i].Ten[strcspn(lop->aHocSinh[i].Ten, "\n")] = '\0';

        printf("+ Phai (0: Nu, 1: Nam): ");
        scanf("%d", &lop->aHocSinh[i].Phai);
        getchar(); // Xóa bộ đệm nhập

        while (lop->aHocSinh[i].Phai != 0 && lop->aHocSinh[i].Phai != 1)
        {
            printf("+ Nhap sai! Nhap lai: ");
            scanf("%d", &lop->aHocSinh[i].Phai);
            getchar();
        }

        printf("+ Nam sinh: ");
        scanf("%d", &lop->aHocSinh[i].NamSinh);
        getchar();

        while (lop->aHocSinh[i].NamSinh <= 0)
        {
            printf("+ Nhap sai! Nhap lai: ");
            scanf("%d", &lop->aHocSinh[i].NamSinh);
            getchar();
        }
    }
}

void XuatLopHoc(LopHoc lop)
{
    printf("Lop hoc co %d hoc sinh: \n", lop.SoLuong);
    printf("STT\tMa so\tHo ten\t\tPhai\tNam sinh \n");

    for (int i = 0; i < lop.SoLuong; i++)
    {
        printf("%d\t%s\t%s %s\t", i + 1, lop.aHocSinh[i].MaSo, lop.aHocSinh[i].Ho, lop.aHocSinh[i].Ten);
        printf("%s\t%d\n", (lop.aHocSinh[i].Phai == 1) ? "Nam" : "Nu", lop.aHocSinh[i].NamSinh);
    }
}

void DemSiSo(LopHoc lop, int *sonam, int *sonu)
{
    *sonam = *sonu = 0;
    for (int i = 0; i < lop.SoLuong; i++)
    {
        if (lop.aHocSinh[i].Phai == 1)
            (*sonam)++;
        else
            (*sonu)++;
    }
}

void SapXepTangTheoNamSinh(LopHoc *lop)
{
    for (int i = 0; i < lop->SoLuong - 1; i++)
    {
        for (int j = i + 1; j < lop->SoLuong; j++)
        {
            if (lop->aHocSinh[i].NamSinh > lop->aHocSinh[j].NamSinh)
            {
                HocSinh tmp = lop->aHocSinh[i];
                lop->aHocSinh[i] = lop->aHocSinh[j];
                lop->aHocSinh[j] = tmp;
            }
        }
    }
}

int main()
{
    LopHoc lop = {
        {{"01", "Nguyen Van", "A", 1, 1984},
         {"02", "Tran Thi", "B", 0, 1982},
         {"03", "Le Duy", "C", 1, 1982}},
        3};

    int sonam, sonu;

    // NhapLopHoc(&lop);
    XuatLopHoc(lop);
    DemSiSo(lop, &sonam, &sonu);

    printf("+ Dem si so hoc sinh trong lop hoc: \n");
    printf("Lop co %d hoc sinh, trong do %d nam va %d nu.\n", lop.SoLuong, sonam, sonu);

    printf("+ Danh sach hoc sinh sau khi sap xep theo nam sinh:\n");
    SapXepTangTheoNamSinh(&lop);
    XuatLopHoc(lop);

    return 0;
}
