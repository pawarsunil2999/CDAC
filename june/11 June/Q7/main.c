#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


int main() {
	
	FILE *fp;
		fp = fopen( "data.txt", "r");
		
	if( fp ) {
		int count =0;
		char ch;
		int vowels =0, alphas = 0, digit = 0, space = 0, tabs =0, punch = 0, lines=0; 
		
		while ( ( ch = fgetc(fp)) != EOF ) {
			
			if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch ==  'u' ||
			    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch ==  'U'  ) 
			    vowels++;
			else if( isalpha(ch) ) 
				alphas++;
			else if( isdigit(ch) ) 
				digit++;
			else if( ch ==  ' ') 
				space++;
			else if( ch == '\t' ) 
				tabs++;
			else if( ch == '\n' )
				lines++;
			else if( ispunct(ch) ) 
				punch++;
		}
		
		printf("\nThe number of lines present in file : %d", lines);
		printf("\nThe number of vowels present in file : %d", vowels);
		printf("\nThe number of alpha present in file : %d", alphas);
		printf("\nThe number of digit present in file : %d", digit);
		printf("\nThe number of spaces present in file : %d", space);
		printf("\nThe number of tabs present in file : %d", tabs);
		printf("\nThe number of punch present in file : %d", punch);
		
	}
	else {
		printf("File Not Opened");
		exit(1);		
	}	
		


}
