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

int getDate(int Days)
{
	char *data = FormatDate();
	char *Months[13] = { "Ian", "Feb", "Mar", "Apr", "May", "Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	int daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char aux[5], startDate[20];
	int auxInt=0;
	if (data[1] == '/') //Check if the day is 1-9 or 10+
		strcpy(aux, data + 6);
	else if (data[2] == '/')
		strcpy(aux, data + 7);
	for (int i = 0; i < 4; i++)
	{
		auxInt = auxInt * 10 + (aux[i] - '0');
	}
	if (auxInt % 4 == 0 && auxInt % 100 != 0 || auxInt % 400 == 0) //Check if february has 28 or 29 days
		daysInMonths[1] = 29;
	strcpy(aux, " "); //Clear the aux
	auxInt = 0;
	return getNewStartDate(data, Days, Months, daysInMonths);
}