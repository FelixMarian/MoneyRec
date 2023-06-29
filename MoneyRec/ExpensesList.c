#include <stdio.h>

void showCategoriesExpenses()
{
	printf("\nExpenses:\n");
	printf("1. Groceries                        11. Going out\n");
	printf("2. Fast-Food                        12. Art\n");
	printf("3. Entertainment                    13. Toys\n");
	printf("4. Tobacco                          14. Electronics\n");
	printf("5. Alcohool                         15. Misc\n");
	printf("6. Transport                        16. Gas\n");
	printf("7. Rent                             17. Car\n");
	printf("8. Debt\n");
	printf("9. Books\n");
	printf("10. Online memberships\n");
}

int chooseTheExpense(int opt)
{
	switch (opt)
	{
	case 1:
		return "Groceries";
	case 2:
		return "Fast-Food";
	case 3:
		return "Entertainment";
	case 4:
		return "Tobacco";
	case 5:
		return "Alcohool";
	case 6:
		return "Transport";
	case 7:
		return "Rent";
	case 8:
		return "Debt";
	case 9:
		return "Books";
	case 10:
		return "Online memberships";
	case 11:
		return "Going out";
	case 12:
		return "Art";
	case 13:
		return "Toys";
	case 14:
		return "Electronics";
	case 15:
		return "Misc";
	case 16:
		return "Gas";
	case 17:
		return "Car";
	}
}