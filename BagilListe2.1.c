#include <stdio.h>
#include <stdlib.h>

/* 1. Tek yönlü baðlý listeye kullanýcý tarafýndan girilen sayýlar büyükten küçüðe olacak þekilde
baðlý listeye elemanlarý ekleyiniz. -1 girildiðinde iþlemi tamamlayýnýz.
4
6 4
6 4 1
6 4 3 1
6 4 3 2 1 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
     int data;
     struct Node* next;
};

void insert(struct Node** head, int value) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = value;
     newNode->next = NULL;
     
     if (*head == NULL || value > (*head)->data) {
        newNode->next = *head;
        *head = newNode;
     } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data > value) {
            current = current->next;
         }
         newNode->next = current->next;
         current->next = newNode;
     }
}

void display(struct Node* head) {
     struct Node* current = head;
     while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
     }
     printf("\n");
}

void freeList(struct Node* head) {
     struct Node* current = head;
     while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
     }
}

int main() {
     struct Node* head = NULL;
     int number;
  
     printf("Sayilari girin (Cikis icin -1): \n");
     while (1) {
         scanf("%d", &number);
         if (number == -1) {
            break;
         }
         insert(&head, number);
         display(head);
     }
     freeList(head);

    return 0;
}

