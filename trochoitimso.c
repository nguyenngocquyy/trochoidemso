#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateTargetNumber(char* target) {
    srand(time(NULL));
    int digits[10] = {0};

    // Tạo một số có 4 chữ số, các chữ số đều khác nhau
    for (int i = 0; i < 4; i++) {
        int digit;
        do {
            digit = rand() % 10;
        } while (digits[digit] != 0 || (i == 0 && digit == 0));
        
        digits[digit] = 1;
        target[i] = '0' + digit;
    }
    target[4] = '\0';
}


void getHints(char* target, char* guess, char* hints) {
    for (int i = 0; i < 4; i++) {
        if (guess[i] == target[i]) {
            hints[i] = 'B'; // Chữ số đúng ở đúng vị trí
        } else if (strchr(target, guess[i])) {
            hints[i] = 'W'; // Chữ số đúng ở vị trí sai
        } else {
            hints[i] = 'X'; // Chữ số không nằm trong số mục tiêu
        }
    }
    hints[4] = '\0';
}

int main() {
    printf("Chao mung ban den voi tro choi guessNumber!\n");

    char target[5];
    generateTargetNumber(target);
    int attempts = 0;


    while (1) {
        char guess[5];
        char hints[5];
        printf("nhap du doan cua ban ( khong trung nhau) : ");
        scanf("%s", guess);

        if (strlen(guess) != 4) {
            printf("du doan khong hop le vui long nhap 4 chu so.\n");
            continue;
        }

        attempts++;

        if (strcmp(guess, target) == 0) {
            printf("Chuc mung! Ban đa đoan đung so muc tieu %s trong %d lan thu.\n", target, attempts);
            break;
        } else {
            getHints(target, guess, hints);
            printf("Goi y: %s\n", hints);
        }
    }
 
    return 0;
}
