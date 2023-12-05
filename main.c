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
	char * num1 = NULL;
	char * num2 = NULL;
	char * operator = NULL;
	char * hex;
	char * oct;
	char * bin;
	getline(&input, &len, stdin);
	if (strchr(input, '~') != NULL)
	{
		num1 = input + 1;
		if (typeofn(num1) == 0)
		{
			hex = dectohex(tilda(hextodec(num1)));
			printf("%s \t (%i)\n", hex, tilda(hextodec(num1)));
			free(hex);
		}
		else if (typeofn(num1) == 1)
		{
			oct = dectooct(tilda(octtodec(num1)));
			printf("%s \t (%i) \t %i \n", oct, tilda(octtodec(num1)), octtodec(num1));
			free(oct);
		}
		else
		{
			bin = dectobin(tilda(bintodec(num1)));
			printf("%s \t (%i)\n", bin, tilda(bintodec(num1)));
			free(bin);
		}
		free(input);
		exit(0);
	}
	char sep[] = " ";

	//num1 = strdup(strtok(input, sep));
	//operator = strdup(strtok(NULL, sep));
	//num2 = strdup(strtok(NULL, sep));
	//printf("%s %s %s\n", num1, operator, num2);
	

	char num1_buffer[100];
	char op_buff[2];
	char num2_buffer[100];
	sscanf(input, "%99s %1s %99s", num1_buffer, op_buff, num2_buffer);
	num1 = strdup(num1_buffer);
	operator = strdup(op_buff);
	num2 = strdup(num2_buffer);
	//printf("%i %i", strlen(num1), strlen(num2));
	//exit(0);
	//printf("%s %s %s\n", num1, num2, operator);
	//printf("%i %i\n", strlen(num1), strlen(num2));


	size_t len2 = strlen(num1);
	size_t len3 = strlen(num2);
	//printf("%i\n", len2);
	char* new_string = (char*)malloc(len2 + 2);
	char* new_string2 = (char*)malloc(len3 + 2);
	strcpy(new_string, num1);
	strcpy(new_string2, num2);
	//printf("%s     %i       %c %c %c %c\n",new_string,len2, new_string[0], new_string[1], new_string[2], new_string[3]);
	new_string[len2] = '0';
	new_string2[len3] = '0';
	//printf("%s %c %c %c %c\n",new_string,new_string[0] , new_string[1], new_string[2], new_string[3]); 
	new_string[len2 + 1] = '\0';
	new_string2[len3 + 1] = '\0';
	free(num1);
	free(num2);
	num1 = new_string;
	num2 = new_string2;
	//printf("%i %i\n", strlen(num1), strlen(num2));
	//printf("%s %s\n", num1, num2); 
	
	/*
	//printf("%i\n###############\n", len2);
	//printf("%s %s\n", num1, num2);
	*/


