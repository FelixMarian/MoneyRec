#include <stdio.h>
#include <stdlib.h>
#include "Insertions.h"


int main()
{
	char alex[10];
	int opt;
	while (1)
	{
		printf("Value: (0 to exit)\n");
		scanf("%d", &opt);
		if (opt == 0)
			exit(0);
		printf("Type?\n");
		scanf("%s", alex);
		InsertExpense(opt, "Income", alex);
	}

	system("pause");
	return 0;
}