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
			//printf("%i\n", (int)(n[i] - '0'));
		}
	}
	//printf("%i\n", sum);
	if (n[0] == '-')
	{	
		return -sum;
	}
	return sum;
}

char* dectooct(int n)
{
/*
	int flag = 0;
	if (n < 0)
	{
		flag = 1;
		n = abs(n);
	}
	int lenght = 12;
	char* octal = (char*)malloc(lenght * sizeof(char));
	if (octal == NULL)
	{
		exit(1);
	}
	int indexx = 0;
	while (n > 0 && indexx < lenght - 1)
	{
		octal[indexx++] = (char)(n % 8 + '0');
		n /= 8;
	}
	if (flag == 1)
	{
		octal[indexx] = '0';
		octal[indexx + 1] = '-';
		octal[indexx + 2] = '\0';
		indexx += 2;
	}
	else
	{
		octal[indexx] = '0';
		octal[indexx + 1] = '\0';
		indexx += 1;
	}
	int start = 0;
	int end = indexx - 1;
	while (start < end)
	{
		char temp = octal[start];
		octal[start] = octal[end];
		octal[end] = temp;
		start++;
		end--;
	}*/
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

