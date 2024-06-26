#include <stdio.h>
#include <stdlib.h>


int main() {
	
	FILE *fp;
	char str[] = "Good morning @cdac kharghar";
	
	fp = fopen("data.txt", "wb" );
	if( fp ) {
		
		fwrite(str, sizeof(str), 1, fp );
		printf("\nbinary write successfull!!\n");
	}
	else {
		printf("\nFile Not opend\n");
		exit(1);
	}
	
	fclose(fp);
	return 0;
}
