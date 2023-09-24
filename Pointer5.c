#include <stdio.h>
#include <stdlib.h>
/*5. int sayilar[] = { 10,15,20,33,22,11,9,8,48,47,12,25,12,21 };
Yukarýda verilen tam sayý dizisinde sayýnýn baþtan kaçýncý sýrada olduðunu bulan (yoksa 
“Bu sayý dizide bulunmamaktadýr” yazdýrýlacaktýr) program kodunu yazýnýz.*/
int main() {
   int sayilar[] = { 10,15,20,33,22,11,9,8,48,47,12,25,12,21 };
   int aranan, i;
   int *ptr;
   printf("Aranacak sayiyi girin: ");
   scanf("%d", &aranan);
   ptr = sayilar;
   
   for (i = 0; i < 14; i++) {
      if (*(ptr+i) == aranan) {
         printf("%d sayisi %d. sirada.\n", aranan, i+1);
         break;
      }
   }
   if (i == 14) {
      printf("Bu sayi dizide bulunmamaktadir.\n");
   }

   return 0;
}
