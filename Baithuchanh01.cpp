#include <stdio.h>

#define toiDa 30000


void soCanTim(int arr[], int n) {
    int count[toiDa + 1] = {0};
    int maxCount = 0;
    int maxNum = -1; 

   
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

  
    for (int i = 0; i <= toiDa; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxNum = i;
        } else if (count[i] == maxCount && i > maxNum) {
            maxNum = i;
        }
    }
    
    printf("So xuat hien nhieu nhat la %d\n", maxNum);
}

int main() {
    int t;
    printf("Nhap so bo test: ");
    scanf("%d", &t); 

    while (t--) {
        int n; 
        printf("Nhap so phan tu cua day: ");
        scanf("%d", &n); 
        
        int arr[n]; 
        
        printf("Nhap cac phan tu cua day: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]); 
        }

        soCanTim(arr, n);
    }

    return 0;
}

