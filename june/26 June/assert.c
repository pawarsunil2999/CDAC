//implementation of function  assert 


#include<stdio.h>
#include<assert.h>

void fun1( int* ptr ) {

	assert( ptr );
	printf("\nValue : %d\n\n", *ptr);

}


int main() {
	
	int k1 = 5;
	fun1(&k1);

	int *k2 = NULL;
	fun1(k2);

	return 0;

}

