//file handling

#include<stdio.h>
#include<stdlib.h>

int main() {

	FILE *fp1;
		fp1 = fopen("rdata.txt", "r");
	FILE *fp2;
		fp2 = fopen("wdata.txt", "w");
	char str[100];
	if( fp1 && fp2 ) {
		while( !feof(fp1) ) {
			fgets(str, sizeof(str), fp1);
			fputs(str, fp2);
		}
		printf("Data transfered successfullY!!!!!!");
	}
	else {
		printf("file not opened");
		exit(1);
	}
		


}
