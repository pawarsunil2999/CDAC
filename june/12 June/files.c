//FILE HANDLING IN BINARY MODES

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	FILE *fp1 = fopen("data.txt", "wb");
	
	
	char str[100] = "s", dest[100] = "d";
	if( fp1 ) {
		printf("Enter string to write/read : ");
		scanf("%s", str);
		fwrite(str, sizeof(str), 1, fp1);
		

		fclose(fp1);
	}
	
	FILE *fp2 = fopen("data.txt", "rb");
	if( fp2 ) { 
		printf("\nreading from file : \n");
		fread(dest, sizeof(dest), 1, fp2);
		printf("%s", dest);
		fclose(fp2);
	}
}

