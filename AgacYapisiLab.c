#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Random olarak [10-50] arasýnda üretmiþ olduðunuz N tane integer sayýyý ikili arama aðacýna ekleyiniz. 30P
Ortalamadan büyük sayýlarý küçükten büyüðe sýralý yazdýrýnýz. 70P
N deðerini kullanýcýdan alýn. */

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

void preorderYazdir(struct Agac* kok) {
	if (kok==NULL){
		return;
		}
        printf("\n%d ", kok->sayi);
        preorderYazdir(kok->sol);
        preorderYazdir(kok->sag);
    
}
int hesaplaToplam(struct Agac* kok) {
    if (kok == NULL) {
        return 0;
    }
    return kok->sayi + hesaplaToplam(kok->sol) + hesaplaToplam(kok->sag);
}

int hesaplaDugumSayisi(struct Agac* kok) {
    if (kok == NULL) {
        return 0;
    }
    return 1 + hesaplaDugumSayisi(kok->sol) + hesaplaDugumSayisi(kok->sag);
}

float hesaplaOrtalama(struct Agac* kok) {
    int toplam = hesaplaToplam(kok);
    int dugumSayisi = hesaplaDugumSayisi(kok);
    return (float)toplam / dugumSayisi;
}
void inorderYazdirOrtalamadanBuyuk(struct Agac* kok, int ortalama) {
    if (kok != NULL) {
        inorderYazdirOrtalamadanBuyuk(kok->sol, ortalama);
        if (kok->sayi > ortalama) {
            printf("%d\t ", kok->sayi);
        }
        inorderYazdirOrtalamadanBuyuk(kok->sag, ortalama);
    }
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	struct Agac *kok=NULL;
	int sayi,n,i;
	float ort;
	printf("Kac sayi girmek istediginizi giriniz.\n");
	scanf("%d",&n);
	printf("Sayi:");
	sayi= rand() % 41 + 10;
	printf("%d\n",sayi);

	kok=agacOlustur(kok,sayi);
	for(i=1;i<n;i++){
		printf("Sayi:");
		sayi= rand() % 41 + 10;
		printf("%d\n",sayi);	
		agacOlustur(kok,sayi);
	}
	preorderYazdir(kok);
	float ortalama = hesaplaOrtalama(kok);
    printf("\nOrtalama: %f\n",ortalama);
    printf("Ortalamadan buyuk sayilarin kucukten buyuge sirali hali:\t");
    inorderYazdirOrtalamadanBuyuk(kok, ortalama);

	return 0;
}
