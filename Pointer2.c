#include <stdio.h>
#include <stdlib.h>

/* 2. Kullanıcı tarafından -1 girilene kadar girilen tam sayılardan sadece pozitif sayıları diziye
alan ve ortalamasını bulan program kodunu yazınız.*/


int main() {
    int *ptr = NULL, num, sum = 0, count = 0;

    printf("Pozitif sayilar girin (-1 girdiginizde durur): ");

    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        if (num > 0) {
            count++;
            int *temp = (int *)realloc(ptr, count * sizeof(int));
            if (temp != NULL) {
                ptr = temp;
                *(ptr + count - 1) = num;
                sum += num;
            } else {
                printf("Bellek tahsis hatasi!\n");
                exit(1); 
            }
        }
    }

    if (count > 0) {
        printf("Pozitif sayilarin ortalamasi: %.2f\n", (float)sum / count);
    } else {
        printf("Hiç pozitif sayi girilmedi.\n");
    }

    free(ptr);
    return 0;
}

