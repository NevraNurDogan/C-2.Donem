#include <stdio.h>
#include <stdlib.h>

/* 6. Kullanýcýnýn istediði sýradaki elemaný yine kullanýcýnýn belirleyeceði yeni sýraya gönderiniz.
MevcutIndex: 1, YeniIndex=3
6 4 3 2 1 => 4 3 6 2 1*/

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
		// printf("Bagil liste: ");
         while (gecici != NULL) {
            printf("%d ", gecici->data);
            gecici = gecici->next;
     	}
  	printf("\n");
     }
}
void changeNodeOrder(struct Dugum** ilk, int currentIndex, int newIndex) {
int i;
    if (currentIndex == newIndex || *ilk == NULL){ return;

	}
       
    struct Dugum* current = *ilk;
    struct Dugum* prev = NULL;

    // Mevcut sýradaki düðümü bulma
    for (i = 1; current != NULL && i < currentIndex; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL){  return;

	}
      
    // Mevcut düðümü baðlý listeden çýkar
    if (prev != NULL){prev->next = current->next;
	}
        
    else{*ilk = current->next;

	}
        
    // Yeni sýradaki düðümü bulma
    struct Dugum* newPrev = NULL;
    struct Dugum* newCurrent = *ilk;
    for ( i = 1; newCurrent != NULL && i < newIndex; i++) {
        newPrev = newCurrent;
        newCurrent = newCurrent->next;
    }

    // Yeni sýradaki düðümü mevcut düðümün önüne yerleþtir
    if (newPrev != NULL){newPrev->next = current;
	}
        
    else{*ilk = current;
	}
        
    current->next = newCurrent;
}




int main(int argc, char *argv[]) {
 	struct Dugum* ilk=NULL;
 	int currentIndex, newIndex;
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
	 	printf("Bagil liste: ");
		 listYazdir(ilk);
		 printf("Mevcut Index Degerini Giriniz: ");
         scanf("%d", &currentIndex);
 
         printf("Yeni Index Degerini Giriniz: ");
         scanf("%d", &newIndex);

		 changeNodeOrder(&ilk ,currentIndex,  newIndex);
		 printf("Yeni bagil liste: ");
	 	 listYazdir(ilk);
	 	 struct Dugum* temp;
    while (ilk != NULL) {
        temp = ilk;
        ilk = ilk->next;
        free(temp);
    }

	 	 
	 	return 0;
}
