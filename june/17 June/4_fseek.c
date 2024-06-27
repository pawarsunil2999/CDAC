//USE OF fseek FUNCTION

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
	
	FILE *fp;
	fp = fopen("data.txt", "r+");
	char ch[117];

	if( fp ) {
		fseek(fp, 62, SEEK_SET);
		fread(ch, sizeof(ch), 1, fp);
		printf("%s", ch);
		

	}
	
return 0;

		

}
