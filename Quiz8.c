#include <stdio.h>
#include <stdlib.h>
/*Olu�turmu� oldu�unuz �ift y�nl� ba�l� listedeki say�lar� s�ras�yla en ba�tan ve sondan olmak �zere kar��la�t�r�p first<end olan say�lar� yer de�i�tiriniz.
1-2-10-50-5-3-6
1 < 6 oldu�undan ;
6-2-10-50-5-3-1
2 < 3 oldu�undan ;�
6-3-10-50-5-2-1
10 < 5 �art� sa�lanmad���ndan liste son hali ;�
6-3-10-50-5-2-1*/

struct Dugum {
    int veri;
    struct Dugum* onceki;
    struct Dugum* sonraki;
};

struct CiftYonluBagliListe {
    struct Dugum* bas;
    struct Dugum* son;
};

void DugumEkle(struct CiftYonluBagliListe* liste, int veri) {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeniDugum->veri = veri;
    yeniDugum->onceki = NULL;
    yeniDugum->sonraki = NULL;

    if (liste->bas == NULL) {
        liste->bas = yeniDugum;
        liste->son = yeniDugum;
    } else {
        yeniDugum->onceki = liste->son;
        liste->son->sonraki = yeniDugum;
        liste->son = yeniDugum;
    }
}

void ListeYazdir(struct CiftYonluBagliListe* liste) {
    struct Dugum* current = liste->bas;
    while (current != NULL) {
        printf("%d \t", current->veri);
        current = current->sonraki;
    }

}

void dugum_yer_degistir(struct CiftYonluBagliListe* liste,int boyut) {
    struct Dugum* bas = liste->bas;
    struct Dugum* son = liste->son;
    int degisiklik;
    int i,n;
    n=boyut/2;
    do {
        degisiklik = 0;
        struct Dugum* kontrolb = bas;
        struct Dugum* kontrols = son;
       for (i=0;i<n;i++) {
            if (kontrolb->veri < kontrols->veri) {
                int temp = kontrolb->veri;
                kontrolb->veri = kontrols->veri;
                kontrols->veri = temp;
                degisiklik = 1;
            }
            kontrolb =kontrolb->sonraki;
            kontrols =kontrols->onceki;
        }

    } while (degisiklik);
}

int main() {
    struct CiftYonluBagliListe liste;
    liste.bas = NULL;
    liste.son = NULL;
    int sayi,n,a=0;
    printf("-1 girilene kadar sayi girisine izin verilir.\n");
    while (1) {
        printf("Sayi girin: ");
        scanf("%d", &sayi);
        if(sayi==-1){
        	break;
		}
        DugumEkle(&liste, sayi);
        a++;
    }
   ListeYazdir(&liste);
   dugum_yer_degistir(&liste,a);
   printf("\n");
   ListeYazdir(&liste);
}
