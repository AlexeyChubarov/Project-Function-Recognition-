#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

#include "InternalDefines.h"
#include "StrFuncBase.h"
#include "FunctionBase.h"
#include "formater.h"
#include "FuncForRec.h"

void FinalRepalce(unsigned* StrCurrentAddress,int accurancy)
{
	unsigned i = 0;
	char buf[25];
	unsigned res;

	//res = sprintf_s(buf, "%.*lf",accurancy, number);

	while (true)
	{
		if (*((char*)StrCurrentAddress + i) == 10)return;

		if ((*((char*)StrCurrentAddress + i) == '(')and (*((char*)StrCurrentAddress + i + 1) == ','))
			add((unsigned*)((char*)StrCurrentAddress + i+1),"0",sizeof("0")-1);

		/* if ( 
			(*((char*)StrCurrentAddress + i) == 'x') 
			and
			(((*((char*)StrCurrentAddress + i-1) == '(') and (*((char*)StrCurrentAddress + i + 1) == ','))
				or((*((char*)StrCurrentAddress + i - 1) == ',') and (*((char*)StrCurrentAddress + i + 1) == ')'))
			    or ((*((char*)StrCurrentAddress + i - 1) == '(') and (*((char*)StrCurrentAddress + i + 1) == ')')))
			)

		{
			replace((unsigned*)((char*)StrCurrentAddress + i), 1, buf, res);
		} */

		if (
			(*((char*)StrCurrentAddress + i) == 'e')
			and
			(((*((char*)StrCurrentAddress + i - 1) == '(') and (*((char*)StrCurrentAddress + i + 1) == ','))
				or ((*((char*)StrCurrentAddress + i - 1) == ',') and (*((char*)StrCurrentAddress + i + 1) == ')'))
				or ((*((char*)StrCurrentAddress + i - 1) == '(') and (*((char*)StrCurrentAddress + i + 1) == ')')))
			)
		{
			res= sprintf_s(buf, "%.*lf",accurancy,2.718281828459045);

			replace((unsigned*)((char*)StrCurrentAddress + i), 1, buf, res);

			//res = sprintf_s(buf, "%.*lf",accurancy, number);
		}

		if (
			((*((char*)StrCurrentAddress + i) == 'p')or(*((char*)StrCurrentAddress + i) == 'P'))
			and
			((*((char*)StrCurrentAddress + i+1) == 'i') or (*((char*)StrCurrentAddress + i+1) == 'I'))
			and
			(((*((char*)StrCurrentAddress + i - 1) == '(') and (*((char*)StrCurrentAddress + i + 2) == ','))
				or ((*((char*)StrCurrentAddress + i - 1) == ',') and (*((char*)StrCurrentAddress + i + 2) == ')'))
				or ((*((char*)StrCurrentAddress + i - 1) == '(') and (*((char*)StrCurrentAddress + i + 2) == ')')))
			)
		{
			res = sprintf_s(buf, "%.*lf", accurancy, 3.14159265358979323);

			replace((unsigned*)((char*)StrCurrentAddress + i), 2, buf, res);

	
		}

		inc(i);
	}
}

//подсчёт значения
/* double counter(unsigned* StrCurrentAddress)
{
	char buf[256];
	int i = 0;
	double result=0.;

	while (true)
	{
		if (*(char*)StrCurrentAddress + i == 10)return result;

		buf[i] = *((char*)StrCurrentAddress + i);

		if (buf[i] == '(')counter((unsigned*)((char*)StrCurrentAddress + i + 1));



		inc(i);
	}

}
*/


struct BracketsIndicator
{
	unsigned* opening;
};

//удаление лишних скобок
unsigned* OddBracketsDeleter(unsigned* StrCurrentAddress)
{
	BracketsIndicator bracket;
	unsigned* CurrentPointer = StrCurrentAddress;

	bracket.opening = NULL;

	while (true)
	{
		if (*(char*)CurrentPointer == '(')
		{
			if (
				(CurrentPointer == StrCurrentAddress) or
				((*((char*)CurrentPointer - 1) == '(') or (*((char*)CurrentPointer - 1) == ','))
				)
			{
				bracket.opening = CurrentPointer;
				CurrentPointer=OddBracketsDeleter((unsigned*)((char*)CurrentPointer + 1));
			}
			else CurrentPointer = OddBracketsDeleter((unsigned*)((char*)CurrentPointer +1));

		}
		else 
			if (*(char*)CurrentPointer == ')')
		{
			if (bracket.opening != NULL)
			{
				del(CurrentPointer, 1);
				del(bracket.opening, 1);

				return (unsigned*)((char*)CurrentPointer-3);
			}
			else return CurrentPointer;

		}
		if (*(char*)CurrentPointer == 10) return CurrentPointer;

		CurrentPointer = (unsigned*)((char*)CurrentPointer + 1);
		
	}
}

//проверка на соответствие скобок
bool BracketAccordance(unsigned* StrCurrentAddress)
{
	struct counters
	{
		unsigned open;
		unsigned close;
	} bracket;

	bracket.open = 0;
	bracket.close = 0;

	unsigned i=0;

	while (true)
	{
		if (*((char*)StrCurrentAddress + i) == '(')
			inc(bracket.open);

		if (*((char*)StrCurrentAddress + i) == ')')
			inc(bracket.close);
	
		if (*((char*)StrCurrentAddress + i) == 10)
		{
			if (bracket.open == bracket.close) return true;
			else return false;
		}

		inc(i);
	}
}