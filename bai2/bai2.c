#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char TenSach[50];
    char TacGia[50];
    int NamXuatBan;
} Sach;

// Hàm xóa bộ nhớ đệm và xuống dòng thừa khi dùng fgets
void XoaXuongDong(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// a. Hàm nhập n cuốn sách
void NhapSach(int *n, Sach **A) {
    printf("Nhap so luong cuon sach: ");
    scanf("%d", n);
    getchar(); // Xóa ký tự newline còn lại

    *A = (Sach *)malloc((*n) * sizeof(Sach));
    if (*A == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return;
    }

    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin cuon sach thu %d:\n", i + 1);
        printf("- Ten sach: ");
        fgets((*A)[i].TenSach, 50, stdin);
        XoaXuongDong((*A)[i].TenSach);

        printf("- Tac gia: ");
        fgets((*A)[i].TacGia, 50, stdin);
        XoaXuongDong((*A)[i].TacGia);

        printf("- Nam xuat ban: ");
        scanf("%d", &((*A)[i].NamXuatBan));
        getchar(); // Xóa newline
    }
}

// b. Hàm xuất n cuốn sách
void XuatSach(int n, Sach A[]) {
    if (n <= 0 || A == NULL) {
        printf("Danh sach sach trong!\n");
        return;
    }
    printf("\n%-3s %-25s %-20s %-10s\n", "STT", "Ten Sach", "Tac Gia", "Nam XB");
    for (int i = 0; i < n; i++) {
        printf("%-3d %-25s %-20s %-10d\n", i + 1, A[i].TenSach, A[i].TacGia, A[i].NamXuatBan);
    }
}

// c. Đếm số sách của một tác giả
int DemSach(int n, Sach *a) {
    char tg[50];
    printf("Nhap ten tac gia can dem: ");
    getchar();
    fgets(tg, 50, stdin);
    XoaXuongDong(tg);

    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (strcasecmp(a[i].TacGia, tg) == 0) { // So sánh không phân biệt hoa thường
            dem++;
        }
    }
    return dem;
}

// d. Thống kê theo năm xuất bản
void ThongKe(int n, Sach *a) {
    if (n <= 0) return;
    int *daXet = (int *)calloc(n, sizeof(int));

    printf("\n--- THONG KE THEO NAM XUAT BAN ---\n");
    for (int i = 0; i < n; i++) {
        if (!daXet[i]) {
            int namHienTai = a[i].NamXuatBan;
            int dem = 0;
            for (int j = i; j < n; j++) {
                if (a[j].NamXuatBan == namHienTai) {
                    dem++;
                    daXet[j] = 1;
                }
            }
            printf("%d: %d cuon\n", namHienTai, dem);
        }
    }
    free(daXet);
}

// e. Menu và hàm main
int Menu2() {
    int chon;
    printf("\n========= MENU BAI 2 =========\n");
    printf("1. Nhap n cuon sach\n");
    printf("2. Xuat n cuon sach\n");
    printf("3. Dem theo tac gia\n");
    printf("4. Thong ke theo nam\n");
    printf("5. Thoat\n");
    printf("Lua chon cua ban [1..5]: ");
    scanf("%d", &chon);
    return chon;
}

void Bai2() {
    Sach *A = NULL;
    int n = 0;
    int chon;

    do {
        chon = Menu2();
        switch (chon) {
            case 1:
                if (A != NULL) free(A);
                NhapSach(&n, &A);
                break;
            case 2:
                XuatSach(n, A);
                break;
            case 3:
                if (n == 0) printf("Chua co du lieu sach!\n");
                else {
                    int d = DemSach(n, A);
                    printf("So cuon sach cua tac gia do la: %d\n", d);
                }
                break;
            case 4:
                if (n == 0) printf("Chua co du lieu sach!\n");
                else ThongKe(n, A);
                break;
            case 5:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon sai!\n");
        }
    } while (chon != 5);

    if (A != NULL) free(A);
}