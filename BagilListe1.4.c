#include <stdio.h>
#include <stdlib.h>

/* 4. Rekürsif olarak baðlý listeye yer alan sayýlarý tersten ekrana yazdýrýnýz.
9, 12, 50… þeklinde*/
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
void tersYazdir(struct Dugum* bas) {
    if (bas == NULL) {
        return;
    }
    tersYazdir(bas->next);
    printf("%d ", bas->data);
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
	 printf("Bagli liste (tersten): ");
     tersYazdir(ilk);
		return 0;
}
