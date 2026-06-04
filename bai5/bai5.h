#ifndef BAI5_H
#define BAI5_H

typedef struct SachNode {
    char TenSach[50];
    int SoLuong;
    char LoaiSach;
    int NamXuatBan;
    struct SachNode *next;
} SachNode;

SachNode* taoSach();
void chenDauSach(SachNode **head, SachNode *p);
void chenCuoiSach(SachNode **head, SachNode *p);
void inDSSach(SachNode *head);
void xoaSach2010(SachNode **head);
void thongKeLoai(SachNode *head);
void sapXepTang(SachNode *head);

void Bai5();

#endif