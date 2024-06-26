#include<stdio.h>
#include<stdlib.h>


int main() {
	
	FILE *fp;
		fp = fopen( "data.txt", "r");
		
	if( fp ) {
		int count =0;
		char ch;
		while ( ( ch = fgetc(fp)) != EOF ) {
			
			if( ch == '\n' ) count++;
		}
		
		printf("\nThe number of lines present in file : %d", count);
	}
	else {
		printf("File Not Opened");
		exit(1);		
	}	
		


}
