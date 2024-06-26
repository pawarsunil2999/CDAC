#include <stdio.h>
#include <stdlib.h>


int main() {
	
	FILE *fp;
	char str[1000];
	
	fp = fopen("data.txt", "rb" );
	if( fp ) {
		
		fread(str, sizeof(str), 1, fp );
		printf("\nbinary read successfull!!\n");
		puts(str);
	}
	else {
		printf("\nFile Not opend\n");
		exit(1);
	}
	
	fclose(fp);
	return 0;
}
