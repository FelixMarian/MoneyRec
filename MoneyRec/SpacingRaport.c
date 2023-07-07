


int howManyDigits(int Number)
{
	int  k = 0;
	while (Number != 0)
	{
		Number /= 10;
		k++;
	}
	return k;
}

int MakeSpaces(int Exp)
{
	int i;
	char spacing[37], space[2] = " ";
	strcpy(spacing, space);
	for (i = 35 - howManyDigits(Exp); i > 0; i--)
		strcat(spacing, " ");
	return spacing;
}