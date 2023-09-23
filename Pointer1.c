#include <stdio.h>
#include <stdlib.h>

/* 1. Kullan�c� taraf�ndan girilen n tane tam say�dan pozitif ve negatif olarak farkl� dizilerde
g�steren program kodunu yaz�n�z.
�rnek: n:6 ise; Girilen say�lar: 1, -24, -2, 5, -5, 2
Pozitif say�lar: 1, 5, 2
Negatif say�lar: -24, -2, -5.*/


	int main() {
    int n, *p, i, j, pos[50], neg[50];
    printf("Kac tane sayi gireceksiniz?: ");
    scanf("%d", &n);

    p = (int*)malloc(n * sizeof(int)); // dinamik bellek tahsisi yap�ld�.

    for(i = 0; i < n; i++) {
        printf("Sayi %d: ", i + 1);
        scanf("%d", p + i);
    }

    int posCount = 0, negCount = 0;

    for(i = 0; i < n; i++) {
        if(*(p + i) > 0) {
            *(pos + posCount) = *(p + i);
            posCount++;
        } else {
            *(neg + negCount) = *(p + i);
            negCount++;
        }
    }

    printf("Pozitif sayilar: ");
    for(i = 0; i < posCount; i++) {
        printf("%d ", *(pos + i));
    }

    printf("\nNegatif sayilar: ");
    for(i = 0; i < negCount; i++) {
        printf("%d ", *(neg + i));
    }

    free(p); // ayr�lan bellek serbest b�rak�ld�.
    return 0;
}
