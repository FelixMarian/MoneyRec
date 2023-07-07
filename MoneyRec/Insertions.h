#pragma once


void InsertExpense(int value, char type[10], char category[20]);

void ExcelFile();
void FormatDate();

int whatTypeItIs(int opt);
int whatCategoryItIsExpense(int opt);
int whatCategoryItIsIncome(int opt);
int itIsAYesOrANo(char opt[]);

void showCategoriesExpenses();
int chooseTheExpense(int opt);

void showCategoriesIncomes();
int chooseTheIncome(int opt);

int Counting();

void GenerateRaport(days);

int howManyDaysUWant(int days);


int getDate(int Days);
int getNewStartDate(char *data, int days, char *months[], int monthdays[]);

void animation();

void DeleteFile(char FileName[]);
void ExcelFileDelete();