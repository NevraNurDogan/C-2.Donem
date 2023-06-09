#include <stdio.h>
#include <stdlib.h>

/*7. Kullan�c�n�n istedi�i mod�ler sistemde elemanlar� siliniz. 
Mod giriniz: 2, (Dolay�s�yla Index=2 ve katlar�n� silinecektir.)
20 10 6 4 3 2 1 => 20 6 3 1 olacakt�r */


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
		 printf("Liste bos.\n");
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


// Ortalamadan k���k olan elemanlar� siler
void deleteList(struct Dugum** ilk,int mod ) {
    struct Dugum* current = *ilk;
    struct Dugum* prev = NULL;
     int index = 1; 

    while (current != NULL) {
        if (index % mod == 0) {
            if (prev == NULL) {
                *ilk = current->next;
                free(current);
                current = *ilk;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
        index++;
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
		 int mod;
		 printf("Mod giriniz:");
		 scanf("%d",&mod);
		 deleteList(&ilk,mod);
		 printf("Yeni bagil liste: ");
	 	 listYazdir(ilk);
	 	return 0;
}
