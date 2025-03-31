#include <iostream>
#include <cmath>
using namespace std;

void ptb2(float a, float b, float c, float &x1, float &x2, int &so_n) {
    x1 = x2 = 0;
    so_n = 0;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                so_n = -1;  // Vô số nghiệm
            } else {
                so_n = 0;   // Vô nghiệm
            }
        } else {
            so_n = 1;    // Phương trình bậc nhất
            x1 = -c / b;
        }
    } else {
        float delta = b * b - 4 * a * c;
        cout << "Delta: " << delta << endl;  // In ra giá trị delta để kiểm tra

        if (delta < 0) {
            so_n = 0;  // Vô nghiệm
        } else if (delta == 0) {
            so_n = 1;  // Nghiệm kép
            x1 = -b / (2 * a);
        } else {
            so_n = 2;  // Hai nghiệm phân biệt
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            if (x1 > x2) {
                swap(x1, x2);
            }
        }
    }
}

int giaipttphuong(float a, float b, float c, float &x1, float &x2, float &x3, float &x4) {
    float t1, t2;
    int so_nbp;

    ptb2(a, b, c, t1, t2, so_nbp);
    cout << "t1 = " << t1 << ", t2 = " << t2 << ", so_nbp = " << so_nbp << endl;

    int so_n = 0;

    if (so_nbp == -1) {
        so_n = -1;
    } else if (so_nbp == 0) {
        so_n = 0;
    } else if (so_nbp == 1) {
        if (t1 > 0) {
            so_n = 2;
            x1 = -sqrt(t1);
            x2 = sqrt(t1);
        } else if (t1 == 0) {
            so_n = 1;
            x1 = 0;
        } else {
            so_n = 0;
        }
    } else if (so_nbp == 2) {
        if (t1 == 0 && t2 > 0) {
            so_n = 3;
            x1 = 0;
            x2 = -sqrt(t2);
            x3 = sqrt(t2);
        } else if (t1 > 0 && t2 == 0) {
            so_n = 3;
            x1 = 0;
            x2 = -sqrt(t1);
            x3 = sqrt(t1);
        } else if (t1 < 0 && t2 > 0) {
            so_n = 2;
            x1 = -sqrt(t2);
            x2 = sqrt(t2);
        } else if (t1 > 0 && t2 > 0) {
            so_n = 4;
            x1 = -sqrt(t1);
            x2 = sqrt(t1);
            x3 = -sqrt(t2);
            x4 = sqrt(t2);
        }
    }

    return so_n;
}

void testpttp() {
    float a, b, c;
    float x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    int sn;

    // Test Case 1: Vô nghiệm
    a = 1; b = 0; c = 1; // x^4 + 1 = 0 => Vô nghiệm
    sn = giaipttphuong(a, b, c, x1, x2, x3, x4);
    printf("Test Case 1: Vô nghiệm\n");
    printf("sn = %d\n", sn);
    printf("---\n");

    // Test Case 2: 1 nghiệm
    a = 1; b = 0; c = 0; // x^4 = 0 => x = 0
    sn = giaipttphuong(a, b, c, x1, x2, x3, x4);
    printf("Test Case 2: 1 nghiệm\n");
    printf("sn = %d, x1 = %.2f\n", sn, x1);
    printf("---\n");

    // Test Case 3: 2 nghiệm
    a = 1; b = 0; c = -1; // x^4 - 1 = 0 => x = ±1
    sn = giaipttphuong(a, b, c, x1, x2, x3, x4);
    printf("Test Case 3: 2 nghiệm\n");
    printf("sn = %d, x1 = %.2f, x2 = %.2f\n", sn, x1, x2);
    printf("---\n");

    // Test Case 4: 3 nghiệm
    a = 1; b = -1; c = 0; // x^4 + 1 = 0 => 3 nghiệm
    sn = giaipttphuong(a, b, c, x1, x2, x3, x4);
    printf("Test Case 4: 3 nghiệm\n");
    printf("sn = %d, x1 = %.2f, x2 = %.2f, x3 = %.2f\n", sn, x1, x2, x3);
    printf("---\n");

    // Test Case 5: 4 nghiệm
    a = 1; b = -5; c = 4; // x^4 - 5x^2 + 4 = 0 => x = ±1, ±2
    sn = giaipttphuong(a, b, c, x1, x2, x3, x4);
    printf("Test Case 5: 4 nghiệm\n");
    printf("sn = %d, x1 = %.2f, x2 = %.2f, x3 = %.2f, x4 = %.2f\n", sn, x1, x2, x3, x4);
    printf("---\n");

    // Test Case 6: Vô số nghiệm
    a = 0; b = 0; c = 0; // 0 = 0 => Vô số nghiệm
    sn = giaipttphuong(a, b, c, x1, x2, x3, x4);
    printf("Test Case 6: Vô số nghiệm\n");
    printf("sn = %d\n", sn);
    printf("---\n");
}


int main() {
    float a, b, c;
    float x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    int sn;

    testpttp();

    FILE *file = freopen("GiaiPTTrungPhuong.INP", "rt", stdin);
    if (!file) {
        printf("Khong the mo file GiaiPTTrungPhuong.INP\n");
        return 1;
    }

    scanf("%f%f%f", &a, &b, &c);
    sn = giaipttphuong(a, b, c, x1, x2, x3, x4);

    if (sn == -1) {
        cout << "Phương trình có vô số nghiệm." << endl;
    } else if (sn == 0) {
        cout << "Phương trình vô nghiệm." << endl;
    } else if (sn == 1) {
        cout << "Phương trình có 1 nghiệm: x = " << x1 << endl;
    } else if (sn == 2) {
        cout << "Phương trình có 2 nghiệm: x1 = " << x1 << "; x2 = " << x2 << endl;
    } else if (sn == 3) {
        cout << "Phương trình có 3 nghiệm: x1 = " << x1 << "; x2 = " << x2 << "; x3 = " << x3 << endl;
    } else if (sn == 4) {
        cout << "Phương trình có 4 nghiệm: x1 = " << x1 << "; x2 = " << x2 << "; x3 = " << x3 << "; x4 = " << x4 << endl;
    }

    return 0;
}


