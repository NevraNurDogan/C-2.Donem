#include <stdio.h>

#define MAX_SIZE 5
//3. 10 say�s�ndan b�y�k tek ve 3�e tam b�l�nen ilk 5 adet tam say�y� diziye alan ve b�y�kten k����e yazd�ran program kodunu yaz�n�z.
int main() {
    int i,j, count = 0;
    int *arr = (int *)malloc(MAX_SIZE * sizeof(int));
    int num = 11;  
    if (arr == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return 1; 
    }

    while (count < MAX_SIZE) {
        if (num % 2 == 1 && num % 3 == 0) {
            arr[count] = num;
            count++;
        }
        num++;
    }

    for ( i = 0; i < MAX_SIZE - 1; i++) {
        for ( j = i + 1; j < MAX_SIZE; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

   
    printf("Buyukten kucuge siralanmis dizi: ");
    for ( i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
     free(arr);

    return 0;
}
