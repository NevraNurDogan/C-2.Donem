#include <stdio.h>
#include <stdlib.h>

/* 4. 100 sayýsýndan küçük çift ve 3’e bölünmeyen ilk 10 adet tam sayýyý diziye alan ve küçükten
büyüðe yazdýran program kodunu yazýnýz. */

int main(int argc, char *argv[]) {
	int dizi[10];
	int *ptr=dizi;
	int n=10,sayi=99;
 	while(n>0){
		if(sayi % 2==0 && sayi % 3!=0){
			*ptr=sayi;
			ptr++;
			n--;
		}
		sayi--;	
	}
	 ptr = dizi;
	for(n=0;n<10;n++){
		printf("%d \t",*ptr);
		ptr++;
	}
	return 0;
}
