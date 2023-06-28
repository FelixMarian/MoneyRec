#include <stdio.h>

void ExcelFile() 
{
	FILE *fileExcel;
	char test[50];
	fileExcel = fopen("Records.csv", "a+");
	if(fgets(test,2,fileExcel)==NULL)
		fprintf(fileExcel, "Date, Type, Category, Value\n\n");
	fclose(fileExcel);
	return 0;
}