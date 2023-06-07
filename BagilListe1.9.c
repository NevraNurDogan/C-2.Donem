#include <stdio.h>
#include <stdlib.h>

/* 9. Bir sonraki sayý kendinden küçük olduðu sürece sayýlarý ekrana yazdýrýnýz. Varsa diðer sayý 
dizileri de yazdýrýlacaktýr. Bu örnekte tek bir sayý dizisi bulunmaktadýr.
Sonuç: 1, 10, 20, 50, 90 olacaktýr. Çünkü 1<10, 10<20, 20<50, 50<90*/

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
void printNumbers(struct Dugum* bas) {
    struct Dugum* gecici = bas;
    while (gecici != NULL && gecici->next != NULL) {
        if (gecici->next->data > gecici->data) {
            printf("%d ", gecici->data);
            gecici = gecici->next;
        } else {
            break;
        }
    }
   printf("%d\n", gecici->data);
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

	 	printf("Bagli listedeki cift sayi ikilileri: ");
        printNumbers(ilk);
	
 	
		return 0;
}
