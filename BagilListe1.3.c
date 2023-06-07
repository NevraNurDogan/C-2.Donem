#include <stdio.h>
#include <stdlib.h>
/* 3. Ortalamadan büyük olan sayýlarý yeni bir baðlý listeye gönderiniz ve ekrana yazdýrýnýz.*/

struct Dugum {
    int data;
    struct Dugum* next;
};

void listeyeEkle(struct Dugum** bas, int data) {
     struct Dugum* yenidugum = (struct  Dugum*)malloc(sizeof(struct  Dugum));
     if (yenidugum  == NULL) {
        printf("Bellek hatasý: Yeni düðüm oluþturulamadý.\n");
        exit(1);
     }
     yenidugum ->data = data;
     yenidugum ->next = NULL;

     if (*bas == NULL) {
         *bas = yenidugum ;
     }  else {
         struct  Dugum* gecici = *bas;
         while (gecici->next != NULL) {
            gecici = gecici->next;
         }
        gecici->next = yenidugum ;
     }
}


void printList(struct  Dugum* bas) {
     struct Dugum* gecici = bas;
     if (gecici == NULL) {
        printf("Liste boþ.\n");
     } else {
         while (gecici != NULL) {
             printf("%d ", gecici->data);
             gecici = gecici->next;
         }
         printf("\n");
     }
}

int main() {
    struct  Dugum* ilkList = NULL;
    struct  Dugum* sonList = NULL;
    int count = 0;
    int sum = 0;

    printf("Sayilari girin (sonlandirmak icin -1):\n");

    while (1) {
        int num;
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        listeyeEkle(&ilkList, num);
        count++;
        sum += num;
     }

        double average = (double)sum / count;
        printf("Girilen sayilarin ortalamasi: %.2f\n", average);
        struct  Dugum* gecici = ilkList;
        
        while (gecici != NULL) {
            if (gecici->data > average) {
                listeyeEkle(&sonList, gecici->data);
            }
            gecici = gecici->next;
        }

        printf("Ortalamadan buyuk sayilarin listesi: ");
        printList(sonList);
    

    return 0;
}

