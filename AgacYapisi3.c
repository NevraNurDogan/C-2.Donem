#include <stdio.h>
#include <stdlib.h>

/*2.3. Aðaçtaki en küçük sayýyý bulunuz. Max-min sayýlar arasýndaki farký bulunuz. */

struct Agac{
	int sayi ;
	struct Agac* sag;
	struct Agac* sol;
	
};

 struct Agac* agacOlustur(struct Agac *kok,int sayi){
 	if (kok==NULL){
 	struct	Agac* kok=(struct Agac*)malloc(sizeof(struct Agac));
	kok->sayi=sayi;
	kok->sol=NULL;
	kok->sag=NULL;
	return kok;
	 }
	 if(sayi< kok->sayi){
	 	kok->sol=agacOlustur(kok->sol, sayi);
	 	return kok;
	
	 }
	 	kok->sag=agacOlustur(kok->sag, sayi);
	 	return kok;
}
int enBuyukBul(struct Agac* kok) {
    if (kok == NULL) {
        printf("Aðaç boþ!\n");
        return -1;
    } else {
        while (kok->sag != NULL) {
            kok = kok->sag;
        }
        return kok->sayi;
    }
}
int enKucukBul(struct Agac* kok) {
    if (kok == NULL) {
        printf("Aðaç boþ!\n");
        return -1;
    } else {
        while (kok->sol != NULL) {
            kok = kok->sol;
        }
        return kok->sayi;
    }
}
void preorderYazdir(struct Agac* kok) {
	if (kok==NULL){
		return;
		}
   
        printf("\n%d ", kok->sayi);
        preorderYazdir(kok->sol);
        preorderYazdir(kok->sag);
    
}


int main(int argc, char *argv[]) {
	struct Agac *kok=NULL;
	int sayi;
	printf("Sayi giriniz(-1 girerek durdurunuz.)\n");
	printf("Sayi:");
	scanf("%d",&sayi);
	kok=agacOlustur(kok,sayi);
	while(1){
		printf("Sayi:");
		scanf("%d",&sayi);
		if(sayi==-1){
			break;
		}
		agacOlustur(kok,sayi);
	}
	preorderYazdir(kok);
	int enBuyuk = enBuyukBul(kok);
    printf("\nEn buyuk sayi: %d\n", enBuyuk);
    int enKucuk = enKucukBul(kok);
    printf("En kucuk sayi: %d\n", enKucuk);
    printf("Fark: %d", enBuyuk-enKucuk);


	return 0;
}
