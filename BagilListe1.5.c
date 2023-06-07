#include <stdio.h>
#include <stdlib.h>

/*5. Kullanýcýnýn istediði sýradaki elemaný ekrana yazdýrýnýz.
Örnek : 2. Eleman ise 10 yazdýrýnýz.*/

 struct Dugum {
 	int data;
 	struct Dugum* next;
     };
struct Dugum* listOlustur(int data){
     struct	Dugum* yenidugum=(struct Dugum*)malloc(sizeof(struct Dugum));
	 if (yenidugum==NULL){
  	exit(1);
	 }
	 yenidugum->data=data;
	 yenidugum->next=NULL;
     } 
void listeyeEkle(struct Dugum** ilk,int data){
	 struct Dugum* yenidugum=listOlustur(data);
	 if(*ilk==NULL){
		*ilk=yenidugum;
 	}
 	else{
		struct Dugum* gecici = *ilk;
		while(gecici->next!=NULL){
			gecici=gecici->next;
		 }
		 gecici->next =yenidugum;
 	}
}
void listYazdir(struct Dugum*ilk){
  	struct Dugum*gecici=ilk;
 	if(gecici==NULL){
		 printf("Liste boþ.\n");
 	}       
	else{
		 printf("Bagil liste: ");
         while (gecici != NULL) {
            printf("%d ", gecici->data);
            gecici = gecici->next;
     	}
  	printf("\n");
     }
}
void elemanBul(struct Dugum* bas, int bul) {
    struct Dugum* gecici = bas;
    int count = 1;
    while (gecici != NULL) {
        if (count == bul) {
            printf("%d. Eleman: %d\n", bul, gecici->data);
            return;
        }
        count++;
        gecici = gecici->next;
    }

    printf("Hata: %d. sirada eleman bulunamadi.\n", bul);
}
int main(int argc, char *argv[]) {
 	struct Dugum* ilk=NULL;
 	int sayi;
 	printf("Sayi giriniz(-1 girerek islemi sonlandirabilirsiniz)\n");
 	while(1){
	 	printf("sayi:");
			scanf("%d",&sayi);
			if(sayi==-1){
				break;
		  	}
			 listeyeEkle(&ilk,sayi);
	 	}
	 	
	int bul;
    printf("Kacinci elemani istersiniz? ");
    scanf("%d", &bul);

    elemanBul(ilk, bul);
 	
		return 0;
}
