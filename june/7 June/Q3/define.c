#include"declare.h"

int rev( int num ) {
	int digit, result=0;
	
	while( num ) {
		digit = num%10;
		result = result * 10 + digit;
		num /=10;
	}
	
	return result;
	
}

void checkPali( int num ) {
	int reversed = rev(num);
	
	if( num == reversed )
		printf("\n The number is %d palindrome", num);
	else
		
		printf("\n The number %d isn`t palindrome", num);
}
