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