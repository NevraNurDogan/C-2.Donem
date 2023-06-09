#include <stdio.h>
#include <stdlib.h>
/*ogrNo ad vize final (Bu satır dosya içine dahil değildir! Bilgi amaçlı eklenmiştir.)
21010501 Ali 10 60
21010503 Veli 55 20
21010504 Sami 70 75
21010505 Yusuf 100 60
21010509 Ayse 90 40
21010511 Fatma 80 90
21010512 Sukru 50 100
21010513 Selman 45 50
21010514 Sema 85 60
21010515 Ahmet 60 70
Yukarıdaki veriler öğrenci.txt dosyasında yer almaktadır. Ogrenci numarası 8 hanelidir.
1. ogrenci.txt dosyası okunarak tüm öğrenciler çift yönlü bir bağlı listeye eklenecektir. Ekleme işleminde dersi 
geçenler (tümü) listenin baş tarafında, kalanlar ise son tarafında olacaktır. Sıralama işlemi yapılmasına gerek yoktur.
Geçme notu 60 alınız. Ort = vize*0.4 + final*0.6; Ort değeri bağlı listede yer almalıdır.
Bunun için ListeyeEkle ve Listele fonksiyonlarını yazınız. (40P) Dosya örnek amaçlı olup öğrenci ekleme/çıkarma 
yapılabilmelidir.
2. Öğrenci adı verilen kaydın yine vize ve final notunu kullanıcıdan alıp güncelleyiniz. Ardından da ortalama notunu 
güncelleyiniz. (40)
3. Sondan ve baştan silme işlemini gerçekleştiriniz. Çift numaralı dersten ilk kalan öğrenci silinecektir. Kullanıcı “s” 
girerse sondan, “b” girerse baştan siliniz. (40)
Bunun için bir menü tasarlayınız.
1) ListeOlustur
2) Listele
3) Güncelle
4) Sil
0) Çıkış*/
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
    
    printf("Öğrenci bulunamadı.\n");
}


void Sil(char secim[1]) {
    if (bas == NULL) {
        printf("Liste boş, silinecek öğrenci yok.\n");
        return;
    }
    
    if (secim [0] == 'b') { 
        Ogrenci* temp = bas;
        
        while (temp != NULL && temp->ortalama >= 60 ) {
            temp = temp->sonraki;
        }
        
        if (temp == NULL) {
            printf("Kalan ögrenci bulunamadı.\n");
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
            printf("Kalan öğrenci bulunamadı.\n");
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
    FILE* dosya = fopen("öğrenci.txt", "r"); 
   /*Menu tasarlarken 1 .ve 2. seçim arasındaki farkı tam anlayamadığım için dosyanın içindekileri
    çift yönlü bağlı listeye ekleme işini 1 'de ,tekrar yazdırma işini 2 de yaptırdım.
    Sonuç olarak diğer menülerin çalışması için öncelikli olarak seçim 1 çalıştırılmalıdır. 
	Seçim 1'in çalıştırılmadan başka menüler çalıştırıldığında kod çalışmayacaktır.*/
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
		 /*3." Sondan ve baştan silme işlemini gerçekleştiriniz. Çift numaralı dersten ilk kalan öğrenci silinecektir. Kullanıcı “s” 
          girerse sondan, “b” girerse baştan siliniz. "
         Maddesinin " Çift numaralı dersten ilk kalan öğrenci silinecektir." kısmında çift numaralı olup da dersten kalan öğrenci olmadığı 
		 ve tam olarak ne demek istediğini anlamadığım için kalan öğrencilerin girilen tercihe göre başından ve sonundan silme işlemi yaptım*/
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

