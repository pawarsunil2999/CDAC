// Write a program of menu driven for employee/student
  //  1.create 2.delete 3.display 4.search using id/roll no 
	
	//(use Makefile and create different file for defination ,declaration and Main.)


#include"Declare.h"

int main() {
	
	int size = 1;
//	printf("Enter the Number of emps : ");
//	scanf("%d", &size);

	emp* ptr;
	ptr = (emp*)malloc( sizeof( emp ) * size );
	

	while( 1 ) {	
	printf("\n==============================================");
	printf("\n\n\t 1 : Add \n\t 2 : Display \n\t 3 : Search  \n\t 4 : Delete Book \n\t 5 : EXIT =======>\n");
	
	printf("\n==============================================");
	printf("\n\nEnter your choice : ");	
	int choice;
	scanf("%d", &choice);
	printf("\n==============================================");
	
		switch( choice ) {
			case 1 :
				add( ptr, size );
//   			int validator = valid( ptr, size );
//				if( validator ) change( ptr, validator );
				break;
			case 2 : 
			
				display( ptr, size );
				break;
			case 3 :
				search( ptr, size );
				break;
			case 4 : 
				delet( ptr, &size );
				break;
			default :
				printf("\n\n\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\t\t:)\n\n\n\n");
				exit(1);
		}

	}


	free( ptr );
	return 0;		
}
