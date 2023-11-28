#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculations.h"

int main()
{
	char * input = NULL;
	size_t len = 0;
	char * num1;
	char * num2;
	char * operator;
	int i = 0;
	getline(&input, &len, stdin);
	if (strchr(input, '~') != NULL)
	{
		
	}
	char sep[] = " ";
	char * istr = strtok(input, sep);
	num1 = istr;
	istr = strtok(NULL, sep);
	operator = istr;
	num2 = strtok(NULL, sep);
	printf("%s %s %s\n",  num1, operator, num2);
	printf("%i\n", typeofn(num1));
	

}
