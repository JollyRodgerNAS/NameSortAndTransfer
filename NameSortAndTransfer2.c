/*
	Reads items from file and
	sorts them alphabetically and stores in new file
*/

#define MAX_SIZE 30
#define MAX_CHARS 60
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareItems(const void *a, const void *b) 
{
	return strcmp(*(char**)a, *(char**)b);
}

int main(void) 
{
	FILE* from, * to;
	size_t counter = 0;
	size_t check = 0;
	char* items[MAX_SIZE];

	from = fopen("from.txt", "r");
	if (from == NULL) 
	{
		perror("Error opening from.txt");
		exit(1);
	}

	to = fopen("to.txt", "w");
	if (to == NULL) 
	{
		fclose(from);
		perror("Error opening to.txt");
		exit(1);
	}

	for (size_t i = 0; i < MAX_SIZE; i++) 
	{
		items[i] = malloc(MAX_CHARS * sizeof(char));
		counter++;
	}

	while (check < counter && fgets(items[check], counter, from) != NULL)
	{
		items[check][strcspn(items[check], "\n")] = '\0';
		check++;
	}

	qsort(items, check, sizeof(char*), compareItems);

	for (size_t j = 0; j < check; j++) 
	{
		fprintf(to, "%s\n", items[j]);
		free(items[j]);
	}

	fclose(from);
	fclose(to);

	return 0;
}