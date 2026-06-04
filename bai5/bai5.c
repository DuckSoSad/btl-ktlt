#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SachNode {
    char TenSach[50];
    int SoLuong;
    char LoaiSach; // 'A', 'B', 'C'
    int NamXuatBan;
    struct SachNode *next;
} SachNode;

// Hàm tạo 1 Node Sách mới
SachNode* taoSach() {
    SachNode *p = (SachNode*)malloc(sizeof(SachNode));
    getchar();
    printf("Ten sach: "); fgets(p->TenSach, 50, stdin);
    p->TenSach[strcspn(p->TenSach, "\n")] = 0;

    printf("So luong: "); scanf("%d", &p->SoLuong);
    printf("Loai sach (A/B/C): "); scanf(" %c", &p->LoaiSach);
    printf("Nam xuat ban: "); scanf("%d", &p->NamXuatBan);
    p->next = NULL;
    return p;
}

// Bổ sung vào đầu và cuối danh sách
void chenDauSach(SachNode **head, SachNode *p) {
    p->next = *head;
    *head = p;
}

void chenCuoiSach(SachNode **head, SachNode *p) {
    if (*head == NULL) {
        *head = p;
    } else {
        SachNode *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = p;
    }
}

// In danh sách sách ra màn hình
void inDSSach(SachNode *head) {
    if(head == NULL) { printf("Danh sach rong.\n"); return; }
    printf("\n%-25s %-10s %-10s %-10s\n", "Ten Sach", "So Luong", "Loai", "Nam XB");
    while (head != NULL) {
        printf("%-25s %-10d %-10c %-10d\n", head->TenSach, head->SoLuong, head->LoaiSach, head->NamXuatBan);
        head = head->next;
    }
}

// Xóa tất cả sách xuất bản năm 2010
void xoaSach2010(SachNode **head) {
    SachNode *curr = *head, *prev = NULL;
    while (curr != NULL) {
        if (curr->NamXuatBan == 2010) {
            if (prev == NULL) { // Xóa đầu danh sách
                *head = curr->next;
                free(curr);
                curr = *head;
            } else { // Xóa ở giữa hoặc cuối
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    printf("\nDa xoa toan bo sach xuat ban nam 2010.\n");
}

// Thống kê tổng số cuốn từng loại A, B, C
void thongKeLoai(SachNode *head) {
    int sumA = 0, sumB = 0, sumC = 0;
    while (head != NULL) {
        if (head->LoaiSach == 'A' || head->LoaiSach == 'a') sumA += head->SoLuong;
        else if (head->LoaiSach == 'B' || head->LoaiSach == 'b') sumB += head->SoLuong;
        else if (head->LoaiSach == 'C' || head->LoaiSach == 'c') sumC += head->SoLuong;
        head = head->next;
    }
    printf("\n--- THONG KE TONG SO LUONG THEO LOAI ---\n");
    printf("Loai A: %d cuon\n", sumA);
    printf("Loai B: %d cuon\n", sumB);
    printf("Loai C: %d cuon\n", sumC);
}

// Sắp xếp sách theo số lượng tăng dần (Đổi dữ liệu cấu trúc)
void sapXepTang(SachNode *head) {
    for (SachNode *i = head; i != NULL && i->next != NULL; i = i->next) {
        for (SachNode *j = i->next; j != NULL; j = j->next) {
            if (i->SoLuong > j->SoLuong) {
                // Đổi TenSach
                char tTen[50]; strcpy(tTen, i->TenSach); strcpy(i->TenSach, j->TenSach); strcpy(j->TenSach, tTen);
                // Đổi SoLuong
                int tSL = i->SoLuong; i->SoLuong = j->SoLuong; j->SoLuong = tSL;
                // Đổi LoaiSach
                char tLoai = i->LoaiSach; i->LoaiSach = j->LoaiSach; j->LoaiSach = tLoai;
                // Đổi NamXB
                int tNam = i->NamXuatBan; i->NamXuatBan = j->NamXuatBan; j->NamXuatBan = tNam;
            }
        }
    }
}

void Bai5() {
    SachNode *head = NULL;
    int n;
    printf("Nhap so luong cuon sach: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i+1);
        SachNode *p = taoSach();
        chenCuoiSach(&head, p);
    }

    printf("\nDanh sach sach ban dau:");
    inDSSach(head);

    thongKeLoai(head);

    xoaSach2010(&head);
    printf("\nDanh sach sau khi xoa sach nam 2010:");
    inDSSach(head);

    sapXepTang(head);
    printf("\nDanh sach sau khi sap xep so luong tang dan:");
    inDSSach(head);

    // Giải phóng bộ nhớ
    while(head != NULL) { SachNode *t = head; head = head->next; free(t); }
}