/*	
	char * istr = strtok(input, sep);
	num1 = istr; 
	istr = strtok(NULL, sep);
	operator = istr;
	istr = strtok(NULL, sep);
	num2 = istr;
	//printf("%s	%s\n", is num1);
	memmove(num1 - 1, num1, strlen(num1));
	num1[strlen(num1) - 1] = '0';
	num1 = num1 - 1;
*/


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
				hex = dectohex(summary(hextodec(num1),hextodec(num2)));
			////int dec = 
				printf("%s \t (%i)\n", hex, summary(hextodec(num1),hextodec(num2)));
				free(hex);
				break;
			case 1:
				oct = dectooct(summary(octtodec(num1),octtodec(num2)));
				printf("%s \t (%i)\n", oct, summary(octtodec(num1),octtodec(num2)));
				free(oct);
				break;
			case 2:
				//printf("%s %s %i\n", num1, num2,bintodec(num2)); 
				bin = dectobin(summary(bintodec(num1),bintodec(num2)));
				printf("%s \t (%i)\n", bin, summary(bintodec(num1),bintodec(num2)));
				free(bin);
				break;
		}
		//free(input);
	}
	else if (*operator == '*')
	{
		switch(typeofn(num1))
		{
			case 0:
				hex = dectohex(multiplication(hextodec(num1),hextodec(num2)));
				printf("%s \t (%i)\n", hex, multiplication(hextodec(num1),hextodec(num2)));
				free(hex);
				break;
				
			case 1:
				oct = dectooct(multiplication(octtodec(num1),octtodec(num2)));
				printf("%s \t (%i)\n", oct, multiplication(octtodec(num1),octtodec(num2)));
				free(oct);
				break;
				
			case 2:
				bin = dectobin(multiplication(bintodec(num1),bintodec(num2)));
				printf("%s \t (%i)\n", bin, multiplication(bintodec(num1),bintodec(num2)));
				free(bin);
				break;
				
		}
	}	
	else if (*operator == '-')
	{
		switch(typeofn(num1))
		{
			case 0:
				hex = dectohex(substraction(hextodec(num1),hextodec(num2)));
				printf("%s \t (%i)\n", hex, substraction(hextodec(num1),hextodec(num2)));
				free(hex);
				break;
				
			case 1:
				oct = dectooct(substraction(octtodec(num1),octtodec(num2)));
				printf("%s \t (%i)\n", oct, substraction(octtodec(num1),octtodec(num2)));
				free(oct);
				break;
				
			case 2:
				bin = dectobin(substraction(bintodec(num1),bintodec(num2)));
				printf("%s \t (%i)\n", bin, substraction(bintodec(num1),bintodec(num2)));
				free(bin);
				break;
		}
	}
	else if (*operator == '%')
	{
		switch(typeofn(num1))
		{
			case 0:
				hex = dectohex(percentage(hextodec(num1),hextodec(num2)));
				printf("%s \t (%i)\n", hex, percentage(hextodec(num1),hextodec(num2)));
				free(hex);
				break;
			case 1:
				oct = dectooct(percentage(octtodec(num1),octtodec(num2)));
				printf("%s \t (%i)\n", oct, percentage(octtodec(num1),octtodec(num2)));
				free(oct);
				break;
			case 2:
				bin = dectobin(percentage(bintodec(num1),bintodec(num2)));
				printf("%s \t (%i)\n", bin, percentage(bintodec(num1),bintodec(num2)));
				free(bin);
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
					hex = dectohex(ampersant(hextodec(num1),hextodec(num2)));
					printf("%s \t (%i)\n", hex, ampersant(hextodec(num1),hextodec(num2)));
					free(hex);
					break;
				case 1:
					oct = dectooct(ampersant(octtodec(num1),octtodec(num2)));
					printf("%s \t (%i)\n", oct, ampersant(octtodec(num1),octtodec(num2)));
					free(oct);
					break;
				case 2:
					bin = dectobin(ampersant(bintodec(num1),bintodec(num2)));
					printf("%s \t (%i)\n", bin, ampersant(bintodec(num1),bintodec(num2)));
					free(bin);
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
					hex = dectohex(palochka(hextodec(num1),hextodec(num2)));
					printf("%s \t (%i)\n", hex, palochka(hextodec(num1),hextodec(num2)));
					free(hex);
					break;
				case 1:
					oct = dectooct(palochka(octtodec(num1),octtodec(num2)));
					printf("%s \t (%i)\n", oct, palochka(octtodec(num1),octtodec(num2)));
					free(oct);
					break;
				case 2:
					bin = dectobin(palochka(bintodec(num1),bintodec(num2)));
					printf("%s \t (%i)\n", bin, palochka(bintodec(num1),bintodec(num2)));
					free(bin);
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
					hex = dectohex(sex(hextodec(num1),hextodec(num2)));
					printf("%s \t (%i)\n", hex, sex(hextodec(num1),hextodec(num2)));
					free(hex);
					break;
				case 1:
					oct = dectooct(sex(octtodec(num1),octtodec(num2)));
					printf("%s \t (%i)\n", oct, sex(octtodec(num1),octtodec(num2)));
					free(oct);
					break;
				case 2:
					bin = dectobin(sex(bintodec(num1),bintodec(num2)));
					printf("%s \t (%i)\n", bin, sex(bintodec(num1),bintodec(num2)));
					free(bin);
					break;
			}
		}	
		else
		{
			printf("ERROR\n");
		}
	}
	//printf("%p\n", input)
	free(input);
	free(num1);
	free(num2);
	free(operator);
	free(new_string);
	exit(0);

}
