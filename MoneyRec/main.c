#include <stdio.h>
#include <stdlib.h>
#include "Insertions.h"


int main()
{
	char type[10], category[10];
	int opt,value, optType, optCategory;
	ExcelFile();
	while (1)
	{
		printf("\n0. Exit\n");
		printf("1. Insert data\n");
		printf("2. See raport\n");
		printf("Your option: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:
			exit(0);
			break;
		case 1:
			printf("Value: ");
			scanf("%d", &value);
			do //Getting if it is an expense or an income
			{
				printf("\nType [1(Expense)/2(Income)]: ");
				scanf("%d", &optType);
				if (optType == 1)
				{
					strcpy(type, "Expense");
					showCategoriesExpenses(); //Showing a list of expenses
					do
					{
						printf("\nCategory: ");
						scanf("%d", &optCategory);
						strcpy(category,chooseTheExpense(optCategory)); //Copying the category
					} while (!whatCategoryItIsExpense(optCategory));
					InsertExpense(value, type, category);
				}
				else if (optType == 2)
				{
					strcpy(type, "Income");
					showCategoriesIncomes(); //Showing a list of incomes
					do
					{
						printf("\nCategory: ");
						scanf("%d", &optCategory);
						strcpy(category, chooseTheIncome(optCategory)); //Copying the category
					} while (!whatCategoryItIsIncome(optCategory));
					InsertExpense(value, type, category);
				}
			} while (!whatTypeItIs(optType));
			break;
		case 2:
			break;
		default:
			printf("\n\n!!! This option doesn't exist !!!\n\n");
			break;
		}
	}

	system("pause");
	return 0;
}