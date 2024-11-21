#include <stdio.h>
#include <string.h>
#include <ctype.h>

// sua ten
void suaTen(char *hoTen) {
    int i, j = 0, len = strlen(hoTen);
    char ketQua[81];
    
    // xoa khoang trang o dau
    while (hoTen[0] == ' ') {
        for (i = 0; i < len; i++) {
            hoTen[i] = hoTen[i + 1];
        }
        len--;
    }
    // cai dat de dung voi dinh dang dua ra
    int kiTuDau = 0;
    for (i = 0; i < len; i++) {
        if (hoTen[i] != ' ') {
            if (kiTuDau == 0) {
                ketQua[j++] = toupper(hoTen[i]); 
                kiTuDau = 1; 
            } else {
                ketQua[j++] = tolower(hoTen[i]); 
            }
        } else {

            if (kiTuDau == 1 && hoTen[i + 1] != ' ' && i + 1 < len) {
                ketQua[j++] = ' ';
                kiTuDau = 0; 
            }
        }
    }

    ketQua[j] = '\0';
    printf("%s\n", ketQua); 
}

int main() {
    char hoTen[81];
    
    printf("Nhap vao ho ten can sua: ");
    fgets(hoTen, sizeof(hoTen), stdin);

    // goi ham
    suaTen(hoTen);

    return 0;
}

