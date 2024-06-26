#include"declare.h"

int main() {
	int a;
	printf("Enter the number : ");
	scanf("%d", &a);
	
	if( oddEven(a) )
		printf("The number is odd");
	else 
		printf("The number is even");
}
