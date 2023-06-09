#include <stdio.h>
#include <stdlib.h>

/*8. Kullanýcýnýn istediði sýradaki elemaný yine kullanýcýnýn belirleyeceði yeni sýrayla yer 
deðiþtiriniz.
Index 1, Index 5 ise
20 10 6 4 3 2 1 => 3 10 6 4 20 2 1*/

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
// Belirtilen indeksteki elemaný taþýma
void moveElement(struct Dugum** ilk, int index, int newIndex) {
    if (index == newIndex) {
        return;
    }
    
    struct Dugum* prev1 = NULL;
    struct Dugum* curr1 = *ilk;
    int count1 = 0;
    while (curr1 != NULL && count1 != index) {
        prev1 = curr1;
        curr1 = curr1->next;
        count1++;
    }
    
    struct Dugum* prev2 = NULL;
    struct Dugum* curr2 = *ilk;
    int count2 = 0;
    while (curr2 != NULL && count2 != newIndex) {
        prev2 = curr2;
        curr2 = curr2->next;
        count2++;
    }
    
    if (curr1 == NULL || curr2 == NULL) {
        return;
    }
    
    if (prev1 != NULL) {
        prev1->next = curr2;
    } else {
        *ilk = curr2;
    }
    
    if (prev2 != NULL) {
        prev2->next = curr1;
    } else {
        *ilk = curr1;
    }
    
    struct Dugum* temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
}

int main(int argc, char *argv[]) {
 	struct Dugum* ilk=NULL;
 	int index, newIndex;
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
		 
         printf("Taþýmak istediðiniz elemanýn indeksini girin: ");
         scanf("%d", &index);
    
         printf("Elemanýn yeni hedef indeksini girin: ");
         scanf("%d", &newIndex);
                
         moveElement(&ilk, index, newIndex);
		 printf("Yeni bagil liste: ");
	 	 listYazdir(ilk);
	 	 
	 	 
	 	return 0;
}
