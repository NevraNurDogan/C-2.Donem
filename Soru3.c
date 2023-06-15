#include<stdio.h>
#include<stdlib.h>

typedef struct Dugum
{
	int sayi;
	struct Dugum *sonraki;
	struct Dugum *onceki;
}Dugum;

const int boyut=10;
Dugum *ilk=NULL, *son=NULL;

ListeOlustur()
{int i;
	int dizi[] ={10, 50, 100, 200, 251, 25, 28 };
	
	for( i=0; i< sizeof(dizi)/sizeof(int); i++)
	{
		 Dugum *yeni=(Dugum *)malloc(sizeof(Dugum));	  	   
	     yeni->sayi= dizi[i];
	     
	     if(ilk==NULL)
	     {
	       ilk=yeni;
		   son=yeni;
		   yeni->sonraki=NULL;
		   yeni->onceki=NULL;	
		 }
		 else
		 {
		 	son->sonraki=yeni;
			yeni->onceki=son;
			son=yeni;
			son->sonraki=NULL; 		 	
		 }
		 
	}	
}

Listele()
{
	Dugum *gecici=ilk;
	printf("son durum: ");
	while(gecici!=NULL)
    {
		printf("%d  -> ",gecici->sayi);
		gecici=gecici->sonraki;
   	}
   	printf("\n");
}



void Sil()
{
    Dugum *gecici = son;

    while (gecici != NULL)
    {
        if (gecici->sayi % 2 == 0) 
        {
        	printf("Sil->%d\n",gecici->sayi);
            if (gecici == ilk) 
            {
                ilk = gecici->sonraki;
                if (gecici->sonraki != NULL)
                    gecici->sonraki->onceki = NULL;
            }
            else if (gecici == son) 
            {
                son = gecici->onceki;
                if (gecici->onceki != NULL)
                    gecici->onceki->sonraki = NULL;
            }
            else
            {
                gecici->onceki->sonraki = gecici->sonraki;
                gecici->sonraki->onceki = gecici->onceki;
            }
            free(gecici);
            break;
        }
        gecici = gecici->onceki;
    }
}



main()
{
	ListeOlustur();
   // Listele();
    Sil();
    Listele();
    Sil();
    Listele();
}
