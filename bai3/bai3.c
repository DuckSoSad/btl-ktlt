#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Định nghĩa cấu trúc 1 Node (Hệ số, Lũy thừa)
typedef struct Node {
    float heSo;
    int luyThua;
    struct Node *next;
} Node;

// Hàm tạo Node mới
Node* taoNode(float hs, int lt) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->heSo = hs;
    p->luyThua = lt;
    p->next = NULL;
    return p;
}

// Thêm một số hạng vào đa thức (sắp xếp giảm dần theo lũy thừa)
void themSoHang(Node **head, float hs, int lt) {
    if (hs == 0) return;
    Node *p = taoNode(hs, lt);
    if (*head == NULL || (*head)->luyThua < lt) {
        p->next = *head;
        *head = p;
    } else {
        Node *temp = *head;
        while (temp->next != NULL && temp->next->luyThua >= lt) {
            temp = temp->next;
        }
        if (temp->luyThua == lt) {
            temp->heSo += hs; // Trùng lũy thừa thì cộng dồn hệ số
            free(p);
        } else {
            p->next = temp->next;
            temp->next = p;
        }
    }
}

// Nhập đa thức
Node* nhapDaThuc() {
    Node *head = NULL;
    int n;
    printf("Nhap so luong so hang cua da thuc: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        float hs;
        int lt;
        printf("Nhap he so va luy thua thu %d (vd: 3 5 -> 3x^5): ", i+1);
        scanf("%f %d", &hs, &lt);
        themSoHang(&head, hs, lt);
    }
    return head;
}

// In đa thức
void inDaThuc(Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node *temp = head;
    int dau = 1;
    while (temp != NULL) {
        if (temp->heSo > 0 && !dau) printf(" + ");
        if (temp->heSo < 0) printf(" - ");
        
        float tuyetDoi = fabs(temp->heSo);
        if (temp->luyThua == 0) printf("%.1f", tuyetDoi);
        else if (temp->luyThua == 1) printf("%.1fx", tuyetDoi);
        else printf("%.1fx^%d", tuyetDoi, temp->luyThua);
        
        dau = 0;
        temp = temp->next;
    }
    printf("\n");
}

// Tính giá trị đa thức tại x
float tinhGiaTri(Node *head, float x) {
    float ketQua = 0;
    Node *temp = head;
    while (temp != NULL) {
        ketQua += temp->heSo * pow(x, temp->luyThua);
        temp = temp->next;
    }
    return ketQua;
}

// Đạo hàm đa thức tại x
float tinhDaoHam(Node *head, float x) {
    float ketQua = 0;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->luyThua > 0) {
            ketQua += temp->heSo * temp->luyThua * pow(x, temp->luyThua - 1);
        }
        temp = temp->next;
    }
    return ketQua;
}

// Cộng hai đa thức
Node* congDaThuc(Node *dt1, Node *dt2) {
    Node *kq = NULL;
    Node *p1 = dt1, *p2 = dt2;
    while (p1 != NULL) {
        themSoHang(&kq, p1->heSo, p1->luyThua);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        themSoHang(&kq, p2->heSo, p2->luyThua);
        p2 = p2->next;
    }
    return kq;
}

// Giải phóng bộ nhớ danh sách
void giaiPhong(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void Bai3() {
    printf("--- NHAP DA THUC 1 ---\n");
    Node *dt1 = nhapDaThuc();
    printf("--- NHAP DA THUC 2 ---\n");
    Node *dt2 = nhapDaThuc();

    printf("\nDa thuc 1: "); inDaThuc(dt1);
    printf("Da thuc 2: "); inDaThuc(dt2);

    float x;
    printf("\nNhap gia tri x: ");
    scanf("%f", &x);

    printf("Gia tri cua Da thuc 1 tai x = %.2f la: %.2f\n", x, tinhGiaTri(dt1, x));
    printf("Dao ham cua Da thuc 1 tai x = %.2f la: %.2f\n", x, tinhDaoHam(dt1, x));

    Node *dtTong = congDaThuc(dt1, dt2);
    printf("\nDa thuc Tong (DT1 + DT2): ");
    inDaThuc(dtTong);

    giaiPhong(dt1);
    giaiPhong(dt2);
    giaiPhong(dtTong);
}