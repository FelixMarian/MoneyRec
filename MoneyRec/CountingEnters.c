#include <stdlib.h>
#include <stdio.h>

int Counting()
{
	FILE *countFile;
	int number=0;
	countFile = fopen("RecordNo.txt", "a+t");
	if (countFile == NULL)
	{
		printf("\nERROR! The file didn't opened corectly\n");
		return 1;
	}
	fscanf(countFile, "%d", &number);
	fclose(countFile);
	countFile = fopen("RecordNo.txt", "w+t");
	if (countFile == NULL)
	{
		printf("\nERROR! The file didn't opened corectly\n");
		return 1;
	}
	if (number == 0) //Counting, if count is 0, start with 1
	{
		fprintf(countFile, "%d", 1);
	}
	else
	{
		number++;
		fprintf(countFile, "%d", number);
	}
	fclose(countFile);
}