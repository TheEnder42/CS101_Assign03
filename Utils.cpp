#include <stdio.h>

int getFileSize(char fileName[])
{
	FILE 	*fr;		/* declare the file pointer */
	int		c;			/*Nb int (not char) for the EOF */
	int 	newlineCount = 0;
	
	// open the file to count the lines
	fr = fopen(fileName, "rt");
	// count the newline characters	
	while ( (c=fgetc(fr)) != EOF)
	{
		if (c =='\n')
			newlineCount++;
	}
	return newlineCount;
}

void loadArray(int list[], int size, char fileName[])
{
	
	FILE 	*fr;		// declare the file pointer 
	int 	count = 0;	// running line count
	char line[80];

	fr = fopen(fileName, "rt");
	
	while(fgets(line, 80, fr) != NULL)
	{
		// get a line, p to 80 chars fr. done if NULL 
		sscanf(line, "%i", &list[count]);
		count++;
	}
} 

void initializeArray(int list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		list[i] = 0;
	}
}

void sortArray(int list[], int size)
{
	int tempNumber;
	for (int i = 0; i < size; i++)
	{
		for (int j = i +1; j < size; j++)
		{
			if(list[i] > list[j])
			{
				tempNumber = list[i];
				list[i] = list[j];
				list[j] = tempNumber;
			}
		}
	}
}