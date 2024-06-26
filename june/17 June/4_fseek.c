#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
	
	FILE *fp;
	fp = fopen("data.txt", "r+");
	char ch[100];

	if( fp ) {
		fseek(fp, -100, SEEK_END);
		fread(ch, sizeof(ch), 1, fp);
		printf("%s", ch);
		

	}
	
return 0;

		

}
