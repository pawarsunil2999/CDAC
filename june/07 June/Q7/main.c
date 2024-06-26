//rev number
#include"declare.h"

int main() {
	printf("Enter any number to reverse : ");
	int num;
	scanf("%d", &num );
	
	int reversed = rev( num );
	
	printf("reversed number is : %d", reversed);
}
