#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculations.h"
#include "hex.h"
#include "oct.h"
#include "bin.h"

void main()
{
	char * input = NULL;
	size_t len = 0;
	char * num1;
	char * num2;
	char * operator;
	char * hex;
	int type;
	getline(&input, &len, stdin);
	if (strchr(input, '~') != NULL)
	{
		num1 = input + 1;
		if (typeofn(num1) == 0)
		{
			printf("%i\n", hextodec(num1));
			printf("%s \t (%i)\n", dectohex(tilda(hextodec(num1))), tilda(hextodec(num1)));
		}
		else if (typeofn(num1) == 1)
		{
			printf("%s \t (%i)\n", dectooct(tilda(octtodec(num1))), tilda(octtodec(num1)));
		}
		else
		{
			printf("%s \t (%i)\n", dectobin(tilda(bintodec(num1))), tilda(bintodec(num1)));
		}
		free(binary);
		free(octal);
		free(hexal);
		exit(0);
	}
	char sep[] = " ";
	char * istr = strtok(input, sep);
	num1 = istr; 
	istr = strtok(NULL, sep);
	operator = istr;
	num2 = strtok(NULL, sep);
	memmove(num1 - 1, num1, strlen(num1));
	num1[strlen(num1) - 1] = '0';
	num1 = num1 - 1;
	if (typeofn(num1) != typeofn(num2))
	{
		printf("TYPE ERROR\n");
		//free(input);
		exit(1);
	}
	if (*operator == '+')
	{
		switch(typeofn(num1))
		{
			case 0:
			//	hex = dectohex(summary(hextodec(num1),hextodec(num2)));
			////int dec = 
				printf("%s \t (%i)\n", dectohex(summary(hextodec(num1),hextodec(num2))), summary(hextodec(num1),hextodec(num2)));
				break;
			case 1:
				printf("%s \t (%i)\n", dectooct(summary(octtodec(num1),octtodec(num2))), summary(octtodec(num1),octtodec(num2)));
				break;
			case 2:
				printf("%s nonsense \t (%i)\n", dectobin(summary(bintodec(num1),bintodec(num2))), summary(bintodec(num1),bintodec(num2)));
				break;
		}
	}
	else if (*operator == '*')
	{
		switch(typeofn(num1))
		{
			case 0:
				printf("%s \t (%i)\n", dectohex(multiplication(hextodec(num1),hextodec(num2))), multiplication(hextodec(num1),hextodec(num2)));
				break;
				
			case 1:
				printf("%s \t (%i)\n", dectooct(multiplication(octtodec(num1),octtodec(num2))), multiplication(octtodec(num1),octtodec(num2)));
				break;
				
			case 2:
				printf("%s \t (%i)\n", dectobin(multiplication(bintodec(num1),bintodec(num2))), multiplication(bintodec(num1),bintodec(num2)));
				break;
				
		}
	}	
	else if (*operator == '-')
	{
		switch(typeofn(num1))
		{
			case 0:
				printf("%s \t (%i)\n", dectohex(substraction(hextodec(num1),hextodec(num2))), substraction(hextodec(num1),hextodec(num2)));
				break;
				
			case 1:
				printf("%s \t (%i)\n", dectooct(substraction(octtodec(num1),octtodec(num2))), substraction(octtodec(num1),octtodec(num2)));
				break;
				
			case 2:
				printf("%s \t (%i)\n", dectobin(substraction(bintodec(num1),bintodec(num2))), substraction(bintodec(num1),bintodec(num2)));
				break;
		}
	}
	else if (*operator == '%')
	{
		switch(typeofn(num1))
		{
			case 0:
				printf("%s \t (%i)\n", dectohex(percentage(hextodec(num1),hextodec(num2))), percentage(hextodec(num1),hextodec(num2)));
				break;
			case 1:
				printf("%s \t (%i)\n", dectooct(percentage(octtodec(num1),octtodec(num2))), percentage(octtodec(num1),octtodec(num2)));
				break;
			case 2:
				printf("%s \t (%i)\n", dectobin(percentage(bintodec(num1),bintodec(num2))), percentage(bintodec(num1),bintodec(num2)));
				break;
		}
	}
	else if (*operator == '&')
	{
		if (num1[0] != '-' && num2[0] != '-')
		{	
			switch(typeofn(num1))
			{
				case 0:
					printf("%s \t (%i)\n", dectohex(ampersant(hextodec(num1),hextodec(num2))), ampersant(hextodec(num1),hextodec(num2)));
					break;
				case 1:
					printf("%s \t (%i)\n", dectooct(ampersant(octtodec(num1),octtodec(num2))), ampersant(octtodec(num1),octtodec(num2)));
					break;
				case 2:
					printf("%s \t (%i)\n", dectobin(ampersant(bintodec(num1),bintodec(num2))), ampersant(bintodec(num1),bintodec(num2)));
					break;
			}
		}	
		else
		{
			printf("ERROR\n");
		}
	}
	else if (*operator == '|')
	{
		if (num1[0] != '-' && num2[0] != '-')
		{	
			switch(typeofn(num1))
			{
				case 0:
					printf("%s \t (%i)\n", dectohex(palochka(hextodec(num1),hextodec(num2))), palochka(hextodec(num1),hextodec(num2)));
					break;
				case 1:
					printf("%s \t (%i)\n", dectooct(palochka(octtodec(num1),octtodec(num2))), palochka(octtodec(num1),octtodec(num2)));
					break;
				case 2:
					printf("%s \t (%i)\n", dectobin(palochka(bintodec(num1),bintodec(num2))), palochka(bintodec(num1),bintodec(num2)));
					break;
			}
		}	
		else
		{
			printf("ERROR\n");
		}
	}
	else if (*operator == '^')
	{
		if (num1[0] != '-' && num2[0] != '-')
		{	
			switch(typeofn(num1))
			{
				case 0:
					printf("%s \t (%i)\n", dectohex(sex(hextodec(num1),hextodec(num2))), sex(hextodec(num1),hextodec(num2)));
					break;
				case 1:
					printf("%s \t (%i)\n", dectooct(sex(octtodec(num1),octtodec(num2))), sex(octtodec(num1),octtodec(num2)));
					break;
				case 2:
					printf("%s \t (%i)\n", dectobin(sex(bintodec(num1),bintodec(num2))), sex(bintodec(num1),bintodec(num2)));
					break;
			}
		}	
		else
		{
			printf("ERROR\n");
		}
	}
	//printf("%p\n", input)
	//;
	free(input);
	//free(binary);
	//free(octal);
	//free(hex);
	exit(0);

}
