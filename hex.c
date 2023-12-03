#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "oct.h"

int hextodec(char * n)
{
	int sum = 0;
	int i = 0;
	if (n[0] == '-')
	{
		i += 3;
	}
	else
	{
		i += 2;
	}
	for (i; i < strlen(n) - 1; i++)
	{      	
		//printf("%c\n", n[i]);
		if (n[i] == 'a')
		{
			sum += 10 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'b')
		{
			sum += 11 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'c')
		{
			sum += 12 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'd')
		{
			sum += 13 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'e')
		{
			sum += 14 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'f')
		{
			sum += 15 * pow(16, strlen(n) - i - 2);
		}
		else
		{	
			//if (n[i] != '\0')
			//{
				sum += (int)(n[i] - '0') * pow(16, strlen(n) - i - 2);
			//}
	//	printf("%i\n", (int)(n[i] - '0'));
		}
	}
//	printf("%i\n", sum);
	if (n[0] == '-')
	{	
		return -sum;
	}
	return sum;
}

char* dectohex(int n)
{ /*
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
	}
	return octal;*/
	int lenght = 32;
	char* hexal = (char*)malloc(lenght * sizeof(char));
	if (n >= 0)
	{
		sprintf(hexal, "0x%x", abs(n));
	}
	else
	{
		sprintf(hexal, "-0x%x", abs(n));
	}
	return hexal;	
}	

