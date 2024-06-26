 #include<stdio.h>

int main() {
	printf("Writing on new lines\n");
	char str[] = "sunil\npawar\n99999\n33";

	scanf("%[^.]s", str);
	FILE *fp;
	fp = fopen("data.txt", "w");    //curr dir
//	fp = fopen("./data.txt", "w"); 	//relative
//	fp = fopen("/home/intern9/Documents/CDAC/june/12/storage/data.txt", "w");     //absolute

	if( fp ) {
		fputs(str, fp);
		printf("\ndata written successfull");
	}
	else {
		printf("\nFile not openeed");
	}

	fclose(fp);
	return 0;

}
