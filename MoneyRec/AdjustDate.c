#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getNewStartDate(char *data, int days, char **months, int monthdays[])
{
	char copyData[15], dateComps[3][6], newStringDay[5], newStartDate[15];
	char *p;
	int i = 0, integerDay=0;
	strcpy(copyData, data);
	strcpy(newStartDate, " ");
	p = strtok(copyData, "/"); //Split the date into componenta (DD,MMM,YYYY)
	while (p != NULL)
	{
		strcpy(dateComps[i], p);
		i++;
		p = strtok(NULL, "/");
	}
	if (dateComps[0][1] == '\0') //Convert the day into integer for calculus
	{
		integerDay = dateComps[0][0] - '0';
	}
	else if (dateComps[0][2] == '\0')
	{
		integerDay = dateComps[0][0] - '0';
		integerDay = integerDay * 10 + (dateComps[0][1]-'0');
	}
	if (integerDay == days)
	{
		strcpy(newStartDate, "1");
		strcat(newStartDate, "/");
		strcat(newStartDate, dateComps[1]);
		strcat(newStartDate, "/");
		strcat(newStartDate, dateComps[2]);
	}
	else if (integerDay - days> 0)
	{
		itoa(integerDay - days, newStringDay, 5);
		strcpy(newStartDate, newStringDay);
		strcat(newStartDate, "/");
		strcat(newStartDate, dateComps[1]);
		strcat(newStartDate, "/");
		strcat(newStartDate, dateComps[2]);
	}
	printf("%s", newStartDate);
}