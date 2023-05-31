#include <stdio.h>
#include <stdlib.h>

/*1.Integer sayýlardan oluþan Ýkili bir aðaç oluþturunuz*/
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
void inorderYazdir(struct Agac* kok) {
    if (kok != NULL) {
        inorderYazdir(kok->sol);
        printf("%d ", kok->sayi);
        inorderYazdir(kok->sag);
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

	return 0;
}
