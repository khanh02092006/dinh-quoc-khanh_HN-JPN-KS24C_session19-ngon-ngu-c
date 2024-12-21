#include <stdio.h>
#include <string.h>

struct sinhvien {
    int maSV;       
    char ten[50];   
    int tuoi;       
    char phone[15]; 
};


void sap_sep_sinhvien(struct sinhvien* danhsach, int* soluong) {
    for (int i = 0; i < *soluong - 1; i++) {
        for (int j = i + 1; j < *soluong; j++) { 
            if (strcmp(danhsach[i].ten, danhsach[j].ten) > 0) {
                
                struct sinhvien temp = danhsach[i]; 
                danhsach[i] = danhsach[j];
                danhsach[j] = temp;
            }
        }
    }
}


void in_danhsach(struct sinhvien* danhsach, int soluong) {
    for (int i = 0; i < soluong; i++) {
        printf("MaSV: %d, Ten: %s, Tuoi: %d, Phone: %s\n",
               danhsach[i].maSV, danhsach[i].ten,
               danhsach[i].tuoi, danhsach[i].phone);
    }
}


int main() {
    
    struct sinhvien danhsach[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 21, "0987654321"},
        {3, "Le Van C", 22, "0112233445"},
        {4, "Pham Thi D", 23, "0223344556"},
        {5, "Hoang Van E", 24, "0334455667"}
    };

    int soluong = 5; 

   
    printf("Danh sach sinh vien ban dau:\n");
    in_danhsach(danhsach, soluong);

   
    sap_sep_sinhvien(danhsach, &soluong);

    
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    in_danhsach(danhsach, soluong);

    return 0;
}

