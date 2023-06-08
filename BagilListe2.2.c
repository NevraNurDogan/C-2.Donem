#include <stdio.h>
#include <stdlib.h>

/* 2. Herhangi bir sayý güncellendiðinde sýralamayý dikkate alarak güncellenen sayýyý baðlý 
listedeki ilgili düðüme yerleþtiriniz.
Örnek: 4 güncellenecek. Yeni sayi: 10 olsun.
10 6 3 2 1*/

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
void degistir(struct Dugum*ilk,int degisecek,int yeniDeger){
 	struct Dugum*gecici=ilk;
     while (gecici != NULL){
     	if(gecici->data==degisecek){
     		gecici->data=yeniDeger;
     		break;
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
	 	
	 	int yeni,degisecek;
	 	printf("Degisecek sayiyi giriniz.");
	 	scanf("%d",&degisecek);
	 	printf("Yeni sayiyi giriniz.");
	 	scanf("%d",&yeni);
	   	degistir(ilk,degisecek,yeni);
     	listYazdir(ilk);
		return 0;
}
