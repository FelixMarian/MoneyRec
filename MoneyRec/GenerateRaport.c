#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char Date[15];
	char Type[10];
	char Category[20];
	int Value;
}recordStruct;


void GenerateRaport(int days)
{
	FILE *counterFile, *csvFile;
	int entersCount;
	char buffer[100];
	recordStruct *records;
	counterFile = fopen("RecordNo.txt", "r");
	if (counterFile == NULL)
	{
		printf("\nERROR! The file didn't opened corectly\n");
		return 1;
	}
	//Get the existent records number
	fscanf(counterFile, "%d", &entersCount);
	fclose(counterFile);
	records = malloc(entersCount * sizeof(recordStruct));

	csvFile = fopen("Records.csv", "r");
	if (csvFile == NULL)
	{
		printf("\nERROR! The file didn't opened corectly\n");
		return 1;
	}
	//2 fgets to ignore the first 2 lines (A header and an empty one)
	fgets(buffer, 50, csvFile);
	fgets(buffer, 50, csvFile);
	int readedPerLine = 0; //Check how many records we have on a line
	int totalRecords = 0; //Check all the records readed (1 record == 1 line)
	do
	{
		
		readedPerLine = fscanf(csvFile, "%15[^,], %10[^,], %20[^,], %d\n", records[totalRecords].Date,
			records[totalRecords].Type, records[totalRecords].Category, &records[totalRecords].Value);
		if (readedPerLine == 4)
			totalRecords++;
		if (readedPerLine != 4 && !feof(csvFile))
		{
			printf("\n\nThe file is corrupt. Delete them and generate new ones\n\n");
			return 1;
		}
	} while (!feof(csvFile));
	fclose(csvFile);

	printf("%d recorduri citite\n\n", totalRecords);
	for (int i = 0; i < totalRecords; i++)
	{
		printf("%s %s %s %d\n", records[i].Date, records[i].Type, records[i].Category, records[i].Value);
	}
	getDate(7);
}