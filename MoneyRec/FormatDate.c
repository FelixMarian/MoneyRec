#include <time.h>
#include <windows.h>
#include <stdio.h>

int FormatDate()
{
	char Data[10][50];
	char DataExcel[20];
	int i = 0;
	char *p;
	time_t t;
	time(&t);
	p = strtok(ctime(&t), " ");
	while (p != NULL)
	{
		i++;
		strcpy(Data[i], p);
		p = strtok(NULL, " ");
	}
	strcpy(DataExcel, Data[3]);
	strcat(DataExcel, "/");
	strcat(DataExcel, Data[2]);
	strcat(DataExcel, "/");
	strcat(DataExcel, Data[5]);
	DataExcel[strcspn(DataExcel, "\n")] = 0;
	return DataExcel;
}