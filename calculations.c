#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"

void summary()
{

}
void multiplication()
{

}
void substraction()
{

}
void percentage()
{

}
void ampersant()
{

}
void palochka()
{

}
void sex()
{

}
int typeofn(char * n)
{
	/*
	printf("%s\n", n);
	printf("%c\n", n[0]);
	*/
	if (n[0] == '0' && n[1] == 'x')
	{
		return 0;
	}
	else if (n[0] == '0')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
