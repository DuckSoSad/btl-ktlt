#ifndef BAI4_H
#define BAI4_H

typedef struct GiangVien {
    char HoTen[50];
    char HocVi[10];
    int SoTietDay;
    float DonGia;
    struct GiangVien *next;
} GiangVien;

GiangVien* taoGV();
void chenDau(GiangVien **head, GiangVien *p);
void chenCuoi(GiangVien **head, GiangVien *p);
void inDS(GiangVien *head);
void inThS(GiangVien *head);
void tinhTienLuong(GiangVien *head);
void sapXepGiam(GiangVien *head);

void Bai4();

#endif