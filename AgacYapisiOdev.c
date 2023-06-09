
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
1. ogrenci.txt dosyası okunarak tüm öğrenciler ikili bir ağaç yapısına eklenecektir. Ekleme işlemi 2 şekilde
yapılacaktır. Kullanıcı “n” girerse öğrenciNumarası, “o” ise ortalamaya göre ikili arama ağacına eklenecektir.
Ort = vize*0.4 + final*0.6; Ort değeri ağaç yapısı içinde yer almalıdır.
Bunun için AğacaEkle ve Listele fonksiyonlarını yazınız. (60P) Dosya örnek amaçlı olup öğrenci ekleme/çıkarma 
yapılabilmelidir. Listeleme işlemini InOrder olarak yapabilirsiniz. 
Not: InOrder ile ağaca sırayla eklendiğinden ve sıralama işleminin doğru olduğundan emin olunuz.
2. Öğrenci adı verilen kaydın yine vize ve final notunu kullanıcıdan alıp güncelleyiniz. Ardından da ortalama notunu 
güncelleyiniz. (40P)
3. Öğrenci numarası verilen düğümü silip (ilgili düğümler için ) ağacı yeniden oluşturunuz. (Bonus: 50P)
Bunun için bir menü tasarlayınız.
1) AgacOlustur
2) Listele
3) Güncelle
4) Sil
0) Çıkış*/

struct Ogrenci {
    int ogrenciNumarasi;
    char ad[50];
    int vizeNotu;
    int finalNotu;
    float ortalama;
    struct Ogrenci* sol;
    struct Ogrenci* sag;
};

struct Ogrenci* dugumOlustur(int numara, const char* ad, int vize, int final) {
    struct Ogrenci* yeniDugum = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniDugum->ogrenciNumarasi = numara;
    strcpy(yeniDugum->ad, ad);
    yeniDugum->vizeNotu = vize;
    yeniDugum->finalNotu = final;
    yeniDugum->ortalama = (0.4 * vize) + (0.6 * final);
    yeniDugum->sol = NULL;
    yeniDugum->sag = NULL;
    return yeniDugum;
}

struct Ogrenci* ekleAgaca(struct Ogrenci* kok, struct Ogrenci* yeniDugum) {
    if (kok == NULL) {
        return yeniDugum;
    } else {
        if (yeniDugum->ogrenciNumarasi <= kok->ogrenciNumarasi) {
            kok->sol = ekleAgaca(kok->sol, yeniDugum);
        } else {
            kok->sag = ekleAgaca(kok->sag, yeniDugum);
        }
        return kok;
    }
}

void inorderListele(struct Ogrenci* dugum) {
    if (dugum != NULL) {
        inorderListele(dugum->sol);
        printf("%d %s %d %d %.2f\n", dugum->ogrenciNumarasi, dugum->ad, dugum->vizeNotu, dugum->finalNotu, dugum->ortalama);
        inorderListele(dugum->sag);
    }
}

struct Ogrenci* ara(struct Ogrenci* kok, int numara) {
    if (kok == NULL || kok->ogrenciNumarasi == numara) {
        return kok;
    }
    if (numara < kok->ogrenciNumarasi) {
        return ara(kok->sol, numara);
    }
    return ara(kok->sag, numara);
}

struct Ogrenci* maxDugumBul(struct Ogrenci* kok) {
    if (kok == NULL || kok->sag == NULL) {
        return kok;
    }
    return maxDugumBul(kok->sag);
}

struct Ogrenci* sil(struct Ogrenci* kok, int numara) {
    if (kok == NULL) {
        return kok;
    }
    if (numara < kok->ogrenciNumarasi) {
        kok->sol = sil(kok->sol, numara);
    } else if (numara > kok->ogrenciNumarasi) {
        kok->sag = sil(kok->sag, numara);
    } else {
        if (kok->sol == NULL) {
            struct Ogrenci* temp = kok->sag;
            free(kok);
            return temp;
        } else if (kok->sag == NULL) {
            struct Ogrenci* temp = kok->sol;
            free(kok);
            return temp;
        }
        struct Ogrenci* temp = maxDugumBul(kok->sol);
        kok->ogrenciNumarasi = temp->ogrenciNumarasi;
        strcpy(kok->ad, temp->ad);
        kok->vizeNotu = temp->vizeNotu;
        kok->finalNotu = temp->finalNotu;
        kok->ortalama = temp->ortalama;
        kok->sol = sil(kok->sol, temp->ogrenciNumarasi);
    }
    return kok;
}

void menu() {
    printf("----- MENU -----\n");
    printf("1) AgacOlustur\n");
    printf("2) Listele\n");
    printf("3) Guncelle\n");
    printf("4) Sil\n");
    printf("0) Cikis\n");
    printf("----------------\n");
}

int main() {
    struct Ogrenci* kok = NULL;
    FILE* dosya = fopen("C:\\Users\\Casper\\OneDrive\\Masaüstü\\öğrenci.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return 1;
    }

    int ogrenciNumarasi, vizeNotu, finalNotu;
    char ad[50];
    float ortalama;

    while (fscanf(dosya, "%d %s %d %d", &ogrenciNumarasi, ad, &vizeNotu, &finalNotu) != EOF) {
        struct Ogrenci* yeniDugum = dugumOlustur(ogrenciNumarasi, ad, vizeNotu, finalNotu);
        kok = ekleAgaca(kok, yeniDugum);
    }

    fclose(dosya);

    int secim;
    do {
        menu();
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);
        switch (secim) {
            case 1: {
                int numara;
                char ad[50];
                int vize;
                int final;
                printf("Ogrenci numarasini girin: ");
                scanf("%d", &numara);
                printf("Adi girin: ");
                scanf("%s", ad);
                printf("Vize notunu girin: ");
                scanf("%d", &vize);
                printf("Final notunu girin: ");
                scanf("%d", &final);
                struct Ogrenci* yeniDugum = dugumOlustur(numara, ad, vize, final);
                kok = ekleAgaca(kok, yeniDugum);
                break;
            }
            case 2: {
                printf("Ogrenciler:\n");
                inorderListele(kok);
                break;
            }
            case 3: {
                int numara;
                printf("Guncellenecek ogrencinin numarasini girin: ");
                scanf("%d", &numara);
                struct Ogrenci* ogrenci = ara(kok, numara);
                if (ogrenci == NULL) {
                    printf("Ogrenci bulunamadi.\n");
                    break;
                }
                int yeniVize, yeniFinal;
                printf("Yeni vize notunu girin: ");
                scanf("%d", &yeniVize);
                printf("Yeni final notunu girin: ");
                scanf("%d", &yeniFinal);
                ogrenci->vizeNotu = yeniVize;
                ogrenci->finalNotu = yeniFinal;
                ogrenci->ortalama = (0.4 * yeniVize) + (0.6 * yeniFinal);
                break;
            }
            case 4: {
                int numara;
                printf("Silinecek ogrencinin numarasini girin: ");
                scanf("%d", &numara);
                kok = sil(kok, numara);
                break;
            }
            case 0:
                printf("Programdan cikiliyor.\n");
                break;
            default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
                break;
        }
    } while (secim != 0);

    return 0;
}



