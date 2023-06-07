#include <stdio.h>
#include <stdlib.h>

/* 8. Kullanýcý tarafýndan girilen artýþ miktarýna göre ekrana yazdýrýnýz.
Örnek: 3 ise , 3 ve 3’ün katýnda yer alan sayýlarý yazdýralým. Bu durumda 20 ve 12 
yazdýrýlacaktýr*/

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
void katBul(struct Dugum* bas,int kat) {
    struct Dugum* gecici = bas;
        while (gecici != NULL) {
            if (gecici->data %kat == 0) {
                printf("%d ", gecici->data);
            }
            gecici = gecici->next;
        }
        
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
	 	listYazdir(ilk);
	 	int kat;
	 	printf("Artis miktari giriniz: ");
	 	scanf("%d",&kat);
        katBul(ilk,kat);
	
 	
		return 0;
}
