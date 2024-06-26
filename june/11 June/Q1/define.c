#include"Declare.h"

void add( emp* arr, int size ) {
	int i;
	for( i=0; i<size; i++ ) {
		printf("\n==============================================");
		printf("\n\tEnter EMP NO : 0%d", i+1);
		scanf("%d", &arr[i].empNo);
		
		printf("\nEnter EMP name : ");
		fflush(stdin);
		scanf("%s", arr[i].name);
		
		printf("\nSuccessfull");
	}
}


void display( emp* arr, int size ) {
	if( size >= 0 ) {
		printf("\n\n\tEMPLOYEE CATALOG : ");
		int i;
		for( i=0; i<size; i++ ) {
//			printf("\n==============================================");
			printf("\n----------------------------------------------");
			printf("\n\tEMP ID \t : %d", arr[i].empNo );
			printf("\n\tEMP NAME \t : %s", arr[i].name);
		}
	
	}
	else {
		printf("\n\n\tEMPLOYEE CATALOG EMPTY ");
	}
	printf("\n\n");
}

void search( emp* arr, int size ) {
	int i, key, flag=0;
	printf("\n\nEnter the emp id to be searched : ");
	scanf("%d", &key);

	for( i=0; i<size; i++ ) {
		if( arr[i].empNo == key ) {
			printf("\n----------------------------------------------");
//			printf("\n==============================================");
			printf("\n\tEMP FOUND :)\n");
			printf("\nEMP ID \t : %d", arr[i].empNo );
			printf("\nEMP NAME \t : %s", arr[i].name);
//			printf("\n==============================================");
			printf("\n----------------------------------------------");
			flag =0;
			break;
		}
		else flag = 1;
	}
	
	if( flag )	{
//		printf("\n==============================================");
		printf("\n\tEMP NOT FOUND :( ");
//		printf("\n==============================================");
	}
}


void delet( emp* arr, int *size ) {
	int i, id = 1;
	printf("\n\nEnter the emp id to delete : ");
	scanf("%d", &id);
	for( i=0; i<*size; i++ ) {
		if( arr[i].empNo == id ) {
			int start;
			for( start=i; start<*size-1; start++ ) {
				arr[start] = arr[start+1];	
			}
			*size = *size - 1;
			printf("\n\nITEM DELETED SUCCESSFULLY ;)\n");
			printf("\n==============================================");
			break;
		}
		else {
			printf("\n\tMATCH NOT FOUND :(\nPLZ Enter valid emp id to delete!!!");
			break;
		}
	}
	
}

