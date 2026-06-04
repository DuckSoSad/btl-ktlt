#ifndef BAI2_H
#define BAI2_H

typedef struct {
    char TenSach[50];
    char TacGia[50];
    int NamXuatBan;
} Sach;

void XoaXuongDong(char *str);
void NhapSach(int *n, Sach **A);
void XuatSach(int n, Sach A[]);
int DemSach(int n, Sach *a);
void ThongKe(int n, Sach *a);
int Menu2();

void Bai2();

#endif