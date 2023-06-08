
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* N adet [10-50] arasý sayýlarý Tek yönlü baðlý listeye pozitif tam sayýlarý ekleyiniz.
Listenin ortalamasýndan küçük olan elemanlarýn tamamýný siliniz ve görüntüleyiniz.*/


struct Node {
    int data;
    struct Node *next;
};
int main(){
    int i;
    int n ;
    int sum = 0, avg;
    srand(time(NULL)); 
    printf("n degerini giriniz:");
    scanf("%d",&n);

    struct Node *head = NULL;
    struct Node *current = NULL;
    for (i = 0; i < n; i++) {
        int num = (rand() % 41+10);
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    printf("Liste: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    avg = sum / n;
    printf("Ortalama:%d\n",avg);
    
    struct Node *prev = NULL;
    current = head;
    while (current != NULL) {
        if (current->data < avg) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            struct Node *temp = current;
            current = current->next;
            free(temp);
            n--;
        } else {
            prev = current;
            current = current->next;
        }
    }

    printf("Ortalamadan buyuk olanlar: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}

