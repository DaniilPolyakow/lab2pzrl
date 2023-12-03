#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculations.h"
#include "hex.h"
#include "oct.h"
#include "bin.h"

int main()
{
	char * input = NULL;
	size_t len = 0;
	char * num1;
	char * num2;
	char * operator;
	int type;
	getline(&input, &len, stdin);
	if (strchr(input, '~') != NULL)
	{
		num1 = input + 1;
		//printf("%i", typeofn(num1));
		//printf("%i\n", bintodec(num1));
		//printf("%s\n", dectobin(bintodec(num1)));
		if (typeofn(num1) == 0)
		{
			printf("%i\n", hextodec(num1));
			//printf("%s\n", dectohex(-123));	
			printf("%s \t (%i)\n", dectohex(tilda(hextodec(num1))), tilda(hextodec(num1)));
		}
		else if (typeofn(num1) == 1)
		{
			//printf("%i\n", octtodec(num1));
			//printf("%s\n", dectooct(-83));
			//printf("%i\n", tilda(octtodec(num1)));
			printf("%s \t (%i)\n", dectooct(tilda(octtodec(num1))), tilda(octtodec(num1)));
		}
		else
		{
			//printf("%i\n", bintodec(num1));
			printf("%s \t (%i)\n", dectobin(tilda(bintodec(num1))), tilda(bintodec(num1)));
			//printf("%i", tilda(bintodec(num1)));
		}
		return 0;
	}
	char sep[] = " ";
	char * istr = strtok(input, sep);
	num1 = istr; 
	istr = strtok(NULL, sep);
	operator = istr;
	num2 = strtok(NULL, sep);
	memmove(num1-1,num1,strlen(num1));
	num1[strlen(num1) - 1] = '0';
	num1 = num1 - 1;
	//printf("%s %s %s",  num1, operator, num2);
	if (typeofn(num1) != typeofn(num2))
	{
		printf("TYPE ERROR\n");
		return 1;
	}
		
	//printf("%i\n", hextodec("0xdd234\0"));
	if (*operator == '+')
	{
		//printf("%i\n", hextodec(num1));
		switch(typeofn(num1))
		{
			case 0:
				//printf("%s %i %i\n",num1, hextodec(num1), hextodec(num2));
				printf("%s \t (%i)\n", dectohex(summary(hextodec(num1),hextodec(num2))), summary(hextodec(num1),hextodec(num2)));
				return 0;
			case 1:
				//printf("%s %i %i\n",num1, octtodec(num1), octtodec(num2));
				printf("%s \t (%i)\n", dectooct(summary(octtodec(num1),octtodec(num2))), summary(octtodec(num1),octtodec(num2)));
				return 0;
			case 2:
				printf("%s \t (%i)\n", dectobin(summary(bintodec(num1),bintodec(num2))), summary(bintodec(num1),bintodec(num2)));
				return 0;
		}
	}
	else if (*operator == '*')
	{
		switch(typeofn(num1))
		{
			case 0:
				//printf("%s %i %i\n",num1, hextodec(num1), hextodec(num2));
				printf("%s \t (%i)\n", dectohex(multiplication(hextodec(num1),hextodec(num2))), multiplication(hextodec(num1),hextodec(num2)));
				return 0;
			case 1:
				//printf("%s %i %i\n",num1, octtodec(num1), octtodec(num2));
				printf("%s \t (%i)\n", dectooct(multiplication(octtodec(num1),octtodec(num2))), multiplication(octtodec(num1),octtodec(num2)));
				return 0;
			case 2:
				printf("%s \t (%i)\n", dectobin(multiplication(bintodec(num1),bintodec(num2))), multiplication(bintodec(num1),bintodec(num2)));
				return 0;
		}
	}	
	else if (*operator == '-')
	{
		switch(typeofn(num1))
		{
			case 0:
				//printf("%s %i %i\n",num1, hextodec(num1), hextodec(num2));
				printf("%s \t (%i)\n", dectohex(substraction(hextodec(num1),hextodec(num2))), substraction(hextodec(num1),hextodec(num2)));
				return 0;
			case 1:
				//printf("%s %i %i\n",num1, octtodec(num1), octtodec(num2));
				printf("%s \t (%i)\n", dectooct(substraction(octtodec(num1),octtodec(num2))), substraction(octtodec(num1),octtodec(num2)));
				return 0;
			case 2:
				printf("%s \t (%i)\n", dectobin(substraction(bintodec(num1),bintodec(num2))), substraction(bintodec(num1),bintodec(num2)));
				return 0;
		}
	}
}
