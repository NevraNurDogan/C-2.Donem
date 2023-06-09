#include <stdio.h>
#include <stdlib.h>

/* 5. Tekrar eden sayý varsa diðer sayýlarý siliniz.
6 4 4 2 2 => 6 4 2 olacaktýr. */

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
void deleteDuplicates(struct Dugum* ilk) {
    struct Dugum* gecici = ilk;

    while (gecici != NULL) {
        struct Dugum* runner = gecici;
        while (runner->next != NULL) {
            if (runner->next->data == gecici->data) {
                struct Dugum* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
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
	 	printf("Bagil liste: ");
		 listYazdir(ilk);
		 deleteDuplicates(ilk);
		 printf("Yeni bagil liste: ");
	 	 listYazdir(ilk);
	 	return 0;
}
