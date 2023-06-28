#include <stdio.h>
#include <stdlib.h>


void InsertExpense(int value, char type[10], char category[20])
{
	char date[20];
	FILE *fileExcel;
	ExcelFile();
	//Get Date
	strcpy(date, FormatDate());

	//Opens and writes info
	fileExcel = fopen("Records.csv", "a+");
	fprintf(fileExcel, "%s, %s, %s, %d\n", date, type, category, value);

	fclose(fileExcel);

}