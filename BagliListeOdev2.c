
#include <stdio.h>
#include <stdlib.h>
/*Sayý dizisi: [21, 40, 30, 25, 50, 24, 14, 6, 27]
Öncelik dizisi: [1, 2, 3, 1, 1, 2, 3, 1, 3]
Yukarýda verilen sayý dizisi kullanýlarak tek yönlü baðlý listeye sýrasýyla ekleme iþlemi yapýlacaktýr.
1. Baðlý listeye ekleme iþlemi öncelik sýrasý dikkate alýnarak küçüðe büyüðe doðru yapýlacaktýr.
(50P) 1 en baþta 2 ortada 3 ise sonda olmalýdýr. Her bir sýralama iþlemi öncelik dizisi dikkate 
alýnarak yapýlmalýdýr. 
Not: Sýralama iþlemi baðlý listeye ekleme yapýlýrken gerçekleþtirilmelidir.
Dizi üzerinde sýralama yapýlarak gerçekleþtirilen iþlemler deðerlendirmeye alýnmayacaktýr.
21
21 40
21 40 30
21 25 40 30
21 25 50 40 30
21 25 50 24 40 30
21 25 50 24 40 14 30
6 21 25 50 24 40 14 30
6 21 25 50 24 40 14 27 30
2. En son oluþan listede yer deðiþtirme iþlemi yapýlacaktýr. Kullanýcýdan mevcut ve yeni konum 
olmak üzere iki öncelik deðer (1, 2 ya da 3) bilgisi istenecek ve buna göre öncelik deðerdeki ilk 
düðümlerin yeri deðiþtirilecektir. Ayrýca öncelik deðerleri de deðiþtirilecektir. (50P)
Not: Sadece sayýlar üzerinde yapýlan yer deðiþtirme iþlemi deðerlendirmeye alýnmayacaktýr.
Örnek: 1 ve 3 girildi ise
1 önceliðe sahip 6, 3 deðerine sahip 14 olduðundan;
6 21 25 50 24 40 14 27 30
14 21 25 50 24 40 6 27 30
6 öncelik deðeri 1 iken 3; 14 öncelik deðeri 3 iken 1 yapýlmýþtýr.
Örnek: 2 ve 3 girildi ise
14 21 25 50 24 40 6 27 30
14 21 25 50 6 40 24 27 30
6 öncelik deðeri 3 iken 2; 24 öncelik deðeri 2 iken 3 yapýlmýþtýr. -1 girildi iþlem sonlarýldý.*/
struct node {
    int data;
    int priority;
    struct node* next;
};

void insert(struct node** head_ref, int new_priority, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->priority = new_priority;

    if (*head_ref == NULL || new_priority < (*head_ref)->priority || (new_priority == (*head_ref)->priority && new_data < (*head_ref)->data)) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        struct node* current = *head_ref;
        while (current->next != NULL && (new_priority > current->next->priority || (new_priority == current->next->priority && new_data > current->next->data))) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void print_list(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}



void changePriority(struct node** head_ref, int currentPriority, int newPriority) {
    if (currentPriority == newPriority) {
  
        printf("Ayni oncelik degerleri girildi.\n");
        return;
    }

    struct node* current = (*head_ref);
    struct node* previousCurrent = NULL;
    struct node* new = NULL;
    struct node* previousNew = NULL;

   
    while (current != NULL && current->priority != currentPriority) {
        previousCurrent = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Oncelik degeri %d olan bir dugum bulunamadi.\n", currentPriority);
        return;
    }

   
    new = (*head_ref);
    while (new != NULL && new->priority != newPriority) {
        previousNew = new;
        new = new->next;
    }

    if (new == NULL) {
        printf("Oncelik degeri %d olan bir dugum bulunamadi.\n", newPriority);
        return;
    }

  
    if (previousCurrent != NULL) {
        previousCurrent->next = new;
    } else {
        (*head_ref) = new;
    }

    
    if (previousNew != NULL) {
        previousNew->next = current;
    } else {
        (*head_ref) = current;
    }


    struct node* temp = current->next;
    current->next = new->next;
    new->next = temp;
}




int main() {
    int i;
    int currentPriority, newPriority;
    int numbers[] = {21, 40, 30, 25, 50, 24, 14, 6, 27};
    int priorities[] = {1, 2, 3, 1, 1, 2, 3, 1, 3};
    struct node* head = NULL;
    int length = sizeof(numbers) / sizeof(numbers[0]);
    for (i = 0; i < length; i++) {
        insert(&head, priorities[i], numbers[i]);
        print_list(head);
    }
    
 
	printf("Degistirilecek oncelik degerini giriniz: ");
    scanf("%d", &currentPriority);
    printf("Yeni oncelik degerini giriniz: ");
    scanf("%d", &newPriority);
    changePriority(&head, currentPriority, newPriority);
    print_list(head);
	

    return 0;
}

