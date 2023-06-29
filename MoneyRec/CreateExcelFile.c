#include <stdio.h>

void ExcelFile() 
{
	FILE *fileExcel;
	char test[50];
	fileExcel = fopen("Records.csv", "a+");
	if (fileExcel == NULL)
	{
		printf("ERROR! The file didn't opened corectly");
		return 1;
	}
	if(fgets(test,2,fileExcel)==NULL)
		fprintf(fileExcel, "Date, Type, Category, Value\n\n");
	fclose(fileExcel);
	return 0;
}