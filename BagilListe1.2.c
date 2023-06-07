
#include <stdio.h>
#include <stdlib.h>
/* 2. 1. Soruda oluþturduðunuz baðlý liste içinde yer alan sayýlarýn ortalamasýný bulunuz. */
/* 1.soru=>int verilerden oluþan bir baðlý liste oluþturunuz. -1 girilene kadar veri giriþini saðlayýnýz.
Örnek: 1, 10, 20, 50, 90, 12, 9*/
 struct Dugum {
 	int data;
 	struct Node* next;
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
int main(int argc, char *argv[]) {
 	struct Dugum* ilk=NULL;
 	int sayi;
 	float ort;
 	int a=0;
 	printf("Sayi giriniz(-1 girerek islemi sonlandirabilirsiniz)\n");
 	while(1){
	 	printf("sayi:");
			scanf("%d",&sayi);
			if(sayi==-1){
				break;
		  	}
			 listeyeEkle(&ilk,sayi);
			 ort+=sayi;
			 a++;
	 	}
	 	
	 listYazdir(ilk);
	 printf("Ortalama:%f",ort/a);
	 
		return 0;
}
