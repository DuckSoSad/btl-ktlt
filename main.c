#include <stdio.h>
#include <stdlib.h>

#include "bai1/bai1.h"
#include "bai2/bai2.h"
#include "bai3/bai3.h"
#include "bai4/bai4.h"
#include "bai5/bai5.h"

int MenuTong() {
    int chon;
    printf("\n=========================================\n");
    printf("    HE THONG QUAN LY BAI TAP LON C\n");
    printf("=========================================\n");
    printf("1. Chay Bai 1: Quan ly day so thuc (Mang dong)\n");
    printf("2. Chay Bai 2: Quan ly Sach (Mang dong cau truc)\n");
    printf("3. Chay Bai 3: Tinh toan Da thuc (DSLK Don)\n");
    printf("4. Chay Bai 4: Quan ly Giang Vien (DSLK Don)\n");
    printf("5. Chay Bai 5: Quan ly Sach nang cao (DSLK Don)\n");
    printf("6. Thoat toan bo chuong trinh\n");
    printf("-----------------------------------------\n");
    printf("Nhap lua chon cua ban [1..6]: ");
    scanf("%d", &chon);
    return chon;
}

int main() {
    int chonBai;

    do {
        chonBai = MenuTong();
        switch (chonBai) {
            case 1:
                printf("\n--- KICH HOAT BAI 1 ---\n");
                Bai1(); 
                break;

            case 2:
                printf("\n--- KICH HOAT BAI 2 ---\n");
                getchar();
                Bai2(); 
                break;

            case 3:
                printf("\n--- KICH HOAT BAI 3 ---\n");
                Bai3();
                break;

            case 4:
                printf("\n--- KICH HOAT BAI 4 ---\n");
                Bai4();
                break;

            case 5:
                printf("\n--- KICH HOAT BAI 5 ---\n");
                Bai5();
                break;

            case 6:
                printf("\nDa thoat he thong. Tam biet!\n");
                break;

            default:
                printf("\nLua chon khong hop le! Vui long chon lai.\n");
        }
    } while (chonBai != 6);

    return 0;
}