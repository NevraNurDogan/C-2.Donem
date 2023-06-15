#include<stdio.h>
#include <stdlib.h>

 typedef struct Agac
 {
 	struct Agac *sol;
 	struct Agac *sag;
 	int sayi;
 	char adi[15];
 	
  }Agac;
  
  Agac * Ekle( Agac *dugum, int sayi)
  {
  	
  	if(dugum==NULL)
  	{
  		Agac *kok= (Agac *)malloc(sizeof(Agac));
		kok->sayi= sayi;
		kok->sol=NULL;
		kok->sag=NULL;
		return kok;
	}
	
	if(sayi < dugum->sayi)
	{
		dugum->sol= Ekle(dugum->sol, sayi);
		return dugum;
	}
	
	dugum->sag= Ekle(dugum->sag, sayi);
	return dugum;	
  	
  }
  
void InOrder(Agac *kok)
{
	if(kok==NULL)
	{
		return;
	}
	
	InOrder(kok->sol);
	printf("\n %d", kok->sayi);
	InOrder(kok->sag);
}
  

 
void OrtalamadanBuyukleriYazdir(Agac *kok, float ort)
{
    if(kok == NULL)
    {
        return;
    }

    OrtalamadanBuyukleriYazdir(kok->sol, ort);

    if(kok->sayi > ort)
    {
        printf("%d ", kok->sayi);
    }

    OrtalamadanBuyukleriYazdir(kok->sag, ort);
}

float AgacOrtalamasi(Agac *kok)
{
    if(kok == NULL)
    {
        return 0;
    }

    float toplam = kok->sayi;
    int adet = 1;

    if(kok->sol != NULL)
    {
        toplam += AgacOrtalamasi(kok->sol);
        adet++;
    }

    if(kok->sag != NULL)
    {
        toplam += AgacOrtalamasi(kok->sag);
        adet++;
    }

    return toplam / adet;
}

 
  main()
  {
  	Agac *kok=NULL;
  	kok= Ekle(kok, 10);
  	Ekle(kok, 5);
  	Ekle(kok, 40);
	Ekle(kok, 20);
  	Ekle(kok, 35);
  	Ekle(kok, 70);
  	Ekle(kok, 100);
	InOrder(kok);
	float ortalama = AgacOrtalamasi(kok);
    printf("\nOrtalama: %.2f\n", ortalama);
  OrtalamadanBuyukleriYazdir( kok,ortalama); 
  } 
