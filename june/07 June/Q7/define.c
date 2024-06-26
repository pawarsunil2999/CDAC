#include"declare.h"

int rev( int num ) {
	int result=0;
	while ( num ) {
		int digit = num %  10;
		result = result * 10 + digit;
		num/=10;
		
	}
	
	return result;
	
}
