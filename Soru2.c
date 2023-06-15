
#include<stdio.h>
#include<stdlib.h>

typedef struct Dugum
{
    int sayi;
    struct Dugum *sonraki;
} Dugum;

const int boyut = 10;
Dugum *ilk1 = NULL;

Dugum* Ekle(int dizi[], int boyut)
{int i;
    Dugum *geciciDugum = NULL;
    Dugum *ilk = NULL;

    for ( i = 0; i < boyut; i++)
    {
        Dugum *yeniDugum = (Dugum *)malloc(sizeof(Dugum));
        yeniDugum->sayi = dizi[i];

        if (ilk == NULL)
        {
            ilk = yeniDugum;
        }
        else
        {
            geciciDugum->sonraki = yeniDugum;
        }

        geciciDugum = yeniDugum;
        yeniDugum->sonraki = NULL;
    }

    return ilk;
}

void Listele(Dugum *ilk)
{
    Dugum *geciciDugum = ilk;
    printf("\n");

    while (geciciDugum != NULL)
    {
        printf("%d ", geciciDugum->sayi);
        geciciDugum = geciciDugum->sonraki;
    }
}

Dugum *ilk3 = NULL;

void ListeleriSiraliBirlestir(Dugum *ilk1, Dugum *ilk2)
{
    Dugum *gecici1 = ilk1;
    Dugum *gecici2 = ilk2;
    Dugum *gecici3 = NULL;
    Dugum *temp = NULL;


    if (gecici1->sayi <= gecici2->sayi)
    {
        ilk3 = gecici1;
        gecici1 = gecici1->sonraki;
    }
    else
    {
        ilk3 = gecici2;
        gecici2 = gecici2->sonraki;
    }

    gecici3 = ilk3;

    while (gecici1 != NULL && gecici2 != NULL)
    {
        if (gecici1->sayi <= gecici2->sayi)
        {
            gecici3->sonraki = gecici1;
            gecici1 = gecici1->sonraki;
        }
        else
        {
            gecici3->sonraki = gecici2;
            gecici2 = gecici2->sonraki;
        }

        gecici3 = gecici3->sonraki;
    }

   
    if (gecici1 != NULL)
    {
        gecici3->sonraki = gecici1;
    }
    else if (gecici2 != NULL)
    {
        gecici3->sonraki = gecici2;
    }
}

int main()
{
    Dugum *ilk1 = NULL;
    int dizi1[] = {10, 50, 100, 200};
    ilk1 = Ekle(dizi1, sizeof(dizi1) / sizeof(int));
    Listele(ilk1);

    Dugum *ilk2 = NULL;
    int dizi2[] = {15, 30, 125, 250, 350, 500};
    ilk2 = Ekle(dizi2, sizeof(dizi2) / sizeof(int));
    Listele(ilk2);

    ListeleriSiraliBirlestir(ilk1 , ilk2 );
    Listele(ilk3);

    return 0;
}

