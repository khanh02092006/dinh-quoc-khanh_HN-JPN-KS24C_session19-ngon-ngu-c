#include <stdio.h>
#include <string.h>
struct SinhVien {
    int maSV; 
    char ten[50]; 
    int tuoi; 
    char phone[15]; 
};

void xoaSinhVien(int maSV, struct SinhVien* danhSach, int* soLuong) {
    int timThay = 0;
    for (int i = 0; i < *soLuong; i++) {
        if (danhSach[i].maSV == maSV) {
            timThay = 1;
            
            for (int j = i; j < *soLuong - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
         (*soLuong)--;
		 break;
		 }
   } 
   if(!timThay){
    printf("khong tim thay sinh vien co ma%d",maSV);
	}
}
void indanhsachsinhvien(struct SinhVien* danhSach,int soluong){
    for(int i=0;i<soluong;i++){
	    printf("Ma SV: %d, Ten: %s, Tuoi: %d, So DT: %s\n", 
               danhSach[i].maSV, danhSach[i].ten, 
               danhSach[i].tuoi, danhSach[i].phone);
			   }
		}
int main(){
    struct SinhVien danhSach[5]={
	{1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 21, "0987654321"},
        {3, "Le Van C", 22, "0112233445"},
        {4, "Pham Thi D", 23, "0223344556"},
        {5, "Hoang Van E", 24, "0334455667"}
    };
    int soluong = 5;
	
	printf(" so luong sinh vien ban dau");
	indanhsachsinhvien(danhSach,soluong);
	int masv_canxoa;
	scanf("%d",&masv_canxoa);
	xoaSinhVien(masv_canxoa,danhSach,&soluong);
	printf(" so luong sinh vien da xoa");
	indanhsachsinhvien(danhSach,soluong);
	return 0;
	}	
			   	    
