
#include <stdio.h>
#include <stdlib.h>
/*Say� dizisi: [21, 40, 30, 25, 50, 24, 14, 6, 27]
�ncelik dizisi: [1, 2, 3, 1, 1, 2, 3, 1, 3]
Yukar�da verilen say� dizisi kullan�larak tek y�nl� ba�l� listeye s�ras�yla ekleme i�lemi yap�lacakt�r.
1. Ba�l� listeye ekleme i�lemi �ncelik s�ras� dikkate al�narak k����e b�y��e do�ru yap�lacakt�r.
(50P) 1 en ba�ta 2 ortada 3 ise sonda olmal�d�r. Her bir s�ralama i�lemi �ncelik dizisi dikkate 
al�narak yap�lmal�d�r. 
Not: S�ralama i�lemi ba�l� listeye ekleme yap�l�rken ger�ekle�tirilmelidir.
Dizi �zerinde s�ralama yap�larak ger�ekle�tirilen i�lemler de�erlendirmeye al�nmayacakt�r.
21
21 40
21 40 30
21 25 40 30
21 25 50 40 30
21 25 50 24 40 30
21 25 50 24 40 14 30
6 21 25 50 24 40 14 30
6 21 25 50 24 40 14 27 30
2. En son olu�an listede yer de�i�tirme i�lemi yap�lacakt�r. Kullan�c�dan mevcut ve yeni konum 
olmak �zere iki �ncelik de�er (1, 2 ya da 3) bilgisi istenecek ve buna g�re �ncelik de�erdeki ilk 
d���mlerin yeri de�i�tirilecektir. Ayr�ca �ncelik de�erleri de de�i�tirilecektir. (50P)
Not: Sadece say�lar �zerinde yap�lan yer de�i�tirme i�lemi de�erlendirmeye al�nmayacakt�r.
�rnek: 1 ve 3 girildi ise
1 �nceli�e sahip 6, 3 de�erine sahip 14 oldu�undan;
6 21 25 50 24 40 14 27 30
14 21 25 50 24 40 6 27 30
6 �ncelik de�eri 1 iken 3; 14 �ncelik de�eri 3 iken 1 yap�lm��t�r.
�rnek: 2 ve 3 girildi ise
14 21 25 50 24 40 6 27 30
14 21 25 50 6 40 24 27 30
6 �ncelik de�eri 3 iken 2; 24 �ncelik de�eri 2 iken 3 yap�lm��t�r. -1 girildi i�lem sonlar�ld�.*/
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

