#include <bits/stdc++.h>
using namespace std;
struct SinhVien {
    int maSV;
    string tenSV;
    string lop;
    float tongKet;
    string hanhKiem;
};
struct Node {
    SinhVien data;
    Node* left;
    Node* right;
};
void khoiTaoCay(Node*& root) {
    root = nullptr;
}

Node* taoNut(SinhVien sv) {
    Node* newNode = new Node;
    newNode->data = sv;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void chenNut(Node*& root, SinhVien sv) {
    if (root == nullptr) {
        root = taoNut(sv);
    } else {
        if (sv.maSV < root->data.maSV) {
            chenNut(root->left, sv);
        } else if (sv.maSV > root->data.maSV) {
            chenNut(root->right, sv);
        }
    }
}
Node* timKiem(Node* root, int maSV) {
    if (root == nullptr || root->data.maSV == maSV) {
        return root;
    }
    if (root->data.maSV < maSV) {
        return timKiem(root->right, maSV);
    }
    return timKiem(root->left, maSV);
}

void hienThiSV(SinhVien sv) {
    cout << "- Ma SV: " << sv.maSV 
         << " | Ten: " << sv.tenSV 
         << " | Lop: " << sv.lop 
         << " | Tong ket: " << sv.tongKet 
         << " | Hanh kiem: " << sv.hanhKiem << endl;
}
void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        hienThiSV(root->data);
        duyetCay(root->right);
    }
}
void nhapThongTinSV(SinhVien &sv) {
    cout << "Nhap Ma SV (so nguyen): "; 
    cin >> sv.maSV;
    cin.ignore(); 
    cout << "Nhap Ten SV: "; 
    getline(cin, sv.tenSV);
    cout << "Nhap Lop: "; 
    getline(cin, sv.lop);
    cout << "Nhap diem Tong ket: "; 
    cin >> sv.tongKet;
    cin.ignore(); 
    cout << "Nhap Hanh kiem (Tot/Kha/Trung binh/Yeu): "; 
    getline(cin, sv.hanhKiem);
}

int main() {
    Node* root;
    khoiTaoCay(root);
    int n;
    cout << "Nhap so luong sinh vien n = "; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---" << endl;
        nhapThongTinSV(sv);
        chenNut(root, sv);
    }
    cout << "\n=== DANH SACH SINH VIEN TRONG CAY ===" << endl;
    if (root == nullptr) {
        cout << "Cay rong!" << endl;
    } else {
        duyetCay(root);
    }
    int maCanTim;
    cout << "\nNhap Ma SV can tim kiem: "; 
    cin >> maCanTim;
    Node* ketQua = timKiem(root, maCanTim);
    if (ketQua != nullptr) {
        cout << "=> THONG TIN SINH VIEN TIM THAY:\n";
        hienThiSV(ketQua->data);
    } else {
        cout << "=> khong co sinh vien trong cay." << endl;
    }
    return 0;
}
