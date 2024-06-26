#include"declare.h"

void isPrime() {
	int num;
	int flag = 1;
	
	printf("Enter any number to verify : ");
	scanf("%d", &num);
	int i=2;
	for( ; i<num-1; i++ ) {
		if( num <= 1 )
			flag = 0;
		if( num%i == 0 ) 
			flag = 0; 
				
	}
	
	if( flag )
		printf("\nIs a prime number ");
	else 
		printf("\nIsn`t a prime number ");
}
