// APPEND DATA INTO EXISTING FILR

#include<stdio.h>
#include<stdlib.h>

int main() {
	
	FILE *fp;
	char str[100] = "sunil pawar \n\n";
	printf("Enter any string to append : ");
	scanf("%s", str);
	
	fp = fopen("data.txt", "a+");
	
	if( fp ) {
		fwrite(str, sizeof(str), 1, fp);
		printf("data appended successfully");
	}
	else {
		printf("File not opened !!!");
		exit(1);		
	}

}
