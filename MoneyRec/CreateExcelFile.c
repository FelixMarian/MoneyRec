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

void ExcelFileDelete()
{
	FILE* fileExcel, *fileNo;
	char test[50];
	fileExcel = fopen("Records.csv", "w+");
	if (fileExcel == NULL)
	{
		printf("ERROR! The file didn't opened corectly");
		return 1;
	}
	if (fgets(test, 2, fileExcel) == NULL)
		fprintf(fileExcel, "Date, Type, Category, Value\n\n");
	fclose(fileExcel);
	fileNo = fopen("RecordNo.txt", "w+");
	if (fileNo == NULL)
	{
		printf("ERROR! The file didn't opened corectly");
		return 1;
	}
	fscanf(fileNo, "%d", 0);
	fclose(fileNo);
	return 0;
}

