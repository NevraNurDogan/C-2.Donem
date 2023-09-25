#include <stdio.h>
#include <stdlib.h>

/* 6. int sayilar[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
Yukar�daki say� dizisinde yan yana ka� tane �ift say� ikilisi oldu�unu bulan program 
kodunu yaz�n�z. 20-60, 24-26, 50-30, 30-40 �eklinde 4 adet olarak ekrana yazd�r�lacakt�r. */

int main() {
   int sayilar[] = { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
   int *ptr, i;
   int count = 0;

   ptr = sayilar;
   for (i = 0; i < 13; i++) {
      if (*ptr % 2 == 0 && *(ptr+1) % 2 == 0) {
         printf("%d-%d\n", *ptr, *(ptr+1));
         count++;
      }
      ptr++;
   }
   printf("Toplam %d adet cift sayi ikilisi vardir.\n", count);

   return 0;
}

