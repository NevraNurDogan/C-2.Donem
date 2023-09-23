#include <stdio.h>
#include <stdlib.h>

/* 2. Kullanýcý tarafýndan -1 girilene kadar girilen tam sayýlardan sadece pozitif sayýlarý diziye
alan ve ortalamasýný bulan program kodunu yazýnýz.*/


int main() {
    int size = 0, *ptr, i, sum = 0, count = 0;
    ptr = (int*)malloc(size * sizeof(int)); // baþlangýçta bellek ayýrmak zorunda deðiliz
    printf("Pozitif sayilar girin (-1 girdiginizde durur): ");

    while (1) {
        scanf("%d", ptr + size);
        if (*(ptr + size) == -1) {
            break;
        }
        if (*(ptr + size) > 0) {
            size++;
          //  int *temp = (int*)realloc(ptr, size * sizeof(int)); // dinamik bellek yeniden boyutlandýrma
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
