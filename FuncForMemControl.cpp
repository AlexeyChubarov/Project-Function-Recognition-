#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <corecrt_malloc.h>

#include "InternalDefines.h"
#include "StrFuncBase.h"
#include "FunctionBase.h"
#include "formater.h"
#include "FuncForRec.h"
#include "StackFuncBase.h"
#include "Counter.h"
#include "Integral.h"
#include "FuncForMemControl.h"
#include "MainFunctions.h"


unsigned CheckEOPage(unsigned* str)
{
	int i = 0, j = 0;
	bool flag = false;
	while (true)
	{
		if (*((char*)str + i) == 10)
		{
			flag = true;
		}

		if (*((char*)str + i) == '¸') break;
		if (flag == true)
			inc(j);
		inc(i);
	}
	return j;
}

unsigned SizeUp(unsigned** str, unsigned size)
{
	unsigned CurrentSize = size+(size>>1);
	if (((*str) = (unsigned*)realloc((void*)(*str), CurrentSize)) == NULL)
	{
		fprintf(stderr, "Allocation Error!!");
		exit(0x2);
	}

	*((char*)(*str) + CurrentSize - 1) = '¸';
	return CurrentSize;
}

int CountAddMemory(unsigned* StrCurrentAddress)
{
	int i = 0;
	int summ = 0;
	while (true)
	{
		if (*((char*)StrCurrentAddress + i) == 10)break;

		switch (*((char*)StrCurrentAddress + i))
		{
		case '+':
			summ += 6;
			break;

		case '-':
			summ += 7;
			break;

		case '*':
			summ += 10;
			break;

		case '/':
			summ += 8;
			break;
		case '^':
			summ += 5;
			break;
		default:
			break;
		}

		inc(i);

	}
	return summ;
}

countstack CountContrAndConstStack(unsigned* StrCurrentAddress)
{

	char buf[10] = {};
	int res = 0,NumOfX=0;
	int i = 0;

	int j = 0;
	while (true)
	{
		if (*((char*)StrCurrentAddress + i) == 10)break;

		if ((*((char*)StrCurrentAddress + i) == ',') or (*((char*)StrCurrentAddress + i) == ')'))
		{
			if ((buf[0] == 'x'))
			{
				inc(res);

				inc(NumOfX);

				for (int k = 0; k < j; k++)
					buf[k] = ' ';

				j = -1;
			}
			else

				if (
					((buf[0] <= '9') and (buf[0] >= '0'))
					or
					((buf[0] == '.') and ((buf[1] <= '9') and (buf[1] >= '0')))
					)
				{
					inc(res);
					for (int k = 0; k < j; k++)
						buf[k] = ' ';
					j = -1;

				}
				else
					if ((*((char*)StrCurrentAddress + i) == ')') or (*((char*)StrCurrentAddress + i) == ',')) j = -1;
		}
		else
			if ((*((char*)StrCurrentAddress + i) == '('))
			{
				inc(res);
				inc(NumOfX);
				j = -1;
			}
			else 
			{
				if (j == 10)j = 0;
				buf[j] = *((char*)StrCurrentAddress + i);
			}


		inc(i);
		inc(j);

	}

	return {res,res-NumOfX};
}

int CountExeStack(control* command_stack)
{
	int res = 0;
	int i = 0;

	while (true)
	{
		if (command_stack[i].descriptor == -1)break;
		if (command_stack[i].descriptor == 0)	
			inc(res);
			
		inc(i);
		
	}

	return res;
}