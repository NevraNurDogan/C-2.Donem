#include <stdio.h>
#include <stdlib.h>

typedef struct Ogrenci {
    char numara[9];
    char ad[20];
    int vize;
    int final;
    float ortalama;
    struct Ogrenci* onceki;
    struct Ogrenci* sonraki;
} Ogrenci;

Ogrenci* bas = NULL;
Ogrenci* son = NULL;

void ListeyeEkle(char numara[9], char ad[20], int vize, int final) {
    Ogrenci* yeniOgrenci = (Ogrenci*)malloc(sizeof(Ogrenci));
    strcpy(yeniOgrenci->numara, numara);
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->vize = vize;
    yeniOgrenci->final = final;
    yeniOgrenci->ortalama = (vize * 0.4) + (final * 0.6);
    yeniOgrenci->onceki = NULL;
    yeniOgrenci->sonraki = NULL;

    if (yeniOgrenci->ortalama >= 60) {
        if (bas == NULL) {
            bas = yeniOgrenci;
            son = yeniOgrenci;
        } else {
            yeniOgrenci->sonraki = bas;
            bas->onceki = yeniOgrenci;
            bas = yeniOgrenci;
        }
    } else {
        if (son == NULL) {
            bas = yeniOgrenci;
            son = yeniOgrenci;
        } else {
            yeniOgrenci->onceki = son;
            son->sonraki = yeniOgrenci;
            son = yeniOgrenci;
        }
    }
}
void OgrenciGuncelle(char ad[20],int vize,int final) {
    Ogrenci* temp = bas;
    
    while (temp != NULL) {
        if (strcmp(temp->ad,ad) == 0) {
           
            
            temp->vize = vize;
            temp->final = final;
            temp->ortalama = (vize * 0.4) + (final * 0.6);
            
            printf("Ogrenci bilgileri guncellendi.\n");
            return;
        }
        
        temp = temp->sonraki;
    }
    printf("Ogrenci bulunamadi.\n");
}


void OgrenciSil(char ad[9]) {
    Ogrenci* temp = bas;
    
    while (temp != NULL) {
        if (strcmp(temp->ad, ad) == 0) {
            if (temp == bas && temp == son) {
                bas = NULL;
                son = NULL;
            } else if (temp == bas) { 
                bas = bas->sonraki;
                bas->onceki = NULL;
            } else if (temp == son) {
                son = son->onceki;
                son->sonraki = NULL;
            } else { 
                temp->onceki->sonraki = temp->sonraki;
                temp->sonraki->onceki = temp->onceki;
            }
            
            free(temp);
            return;
        }
        
        temp = temp->sonraki;
    }
    
    printf("��renci bulunamad�.\n");
}


void Sil(char secim[1]) {
    if (bas == NULL) {
        printf("Liste bo�, silinecek ��renci yok.\n");
        return;
    }
    
    if (secim [0] == 'b') { 
        Ogrenci* temp = bas;
        
        while (temp != NULL && temp->ortalama >= 60 ) {
            temp = temp->sonraki;
        }
        
        if (temp == NULL) {
            printf("Kalan �grenci bulunamad�.\n");
            return;
        }
        
        if (temp == bas) {
            bas = temp->sonraki;
            if (bas != NULL) {
                bas->onceki = NULL;
            }
        } else {
            temp->onceki->sonraki = temp->sonraki;
            if (temp->sonraki != NULL) {
                temp->sonraki->onceki = temp->onceki;
            }
        }
        
        free(temp);
    } else if (secim[0]  == 's') { 
        Ogrenci* temp = son;
        
        while (temp != NULL && temp->ortalama >= 60) {
            temp = temp->onceki;
        }
        
        if (temp == NULL) {
            printf("Kalan ��renci bulunamad�.\n");
            return;
        }
        
        if (temp == son) {
            son = temp->onceki;
            if (son != NULL) {
                son->sonraki = NULL;
            }
        } else {
            temp->sonraki->onceki = temp->onceki;
            if (temp->onceki != NULL) {
                temp->onceki->sonraki = temp->sonraki;
            }
        }
        
        free(temp);
    } else {
        printf("Gecersiz secim.\n");
        return;
    }
    
    printf("Ogrenci silindi.\n");
}


void Listele() {
    Ogrenci* temp = bas;
    printf("Gecen Ogrenciler:\n");
    while (temp != NULL) {
        printf("%s %s\t %d\t%d\t%.2f\n", temp->numara, temp->ad,temp->vize,temp->final, temp->ortalama);
        temp = temp->sonraki;
    }
    temp = son;
}
int main() {
    FILE* dosya = fopen("��renci.txt", "r"); 
   /*Menu tasarlarken 1 .ve 2. se�im aras�ndaki fark� tam anlayamad���m i�in dosyan�n i�indekileri
    �ift y�nl� ba�l� listeye ekleme i�ini 1 'de ,tekrar yazd�rma i�ini 2 de yapt�rd�m.
    Sonu� olarak di�er men�lerin �al��mas� i�in �ncelikli olarak se�im 1 �al��t�r�lmal�d�r. 
	Se�im 1'in �al��t�r�lmadan ba�ka men�ler �al��t�r�ld���nda kod �al��mayacakt�r.*/
	char tercih[1];
	printf("\t\tMENU\n");
	printf("1) ListeOlustur\n2) Listele\n3) Guncelle\n4) Sil\n0)Cikis\n");
	printf("Diger menulerin calismasi icin ilk secim olarak lutfen 1 giriniz.\n");
    int secim;
      do {
	    printf("Secim girin: ");          
    	scanf("%d", &secim);
    switch(secim){
    	case 1:
    	if (dosya == NULL) {
        printf("Dosya bulunamadi.");
        return 0;
        }
        char numara[9];
        char ad[20];
        int vize;
        int final;
        while (fscanf(dosya, "%s %s %d %d", numara, ad, &vize, &final) == 4) {
           ListeyeEkle(numara, ad, vize, final);
        }
       fclose(dosya);

    	case 2:Listele();
    		break;
    	case 3: printf("\nOgrenci bilgilerini guncellemek istediginiz ogrencinin adini girin: ");
        scanf("%s",ad); 
        printf("Yeni vize notunu girin:");          
    	scanf("%d", &vize);
        printf("Yeni final notunu girin:");
        scanf("%d", &final);
        OgrenciGuncelle(ad,vize,final);
        ListeyeEkle(numara, ad, vize, final);
        OgrenciSil(ad);
        Listele();
            break;
        case 4:
		 /*3." Sondan ve ba�tan silme i�lemini ger�ekle�tiriniz. �ift numaral� dersten ilk kalan ��renci silinecektir. Kullan�c� �s� 
          girerse sondan, �b� girerse ba�tan siliniz. "
         Maddesinin " �ift numaral� dersten ilk kalan ��renci silinecektir." k�sm�nda �ift numaral� olup da dersten kalan ��renci olmad��� 
		 ve tam olarak ne demek istedi�ini anlamad���m i�in kalan ��rencilerin girilen tercihe g�re ba��ndan ve sonundan silme i�lemi yapt�m*/
       printf("\nSilmek icin 's' (sondan) veya 'b' (bastan) girin:\n");
       scanf(" %c", tercih);
       Sil(tercih);
       Listele();
           	break;
        case 0:printf("Cikis Yapildi.");
           	break;  	
	   }
    } while(secim!=0);

    
    return 0;
}

