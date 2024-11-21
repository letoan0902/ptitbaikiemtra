#include <stdio.h>

// nhap ma tran a n*m
void nhapMaTran(int a[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// tinh tich cua a b va luu vao c
void tinhTichMaTran(int a[100][100], int b[100][100], int c[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// in ma tran c co kich thuoc n*n
void inMaTran(int c[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", c[i][j]);
            if (j < n - 1) printf(" "); 
        }
        printf("\n");
    }
}

int main() {
    int t; 
    printf("Nhap so bo test: ");
    scanf("%d", &t);
    
    for (int test = 1; test <= t; test++) {
        int n, m;
        printf("Nhap kich thuoc ma tran n,m : ");
        scanf("%d %d", &n, &m);
        
        int a[100][100];  
        int b[100][100];  
        int c[100][100];  
        
        // nhap a 
        printf("Nhap ma tran a:\n");
        nhapMaTran(a, n, m);
        
        // tao b la chuyen vi cua a 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][i] = a[i][j];
            }
        }

        // tich a vaf b luu vao c
        tinhTichMaTran(a, b, c, n, m);
        
        // in ket qua
        printf("Test %d:\n", test);
        inMaTran(c, n);
    }

    return 0;
}

