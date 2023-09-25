#include <stdio.h>
#include <stdlib.h>

/* 7. int sayilar[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
Yukarýdaki sayý dizisinde çift sayýlarý tek sayýya (kendinden bir sonraki sayýya) çeviren 
program kodunu yazýnýz. 20->21, 60->61 þeklinde olacaktýr */

#include <stdio.h>

int main() {
   int sayilar[] = { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
   int *ptr, i;
   ptr = sayilar;
   for (i = 0; i < 14; i++) {
      if ( *ptr% 2 == 0) {
        *ptr+=1;
      }
      ptr++;
   }
   printf("Yeni dizinin elemanlari: ");
   ptr=sayilar;
   for (i = 0; i < 14; i++) {
      printf("%d ",*ptr);
      ptr++;
   }
   printf("\n");

   return 0;
}
