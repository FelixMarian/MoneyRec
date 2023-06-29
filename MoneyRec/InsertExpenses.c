#include <stdio.h>
#include <stdlib.h>


void InsertExpense(int value, char type[10], char category[20])
{
	char date[20];
	FILE *fileExcel;
	int Number,c;
	//Get Date
	strcpy(date, FormatDate());

	//Opens and writes info
	fileExcel = fopen("Records.csv", "a+");
	if (fileExcel == NULL)
	{
		printf("\nERROR! The file didn't opened corectly\n");
		return 1;
	}
	fprintf(fileExcel, "%s, %s, %s, %d\n", date, type, category, value);

	fclose(fileExcel);

	Counting();
	
	
}