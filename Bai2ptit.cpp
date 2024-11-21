#include <stdio.h>
#include <string.h>
#define thiSinhToiDa 100
// khai bao du lieu can hoi
typedef struct {
    int ma;
    char ten[50];
    char ngaySinh[11]; 
    float diem[3];
    float tongDiem;
} ThiSinh;
    // nhap thong tin thi sinh 
void nhapThiSinh(ThiSinh *ts, int ma) {
    ts->ma = ma;
    printf("Nhap ten thi sinh: ");
    fgets(ts->ten, sizeof(ts->ten), stdin);
    ts->ten[strcspn(ts->ten, "\n")] = 0;

    printf("Nhap ngay thang nam sinh: ");
    fgets(ts->ngaySinh, sizeof(ts->ngaySinh), stdin);
    ts->ngaySinh[strcspn(ts->ngaySinh, "\n")] = 0;

    printf("Nhap diem mon 1: ");
    scanf("%f", &ts->diem[0]);
    printf("Nhap diem mon 2: ");
    scanf("%f", &ts->diem[1]);
    printf("Nhap diem mon 3: ");
    scanf("%f", &ts->diem[2]);
    ts->tongDiem = ts->diem[0] + ts->diem[1] + ts->diem[2];
    getchar(); 
}
// ham tim thu khoa
void timThuKhoa(ThiSinh ds[], int n) {
    float diemCaoNhat = -1;
    int i;

    for (i = 0; i < n; i++) {
        if (ds[i].tongDiem > diemCaoNhat) {
            diemCaoNhat = ds[i].tongDiem;
        }
    }

    printf("Thu khoa:\n");
    for (i = 0; i < n; i++) {
        if (ds[i].tongDiem == diemCaoNhat) {
            printf("%d %s %s %.1f\n", ds[i].ma, ds[i].ten, ds[i].ngaySinh, ds[i].tongDiem);
        }
    }
}
// hoi so luong thi sinh 
int main() {
    int n;
    ThiSinh ds[thiSinhToiDa];

    printf("Nhap so thi sinh: ");
    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {
        nhapThiSinh(&ds[i], i + 1);
    }

    timThuKhoa(ds, n);

    return 0;
}

