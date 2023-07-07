#include <stdio.h>


void DeleteFile(char FileName[])
{
	remove(FileName);
}