#include <stdio.h>
#include <stdlib.h>

/* 2. Kullan�c� taraf�ndan -1 girilene kadar girilen tam say�lardan sadece pozitif say�lar� diziye
alan ve ortalamas�n� bulan program kodunu yaz�n�z.*/


int main() {
    int size = 0, *ptr, i, sum = 0, count = 0;
    ptr = (int*)malloc(size * sizeof(int)); // ba�lang��ta bellek ay�rmak zorunda de�iliz
    printf("Pozitif sayilar girin (-1 girdiginizde durur): ");

    while (1) {
        scanf("%d", ptr + size);
        if (*(ptr + size) == -1) {
            break;
        }
        if (*(ptr + size) > 0) {
            size++;
          //  int *temp = (int*)realloc(ptr, size * sizeof(int)); // dinamik bellek yeniden boyutland�rma
            //if (temp != NULL) {
               // ptr = temp;
           // }  
        }
    }

    for (i = 0; i < size; i++) {
        sum += *(ptr + i);
        count++;
    }

    printf("Pozitif sayilarin ortalamasi: %.2f", (float)sum / count);

    free(ptr);
    return 0;
}
