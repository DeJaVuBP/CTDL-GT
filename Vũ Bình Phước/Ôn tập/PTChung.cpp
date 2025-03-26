#include <stdio.h>
#include <stdlib.h>

void nhapMangTuFile(FILE *file, int *arr, int *n) {
    fscanf(file, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int isPresent(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

int timPhanTuChung(int *x, int nx, int *y, int ny, int *z, int nz, int *common) {
    int count = 0;
    for (int i = 0; i < nx; i++) {
        if (isPresent(y, ny, x[i]) && isPresent(z, nz, x[i]) && !isPresent(common, count, x[i])) {
            common[count++] = x[i];
        }
    }
    return count;
}

void inKetQua(int *arr, int size) {
    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nx, ny, nz;
    int x[1000], y[1000], z[1000];
    int common[1000];

    FILE *file = fopen("PTChung1.INP", "r");
    if (file == NULL) {
        printf("Khong mo duoc file!\n");
        return 1;
    }

    nhapMangTuFile(file, x, &nx);
    nhapMangTuFile(file, y, &ny);
    nhapMangTuFile(file, z, &nz);

    fclose(file);

    int count = timPhanTuChung(x, nx, y, ny, z, nz, common);

    qsort(common, count, sizeof(int), compare);

    inKetQua(common, count);

    return 0;
}
