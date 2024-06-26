#include"declare.h"

int sumOfDigit( int num ) {
	
	int result=0;
	while(num) {
		int digit = num%10;
		result = result + digit;
		num/=10;
	
	}
	return result;
}
