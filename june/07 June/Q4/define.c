#include"declare.h"

int fact( int num ) {
	
	int i, result=1;
	
	for( i=1; i<=num; i++ ) {
		result = i*result;
	}
	
	return result;
}
