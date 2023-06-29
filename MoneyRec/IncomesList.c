#include <stdio.h>

void showCategoriesIncomes()
{
	printf("\nIncomes:\n");
	printf("1. Salary\n");
	printf("2. Family\n");
	printf("3. Wins (Loterry/Gambling/Etc...)\n");
	printf("4. Shares\n");
	printf("5. Crypto\n");
	printf("6. Scolarship\n");
	printf("7. Loan\n");
	printf("8. Tips\n");
	printf("9. Sells\n");
}

int chooseTheIncome(int opt)
{
	switch (opt)
	{
	case 1:
		return "Salary";
	case 2:
		return "Family";
	case 3:
		return "Wins";
	case 4:
		return "Shares";
	case 5:
		return "Crypto";
	case 6:
		return "Scolarship";
	case 7:
		return "Loan";
	case 8:
		return "Tips";
	case 9:
		return "Sells";
	}
}