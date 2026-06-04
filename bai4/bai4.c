#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GiangVien {
    char HoTen[50];
    char HocVi[10]; // "TS", "ThS", "CN"
    int SoTietDay;
    float DonGia;
    struct GiangVien *next;
} GiangVien;

// Hàm tạo 1 Giảng viên mới
GiangVien* taoGV() {
    GiangVien *p = (GiangVien*)malloc(sizeof(GiangVien));
    getchar(); // Xóa bộ đệm
    printf("Ho ten GV: "); fgets(p->HoTen, 50, stdin);
    p->HoTen[strcspn(p->HoTen, "\n")] = 0;
    
    printf("Hoc vi (TS/ThS/CN): "); scanf("%s", p->HocVi);
    printf("So tiet day: "); scanf("%d", &p->SoTietDay);
    printf("Don gia: "); scanf("%f", &p->DonGia);
    p->next = NULL;
    return p;
}

// Bổ sung vào đầu danh sách
void chenDau(GiangVien **head, GiangVien *p) {
    p->next = *head;
    *head = p;
}

// Bổ sung vào cuối danh sách
void chenCuoi(GiangVien **head, GiangVien *p) {
    if (*head == NULL) {
        *head = p;
    } else {
        GiangVien *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = p;
    }
}

// In danh sách giảng viên
void inDS(GiangVien *head) {
    printf("\n%-25s %-10s %-12s %-12s\n", "Ho Ten", "Hoc Vi", "So Tiet", "Don Gia");
    while (head != NULL) {
        printf("%-25s %-10s %-12d %-12.2f\n", head->HoTen, head->HocVi, head->SoTietDay, head->DonGia);
        head = head->next;
    }
}

// Tìm và in giảng viên ThS
void inThS(GiangVien *head) {
    printf("\n--- DANH SACH GIANG VIEN THAC SI (ThS) ---\n");
    int co = 0;
    while (head != NULL) {
        if (strcmp(head->HocVi, "ThS") == 0) {
            printf("%-25s %-12d %-12.2f\n", head->HoTen, head->SoTietDay, head->DonGia);
            co = 1;
        }
        head = head->next;
    }
    if(!co) printf("Khong co giang vien nao hoc vi ThS.\n");
}

// Tính tiền giảng dạy
void tinhTienLuong(GiangVien *head) {
    printf("\n--- BANG LUONG GIANG VIEN ---\n");
    while (head != NULL) {
        float heSo = 0.5;
        if (strcmp(head->HocVi, "TS") == 0) heSo = 1.5;
        else if (strcmp(head->HocVi, "ThS") == 0) heSo = 1.0;
        
        float thanhTien = head->SoTietDay * head->DonGia * heSo;
        printf("GV: %-25s | Luong: %.2f\n", head->HoTen, thanhTien);
        head = head->next;
    }
}

// Sắp xếp giảng viên theo số tiết dạy giảm dần (Đổi chỗ dữ liệu)
void sapXepGiam(GiangVien *head) {
    for (GiangVien *i = head; i != NULL && i->next != NULL; i = i->next) {
        for (GiangVien *j = i->next; j != NULL; j = j->next) {
            if (i->SoTietDay < j->SoTietDay) {
                // Hoán vị dữ liệu HoTen
                char tTen[50]; strcpy(tTen, i->HoTen); strcpy(i->HoTen, j->HoTen); strcpy(j->HoTen, tTen);
                // Hoán vị HocVi
                char tVi[10]; strcpy(tVi, i->HocVi); strcpy(i->HocVi, j->HocVi); strcpy(j->HocVi, tVi);
                // Hoán vị Tiet day
                int tTiet = i->SoTietDay; i->SoTietDay = j->SoTietDay; j->SoTietDay = tTiet;
                // Hoán vị Don gia
                float tGia = i->DonGia; i->DonGia = j->DonGia; j->DonGia = tGia;
            }
        }
    }
}

void Bai4() {
    GiangVien *head = NULL;
    int n;
    printf("Nhap so luong giang vien: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nNhap giang vien thu %d:\n", i+1);
        GiangVien *p = taoGV();
        chenCuoi(&head, p); // Hoặc chenDau(&head, p);
    }

    printf("\nDanh sach ban dau:");
    inDS(head);

    inThS(head);
    tinhTienLuong(head);

    sapXepGiam(head);
    printf("\nDanh sach sau khi sap xep so tiet giam dan:");
    inDS(head);

    // Giải phóng bộ nhớ
    while(head != NULL) { GiangVien *t = head; head = head->next; free(t); }
}