#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bai1.h"

int Nhap(float **a) {
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    if (n <= 0) return 0;

    *a = (float *)malloc((n) * sizeof(float));
    if (*a == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", (*a) + i);
    }
    return n;
}

void Xuat(int n, float *a) {
    if (n == 0 || a == NULL) {
        printf("Day so rong!\n");
        return;
    }
    printf("Day so hien tai: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f  ", a[i]);
    }
    printf("\n");
}

int MaxDuong(int n, float *a, float *max) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (!found) {
                *max = a[i];
                found = 1;
            } else {
                if (a[i] > *max) {
                    *max = a[i];
                }
            }
        }
    }
    return found;
}

int Fibo(int n, float *a) {
    if (n < 3) return 0;
    for (int i = 2; i < n; i++) {
        if (fabs(a[i] - (a[i - 1] + a[i - 2])) > 0.0001) {
            return 0; 
        }
    }
    return 1;
}

int Menu1() {
    int chon;
    printf("\n========= MENU BAI 1 =========\n");
    printf("1. Nhap day so\n");
    printf("2. Xuat day so\n");
    printf("3. Tim Max Duong\n");
    printf("4. Kiem tra tinh Fibonacci\n");
    printf("5. Thoat\n");
    printf("Lua chon cua ban [1..5]: ");
    scanf("%d", &chon);
    return chon;
}

void Bai1() {
    float *a = NULL;
    int n = 0;
    int chon;
    float max_d;

    do {
        chon = Menu1();
        switch (chon) {
            case 1:
                if (a != NULL) free(a);
                n = Nhap(&a);
                break;
            case 2:
                Xuat(n, a);
                break;
            case 3:
                if (n == 0) {
                    printf("Hay nhap day so truoc!\n");
                } else if (MaxDuong(n, a, &max_d)) {
                    printf("Gia tri duong lon nhat la: %.2f\n", max_d);
                } else {
                    printf("Mang khong co so duong!\n");
                }
                break;
            case 4:
                if (n == 0) {
                    printf("Hay nhap day so truoc!\n");
                } else if (Fibo(n, a)) {
                    printf("Day so CO tinh chat Fibonacci.\n");
                } else {
                    printf("Day so KHONG CO tinh chat Fibonacci.\n");
                }
                break;
            case 5:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 5);

    if (a != NULL) free(a);
}