#ifndef BAI3_H
#define BAI3_H

typedef struct Node {
    float heSo;
    int luyThua;
    struct Node *next;
} Node;

Node* taoNode(float hs, int lt);
void themSoHang(Node **head, float hs, int lt);
Node* nhapDaThuc();
void inDaThuc(Node *head);
float tinhGiaTri(Node *head, float x);
float tinhDaoHam(Node *head, float x);
Node* congDaThuc(Node *dt1, Node *dt2);
void giaiPhong(Node *head);

void Bai3();

#endif