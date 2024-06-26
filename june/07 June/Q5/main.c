//Armstrong Number

#include"declare.h"

int main() {
	
	int num;
	printf("Enter any number : ");
	scanf("%d", &num);
	
	int result = armStrong(num);
	
	if( num == result )
		printf("Number is Armstrong");
	else 
		printf("Number isn`t Armsrong");
	
}
