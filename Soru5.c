#include <stdio.h>
#include <stdlib.h>


const int OGR_SAYISI = 12;
const int SUTUN_SAYISI = 3;

void EnBasaliriOgrencilerBul(int matris[][SUTUN_SAYISI], int N) {
    float genelOrtalamalar[OGR_SAYISI];
    int i, j,k;
    for (i = 0; i < OGR_SAYISI; i++) {
        int toplam = 0;

        for (j = 1; j < SUTUN_SAYISI; j++) {
            toplam += matris[i][j];
        }

        genelOrtalamalar[i] = (float)toplam / (SUTUN_SAYISI - 1);
    }

    for (i = 0; i < OGR_SAYISI - 1; i++) {
        for (j = 0; j < OGR_SAYISI - i - 1; j++) {
            if (genelOrtalamalar[j] < genelOrtalamalar[j + 1]) {
                float tempOrtalama = genelOrtalamalar[j];
                genelOrtalamalar[j] = genelOrtalamalar[j + 1];
                genelOrtalamalar[j + 1] = tempOrtalama;

                int tempBilgi[SUTUN_SAYISI];
                for ( k = 0; k < SUTUN_SAYISI; k++) {
                    tempBilgi[k] = matris[j][k];
                    matris[j][k] = matris[j + 1][k];
                    matris[j + 1][k] = tempBilgi[k];
                }
            }
        }
    }

    printf("En yuksek genel ortalamaya sahip %d ogrenci:\n", N);
    printf("No\tVize\tFinal\tOrtalama\n");
    for (i = 0; i < N; i++) {
        printf("%d\t%d\t%d\t%.2f\n", matris[i][0], matris[i][1], matris[i][2], genelOrtalamalar[i]);
    }
}

int main() {
    int matris[12][3] = {
        {2101, 70, 60},
        {2102, 50, 35},
        {2103, 60, 75},
        {2104, 70, 90},
        {2105, 75, 50},
        {2106, 50, 35},
        {2107, 10, 55},
        {2108, 20, 40},
        {2109, 75, 90},
        {2110, 12, 85},
        {2111, 53, 75},
        {2112, 12, 30}
    };

    int N ;  
    printf("Ogrenci sayisini giriniz:");
    scanf("%d",&N);
    EnBasaliriOgrencilerBul(matris, N);

    return 0;
}

