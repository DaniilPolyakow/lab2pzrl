#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"

int summary(int n1, int n2)
{
	return n1 + n2;
}
int multiplication(int n1, int n2)
{
	return n1 * n2;
}
int substraction(int n1, int n2)
{
	return n1 - n2;
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
int tilda(const int n)
{
	return -(n + 1);	
}
int typeofn(char * n)
{
	if (n[0] == '-')
	{
		n = n + 1;
	}
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
