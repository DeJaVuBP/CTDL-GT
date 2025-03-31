#include <stdio.h>

// Hàm kiểm tra dãy có xen kẽ chẵn lẻ không (dùng con trỏ)
int kiemTraXenKeChanLe(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if ((*(arr + i) % 2) == (*(arr + i - 1) % 2))
        {
            return 0; // Nếu hai phần tử liên tiếp cùng chẵn hoặc cùng lẻ => Không thỏa mãn
        }
    }
    return 1; // Dãy xen kẽ chẵn lẻ
}

// Hàm kiểm tra dãy có toàn số chẵn không (dùng con trỏ)
int kiemTraToanChan(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) % 2 != 0)
        {
            return 0; // Nếu có ít nhất một số lẻ => Không phải dãy toàn chẵn
        }
    }
    return 1; // Dãy toàn chẵn
}

int main()
{
    int n;

    // Nhập số lượng phần tử
    printf("Moi ban nhap so luong phan tu: ");
    scanf("%d", &n);

    // Kiểm tra điều kiện hợp lệ
    if (n <= 0 || n > 100)
    {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    int arr[n];

    // Nhập dãy số
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu %d: ", i);
        scanf("%d", arr + i); // Nhập giá trị vào mảng bằng con trỏ
    }

    // Kiểm tra tính chẵn lẻ xen kẽ
    if (kiemTraXenKeChanLe(arr, n))
    {
        printf("+ Day co tinh chat chan le\n");
    }
    else
    {
        printf("+ Day khong co tinh chat chan le\n");
    }

    // Kiểm tra tính toàn chẵn
    if (kiemTraToanChan(arr, n))
    {
        printf("+ Day co tinh chat toan chan\n");
    }
    else
    {
        printf("+ Day khong co tinh chat toan chan\n");
    }

    return 0;
}
