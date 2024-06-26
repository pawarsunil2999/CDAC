#include<stdio.h>
#include<stdlib.h>

typedef struct emp {
	int empNo;
	char name[30];
	
}emp;

void add(emp*, int);
void delet(emp*, int*);
void display(emp*, int);
void search(emp*, int);

