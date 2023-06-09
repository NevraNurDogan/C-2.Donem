#include <stdio.h>
#include <stdlib.h>

/*9. Listenin ortalamasýndan küçük olan elemanlarýn tamamýný siliniz. */

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
float calculateAverage(struct Dugum* ilk) {
    struct Dugum* current = ilk;
    float sum = 0.0, count = 0.0;
    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }
    printf("Ortalama: %f\n",sum / count);
    return sum / count;
}

// Ortalamadan küçük olan elemanlarý siler
void deleteLessThanAverage(struct Dugum** ilk) {
    float average = calculateAverage(*ilk);
    struct Dugum* current = *ilk;
    struct Dugum* prev = NULL;

    while (current != NULL) {
        if (current->data < average) {
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
		 deleteLessThanAverage(&ilk);
		 printf("Yeni bagil liste: ");
	 	 listYazdir(ilk);
	 	return 0;
}
