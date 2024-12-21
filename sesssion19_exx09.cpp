#include <stdio.h>
#include <string.h>


struct SinhVien {
    int maSV;       
    char ten[50];  
    int tuoi;       
    char phone[15]; 
};


void hienThiDanhSach(struct SinhVien* danhsach, int soluong) {
    if (soluong == 0) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }
    for (int i = 0; i < soluong; i++) {
        printf("MaSV: %d, Ten: %s, Tuoi: %d, Phone: %s\n",
               danhsach[i].maSV, danhsach[i].ten,
               danhsach[i].tuoi, danhsach[i].phone);
    }
}


void themSinhVien(struct SinhVien* danhsach, int* soluong) {
    if (*soluong >= 100) {
        printf("Danh sach da day, khong the them sinh vien moi.\n");
        return;
    }
    printf("Nhap ma sinh vien: ");
    scanf("%d", &danhsach[*soluong].maSV);
    printf("Nhap ten sinh vien: ");
    scanf(" %[^\n]", danhsach[*soluong].ten);
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &danhsach[*soluong].tuoi);
    printf("Nhap so dien thoai: ");
    scanf(" %[^\n]", danhsach[*soluong].phone);
    (*soluong)++;
    printf("Them sinh vien thanh cong!\n");
}


void suaSinhVien(struct SinhVien* danhsach, int soluong) {
    int maSV, timThay = 0;
    printf("Nhap ma sinh vien can sua: ");
    scanf("%d", &maSV);
    for (int i = 0; i < soluong; i++) {
        if (danhsach[i].maSV == maSV) {
            timThay = 1;
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", danhsach[i].ten);
            printf("Nhap tuoi moi: ");
            scanf("%d", &danhsach[i].tuoi);
            printf("Nhap so dien thoai moi: ");
            scanf(" %[^\n]", danhsach[i].phone);
            printf("Sua thong tin thanh cong!\n");
            break;
        }
    }
    if (!timThay) {
        printf("Khong tim thay sinh vien co ma: %d\n", maSV);
    }
}


void xoaSinhVien(struct SinhVien* danhsach, int* soluong) {
    int maSV, timThay = 0;
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%d", &maSV);
    for (int i = 0; i < *soluong; i++) {
        if (danhsach[i].maSV == maSV) {
            timThay = 1;
            for (int j = i; j < *soluong - 1; j++) {
                danhsach[j] = danhsach[j + 1];
            }
            (*soluong)--;
            printf("Xoa sinh vien thanh cong!\n");
            break;
        }
    }
    if (!timThay) {
        printf("Khong tim thay sinh vien co ma: %d\n", maSV);
    }
}


void timKiemSinhVien(struct SinhVien* danhsach, int soluong) {
    char ten[50];
    int timThay = 0;
    printf("Nhap ten sinh vien can tim: ");
    scanf(" %[^\n]", ten);
    for (int i = 0; i < soluong; i++) {
        if (strstr(danhsach[i].ten, ten) != NULL) {
            printf("MaSV: %d, Ten: %s, Tuoi: %d, Phone: %s\n",
                   danhsach[i].maSV, danhsach[i].ten,
                   danhsach[i].tuoi, danhsach[i].phone);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("Khong tim thay sinh vien co ten: %s\n", ten);
    }
}


void sapXepSinhVien(struct SinhVien* danhsach, int soluong) {
    for (int i = 0; i < soluong - 1; i++) {
        for (int j = i + 1; j < soluong; j++) {
            if (strcmp(danhsach[i].ten, danhsach[j].ten) > 0) {
                struct SinhVien temp = danhsach[i];
                danhsach[i] = danhsach[j];
                danhsach[j] = temp;
            }
        }
    }
    printf("Sap xep danh sach thanh cong!\n");
}


int main() {
    struct SinhVien danhsach[100];
    int soluong = 0;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                hienThiDanhSach(danhsach, soluong);
                break;
            case 2:
                themSinhVien(danhsach, &soluong);
                break;
            case 3:
                suaSinhVien(danhsach, soluong);
                break;
            case 4:
                xoaSinhVien(danhsach, &soluong);
                break;
            case 5:
                timKiemSinhVien(danhsach, soluong);
                break;
            case 6:
                sapXepSinhVien(danhsach, soluong);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 7);

    return 0;
}

