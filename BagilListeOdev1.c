#include <stdio.h>
#include <stdlib.h>
/*Aşağıdaki şekilde bir menü tasarlayınız. Çıkış işlemine kadar tüm işlemler yerine getirilmelidir.
1 ve 2 nolu işlemler ilk aşamada gerçekleştirilmesi gerekmektedir.
Menü:
1. Sayı Üret
2. Bağlı Liste Oluştur
3. Ortalamaya Göre Sil
4. Sıralı Birleştir
5. Çıkış
1. Kullanıcı tarafından N sayısı girilecektir. N sayısı kadar rastgele (random fonksiyonu ile) şekilde 
20-50 arasında (sayılar dâhil) pozitif tam sayılar üretilecektir.
Örnek N: 8 ise;
21, 40, 30, 25, 24, 34, 37, 50
2. Üretilen rastgele sayılar, kullanıcının girdiği sayıdan küçük ya da büyük olmak üzere iki farklı 
tek yönlü bağlı liste oluşturulacaktır ve listeler aşağıdaki gibi yazdırılacaktır. (50P)
Eşik Değeri: 30
Küçük Sayı Listesi => 21, 30, 25, 24
Büyük Sayı Listesi => 40, 34, 37, 50
3. Üretilen bağlı listeler kendi içinde ortalamadan büyük olan ilk sayıyı siliniz. (50P)
Küçük Sayı Listesi => Ortalama: 25.00 30 silinecek… Yeni Liste: 21 -> 25 -> 24
Büyük Sayı Listesi => Ortalama: 40.25 50 silinecek… Yeni Liste: 40 -> 34 -> 37
4. Her iki bağlı liste kullanılarak üçüncü ve yeni iki ayrı tek yönlü bağlı listeye TEK ya da ÇİFT sayılar
sırayla eklenecektir. (Bonus: +50P)
Ortak ve Sıralı Yeni Bağlı Liste TEK: 21, 25, 37
Ortak ve Sıralı Yeni Bağlı Liste ÇİFT: 24, 34, 40*/
typedef struct node {
    int data;
    struct node* next;
} Node;

Node* insert(Node* head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

void print_list(Node* head) {
    if(head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    while(head != NULL) {
        printf("%d , ", head->data);
        head = head->next;
    }
    printf("\n");
}
void new_print_list(Node* head,int ort) {
    if(head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    while(head != NULL && head->data <=ort ) {
        printf("%d , ", head->data); 
        head = head->next;
    }
    printf("\n");
}
void deleteNodeGreaterThanAverage(struct node** headRef) {
    struct node* current = *headRef;
    struct node* previous = NULL;
    double sum = 0;
    int count = 0;

    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }


    double average = sum / count;

    current = *headRef;
    while (current != NULL && current->data <= average) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Listede ortalamadan büyük bir eleman bulunamadý.\n");
    } else {
        if (previous == NULL) {
            
            *headRef = current->next;
        } else {
            
            previous->next = current->next;
        }
        free(current);
    }
}

int main() {
    int n, esik, i,a=0,b=0, sayi;
    float kucuk_ort=0,buyuk_ort=0;
    Node *kucuk_list = NULL, *buyuk_list = NULL;
    
    printf("Eleman sayisini giriniz:");
    scanf("%d", &n);
    
    printf("Esik degerini giriniz: ");
    scanf("%d", &esik);
    printf("List: ");
    for(i=0; i<n; i++) {
        sayi = 20 + (rand() % 31);
        printf("%d ",sayi);
        if(sayi <= esik) {
            kucuk_list = insert(kucuk_list, sayi);
            a++;
            kucuk_ort+=sayi;
            
        } else {
           buyuk_list = insert(buyuk_list,sayi);
           b++;
           buyuk_ort+=sayi;
        }
    }
    
    printf("\nKucuk Sayi Listesi =>");
    print_list(kucuk_list);
    printf("Buyuk Sayi Listesi =>");
    print_list(buyuk_list);
    printf("Kucuk Sayi Listesi => Ortalama :%f ",kucuk_ort/a);
    printf("\nBuyuk Sayi Listesi => Ortalama :%f\n ",buyuk_ort/b);
    deleteNodeGreaterThanAverage(kucuk_list);
    print_list(kucuk_list);
    
    return 0;
}

