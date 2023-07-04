#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char Date[15];
	char Type[10];
	char Category[20];
	int Value;
}recordStruct;

int CompareDate(char *startDate, char *actualDate)
{
	char *pStart, *pActual;
	char startDateArray[3][10], actualDateArray[3][10], startDateCopy[20], actualDateCopy[20];
	int i = 0, j = 0, dayIntegerStart=0, dayIntegerActual=0, posStart=0, posActual=0, started=0;
	char *Months[13] = { "Ian", "Feb", "Mar", "Apr", "May", "Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	strcpy(startDateCopy, startDate);
	strcpy(actualDateCopy, actualDate);
	pStart = strtok(startDateCopy, "/");
	while (pStart != NULL)
	{
		strcpy(startDateArray[i], pStart);
		i++;
		pStart = strtok(NULL, "/");
	}	
	pActual = strtok(actualDateCopy, "/");
	while (pActual != NULL)
	{
		strcpy(actualDateArray[j], pActual);
		j++;
		pActual = strtok(NULL, "/");
	}
	if (startDateArray[0][1] == '\0')
	{
		dayIntegerStart = startDateArray[0][0] - '0';
	}
	if (actualDateArray[0][1] == '\0')
	{
		dayIntegerActual = actualDateArray[0][0] - '0';
	}
	if (startDateArray[0][2] == '\0')
	{
		dayIntegerStart = startDateArray[0][0] - '0';
		dayIntegerStart = dayIntegerStart * 10 + (startDateArray[0][1] - '0');
	}
	if (actualDateArray[0][2] == '\0')
	{
		dayIntegerActual = actualDateArray[0][0] - '0';
		dayIntegerActual = dayIntegerActual * 10 + (actualDateArray[0][1] - '0');
	}
	for (i = 0; i < 12; i++)
	{
		if (strcmp(startDateArray[1], Months[i]) == 0)
			posStart = i;
		if (strcmp(actualDateArray[1], Months[i]) == 0)
			posActual = i;
	}
 	if (strcmp(startDateArray[2], actualDateArray[2]) < 0)
		return 1;
	else if (strcmp(startDateArray[2], actualDateArray[2]) == 0 && posStart < posActual)
		return 1;
	else if (strcmp(startDateArray[2], actualDateArray[2]) == 0 && posStart == posActual && dayIntegerStart < dayIntegerActual)
		return 1;
	return 0;
}	

void GenerateRaport(int days)
{
	FILE *counterFile, *csvFile;
	int entersCount, started=0;
	//Raports per category
	int groceries = 0, fast_food=0,entertainment=0,tobacco=0, alcohool=0, transport=0,rent=0,debt=0,books=0;
	int online_memberships = 0, going_out = 0, art = 0, toys = 0, electronics = 0, misc = 0, gas = 0, car = 0, totalExp = 0;
	int salary = 0, family = 0, wins = 0, shares = 0, crypto = 0, scolarship = 0, loan = 0, tips = 0, sells = 0, totalInc=0;
	char buffer[100], startDate[20], categoryToCheck[20];
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
	strcpy(startDate,getDate(days));
	for (int i = 0; i < totalRecords; i++)
	{
		started = CompareDate(startDate, records[i].Date);
		if(started==1)
		{
			if (strcmp(records[i].Category, "Groceries") == 0)
			{
				groceries += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Fast-Food") == 0)
			{
				fast_food += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Entertainment") == 0)
			{
				entertainment += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Tobacco") == 0)
			{
				tobacco += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Alcohool") == 0)
			{
				alcohool += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Transport") == 0)
			{
				transport += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Rent") == 0)
			{
				rent += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Debt") == 0)
			{
				debt += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Books") == 0)
			{
				books += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Online memberships") == 0)
			{
				online_memberships += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Going out") == 0)
			{
				going_out += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Art") == 0)
			{
				art += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Toys") == 0)
			{
				toys += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Electronics") == 0)
			{
				electronics += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Misc") == 0)
			{
				misc += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Gas") == 0)
			{
				gas += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Car") == 0)
			{
				car += records[i].Value;
				totalExp += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Salary") == 0)
			{
				salary += records[i].Value;
				totalInc += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Family") == 0)
			{
				family += records[i].Value;
				totalInc += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Wins") == 0)
			{
				wins += records[i].Value;
				totalInc += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Shares") == 0)
			{
				shares += records[i].Value;
				totalInc += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Crypto") == 0)
			{
				crypto += records[i].Value;
				totalInc += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Scolarship") == 0)
			{
				 scolarship += records[i].Value;
				totalInc += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Loan") == 0)
			{
				loan += records[i].Value;
				totalInc += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Tips") == 0)
			{
				tips += records[i].Value;
				totalInc += records[i].Value;
			}
			else if (strcmp(records[i].Category, "Sells") == 0)
			{
				sells += records[i].Value;
				totalInc += records[i].Value;
			}
		}
	}
	animation(); //Loading animation
	printf("\n\nExpenses                              \n\n");
	printf("Groceries: %d RON                               \n", groceries);
	printf("Fast-Food: %d RON                                \n", fast_food);
	printf("Entertainment: %d RON                                \n", entertainment);
	printf("Tobacco: %d RON                                \n", tobacco);
	printf("Alcohool: %d RON                                \n", alcohool);
	printf("Transport: %d RON                                \n", transport);
	printf("Rent: %d RON                                \n", rent);
	printf("Debt: %d RON                                \n", debt);
	printf("Books: %d RON                                \n",books);
	printf("Online memberships: %d RON                                \n",online_memberships);
	printf("Going out: %d RON                                \n",going_out);
	printf("Art: %d RON                                \n",art);
	printf("Toys: %d RON                                \n",toys);
	printf("Electronics: %d RON                                \n",electronics);
	printf("Misc: %d RON                                \n",misc);
	printf("Gas: %d RON                                \n",gas);
	printf("Car: %d RON                               \n\n",car);
	printf("Total expenses: %d RON", totalExp);
}