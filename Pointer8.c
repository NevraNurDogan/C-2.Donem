#include <stdio.h>
#include <stdlib.h>

/*8. int sayilar[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
Yukar�daki say� dizisinde indisleri tek olan say�lar�n ortalamas�n� bulan ve ortalamadan 
b�y�k olan (sadece tek indisli) say�lar� ekrana yazd�ran program kodunu yaz�n�z. 
Not: indis 0 ile ba�lar. 20 say�s� 0. �ndistedir. 60, 42, 24 gibi say�lar i�leme tabi tutulmal�d�r. */

int main(int argc, char *argv[]) {
	int sayilar[]= { 20,60,45,42,23,24,26,125,66,55,145,50,30,40 };
	int *ptr, i;
	int total=0,a=0;
	int ort;
   ptr = sayilar;
   for (i = 0; i < 14; i++) {
      if (i % 2 != 0) {
      	printf("%d\t",*(ptr +i));
         total+=*(ptr +i);
         a++;
      }
   }
    ort =total/a;
      printf("\nOrtalama:%d\nOrtalamadan buyuk olan tek indisliler:\t",ort);
      for (i = 0; i < 14; i++) {
      if (i % 2 != 0 && *(ptr +i)>ort) {	
         printf("%d\t",*(ptr +i));
  }
 }
	return 0;
}
