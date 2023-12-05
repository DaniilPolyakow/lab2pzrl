#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "oct.h"

int octtodec(const char * n)
{
	int sum = 0;
	for (int i = 0; i < strlen(n) - 1; i++)
	{       if (n[i] != '-')	
		{
			sum += (int)(n[i] - '0') * pow(8, strlen(n) - i - 2); 
		}
	}
	if (n[0] == '-')
	{	
		return -sum;
	}
	return sum;
}

char* dectooct(int n)
{
	int lenght = 20;
	char* octal = (char*)malloc(lenght * sizeof(char));
	if (n >= 0)
	{	
		sprintf(octal, "0%o", abs(n));
	}
	else
	{
		sprintf(octal, "-0%o", abs(n));
	}
	return octal;
}	

