#include"daclare.h"

void fibbo() {
	
	int limit, nxt, a=0, b=1;
	printf("Enter any number : ");
	scanf("%d", &limit);
	
	printf("The fibbo series is : 0, 1, ");
	
	for( int i =0; i<limit; i++ ) {
		nxt = a+b;
		printf("%d, ", nxt);
		
		a=b, b=nxt;
	}
}
