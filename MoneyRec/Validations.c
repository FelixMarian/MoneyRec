#include <stdio.h>
#include <stdlib.h>


int whatTypeItIs(int opt)
{
	if (opt == 1 || opt == 2)
		return 1;
	return 0;
}

int whatCategoryItIsExpense(int opt)
{
	if (opt >= 1 && opt <= 17)
		return 1;
	return 0;
}

int whatCategoryItIsIncome(int opt)
{
	if (opt >= 1 && opt <= 9)
		return 1;
	return 0;
}

int howManyDaysUWant(int days)
{
	if (days == 7 || days == 14 || days == 31)
		return 1;
	return 0;
}

int itIsAYesOrANo(char opt[])
{
	if (strcmp(opt,"Y")==0 || strcmp(opt, "N") == 0)
		return 1;
	return 0;
}