#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // so luong phan tu toi da cua day
/*
Nhap day so nguyen tu ban phim
+ Vao: ban phim
+ Ra : (*a), n
+ Vi du: (*a) = {1,2,3}, n = 3
*/
void NhapMang(int **a, int *n)
{
    printf("Moi ban nhap so luong phan tu: "); // nhap (*n)
    scanf("%d", n);
    while ((*n) <= 0 || (*n) > MAX) // kiem tra nhap (*n)
    {                               // nhap lai (*n)
        printf("Nhap sai! Nhap lai: ");
        scanf("%d", n);
    } // while n
    (*a) = new int[(*n)];               // cap phat mang (*a) co (*n) phan tu
    for (int i = 0; i <= (*n) - 1; i++) // duyet tu vi tri 0 den (*n)-1
    {                                   // nhap *((*a)+i) <-> (*a)[i]
        printf("Phan tu %d: ", i);
        scanf("%d", (*a) + i); // scanf("%d",&(*a)[i]);
    } // for i
} // NhapMang
/*
Xuat day so nguyen ra man hinh
+ Vao: (*a), n
+ Ra : man hinh
+ Vi du:
*a = {2,5,3}, n = 3
=> man hinh = 2 5 3
*/
void XuatMang(int *a, int n)
{
    printf("Day so co %d phan tu: ", n); // xuat so luong phan tu
    for (int i = 0; i <= n - 1; i++)     // duyet tu vi tri 0 den n-1 lam
    {
        printf("%d ", *(a + i)); // xuat a[i] hay printf("%d",a[i]);
    } // for i
    printf("\n"); // xuong dong
} // XuatMang
/*
Dem so chan co tron day
+ Vao: *a, n
+ Ra : dem
*/
int DemChan(int *a, int n)
{
    int dem = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (*(a + i) % 2 == 0)
            dem++;
    }
    return dem;
} // DemChan
/*
Tach cac so chan
+ Vao: *a, n
+ Ra : *b, m
*/
void TachChan(int *a, int n, int **b, int *m)
{
    (*m) = DemChan(a, n); // dem so luong phan tu day (*b)
    (*b) = new int[(*m)]; // cap phat day so (*b) co (*m) phan tu
    int cs = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (*(a + i) % 2 == 0) // a[i]%2
        {
            *((*b) + cs) = *(a + i); // (*b)[cs] = a[i]
            cs++;
        }
    } // for
} // TachChan
int main()
{
    /* Khai bao bien */
    int *b = NULL, k = 0;
    int *aChan = NULL, nChan;
    /* Nhap du lieu */
    NhapMang(&b, &k);
    /* Xu ly*/
    TachChan(b, k, &aChan, &nChan);
    /* Xuat du lieu */
    printf("+ Day chua cac so chan\n");
    XuatMang(aChan, nChan);
    /* QUAN TRONG - Huy vung nho*/
    delete[] b;
    delete[] aChan;
    /* Dung man hinh xem ket qua */
    system("PAUSE");
    return 0;
} // main