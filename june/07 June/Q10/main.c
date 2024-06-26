//swapping of two numbers

#include"declare.h"

int main() {
	int a,b;
	printf("Enter two numbers to swap : ");
	scanf("%d%d", &a, &b);
	
	swap( &a, &b );
	
	printf("\nValue of a : %d\nValue of b : %d", a,b );

}
