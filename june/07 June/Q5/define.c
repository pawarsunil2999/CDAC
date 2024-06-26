#include"declare.h"


int	armStrong( int num ) {
	int num1 = num1, i;
	
	while( num ) {
		int digit = num %10;
		i = i + (digit*digit*digit);
		num /=10;
	}

	return i;
	
}
