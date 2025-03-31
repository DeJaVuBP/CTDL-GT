#include <iostream>
#include <cmath>
using namespace std;


int giaiptbac2(float a, float b, float c, float &x1, float &x2)
{
    int sn = -1;
    if(a==0) {
        if(b==0) {
            if(c==0)
                sn = -1;
            else
                sn = 0;
        }
        else { // bx + c  = 0
            sn = 1;
            x1 = -c / b;
        }
    } else {
        float delta = b * b - 4 * a * c;
        if(delta<0) sn = 0;
        else if(delta == 0) {
            sn = 1;
            x1 = -b / (2 * a);
        } else {
            sn = 2;
            x1 = (-b - sqrt(delta))/(2*a);
            x2 = (-b + sqrt(delta))/(2*a);
            if(x1>x2){
                float tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
        }
    }
    return sn;
}

void test1(){
    float a1, b1, c1;
    int sn1; float x1, x2;

    a1=0; b1=0; c1=0; sn1 = giaiptbac2(a1, b1, c1, x1, x2);
    printf("sn=%d, x1=%g, x2=%g\n", sn1, x1, x2);
    printf("---\n");

    a1=0; b1=0; c1=5; sn1 = giaiptbac2(a1, b1, c1, x1, x2);
    printf("sn=%d, x1=%g, x2=%g\n", sn1, x1, x2);
    printf("---\n");

    a1=1; b1=-2; c1=1; sn1 = giaiptbac2(a1, b1, c1, x1, x2);
    printf("sn=%d, x1=%g, x2=%g\n", sn1, x1, x2);
    printf("---\n");

    a1=1; b1=-3; c1=2; sn1 = giaiptbac2(a1, b1, c1, x1, x2);
    printf("sn=%d, x1=%g, x2=%g\n", sn1, x1, x2);


}

int main(){
    float a, b, c;
    int sn; float x1, x2;

    test1();

    FILE *file = freopen("GiaiPTBac2.INP", "rt", stdin);
    if (!file) {
        printf("Khong the mo file GiaiPTBac2.INP\n");
        return 1;
    }

    scanf("%f%f%f", &a, &b, &c);
    sn = giaiptbac2(a, b, c, x1, x2);

    if(sn == -1)
        printf("Phuong trinh co vo so nghiem\n");
    else if(sn == 0)
        printf("Phuong trinh vo nghiem\n");
    else {
        printf("Phuong trinh co %d nghiem\n", sn);
        printf("%.2f", x1);
        if(sn == 2)
            printf(" %.2f", x2);
        printf("\n");
    }
    return 0;
}


