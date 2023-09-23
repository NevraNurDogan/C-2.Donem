#include <stdio.h>
#include <stdlib.h>

/* 1. Kullanýcý tarafýndan girilen n tane tam sayýdan pozitif ve negatif olarak farklý dizilerde
gösteren program kodunu yazýnýz.
Örnek: n:6 ise; Girilen sayýlar: 1, -24, -2, 5, -5, 2
Pozitif sayýlar: 1, 5, 2
Negatif sayýlar: -24, -2, -5.*/


	int main() {
    int n, *p, i, j, pos[50], neg[50];
    printf("Kac tane sayi gireceksiniz?: ");
    scanf("%d", &n);

    p = (int*)malloc(n * sizeof(int)); // dinamik bellek tahsisi yapýldý.

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

    free(p); // ayrýlan bellek serbest býrakýldý.
    return 0;
}
