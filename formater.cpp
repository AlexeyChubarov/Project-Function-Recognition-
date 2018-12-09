#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

#include "InternalDefines.h"
#include "StrFuncBase.h"
#include "FunctionBase.h"
#include "formater.h"

struct pointers 
{
	unsigned* past;
	unsigned* present;
	unsigned* future;
};

//распознание умножения и деления
unsigned* StrFormatMD(unsigned* StrCurrentAddress)
{
	pointers position;

	bool flag = false;
	bool exception = false;


	unsigned* pAdd=NULL;

	position.past = (unsigned*)((char*)StrCurrentAddress-1);
	position.present = position.past;
	position.future = StrCurrentAddress;
	

	

	while (true)
	{
		if (*(char*)position.future == '(')
		{
			position.future = StrFormatMD((unsigned*)((char*)position.future+1));
		}

		if ((*(char*)position.future == '+') or (*(char*)position.future == '-')or(*(char*)position.future == '*') or (*(char*)position.future == '/')or (*(char*)position.future == '\n')or(*(char*)position.future == ')'))
		{
			if (flag == false)
			{
				if ((*(char*)position.future == '*') or (*(char*)position.future == '/'))
				{

					position.present = position.future;
					flag = true;

				}
				else
				{
					position.past = position.future;
				}
			}
			else 
			{
				if (*(char*)position.present == '*')
				{

					replace(position.present, 1, ",", 1);

					add((unsigned*)((char*)position.future), ")", 1);

					pAdd = add((unsigned*)((char*)position.past+1), "multiply(", sizeof("multiply(")-1);

					position.future = (unsigned*)((char*)position.future +9);

					flag = false;
					exception = true;
				} else

				if (*(char*)position.present == '/')
				{
					replace(position.present, 1, ",", 1);

					add(position.future, ")", 1);

					pAdd = add((unsigned*)((char*)position.past + 1), "divide(", sizeof("divide(")-1);

					position.future = (unsigned*)((char*)position.future +7);

					flag = false;
					exception = true;
				}
				
			}
		}
		if (exception==false)
		{ 
			if (*(char*)position.future == ')')return (unsigned*)((char*)position.future+1);
			if (*(char*)position.future == '\n') return position.future;

		}
		exception = false;

		position.future = (unsigned*)((char*)position.future+1);
	}
}

//распознавание сложения и вычитания
unsigned* StrFormatPM(unsigned* StrCurrentAddress)
{
	pointers position;

	bool flag = false;
	bool exception = false;


	unsigned* pAdd = NULL;

	position.past = (unsigned*)((char*)StrCurrentAddress - 1);
	position.present = position.past;
	position.future = StrCurrentAddress;




	while (true)
	{
		if (*(char*)position.future == '(')
		{
			position.future = StrFormatPM((unsigned*)((char*)position.future + 1));
		}

		if ((*(char*)position.future == '+') or (*(char*)position.future == '-') or (*(char*)position.future == '*') or (*(char*)position.future == '/') or (*(char*)position.future == '\n') or (*(char*)position.future == ')'))
		{
			if (flag == false)
			{
				if ((*(char*)position.future == '+') or (*(char*)position.future == '-'))
				{

					position.present = position.future;
					flag = true;

				}
				else
				{
					position.past = position.future;
				}
			}
			else
			{
				if (*(char*)position.present == '+')
				{

					replace(position.present, 1, ",", 1);

					add((unsigned*)((char*)position.future), ")", 1);

					pAdd = add((unsigned*)((char*)position.past + 1), "plus(", sizeof("plus(") - 1);

					position.future = (unsigned*)((char*)position.future + 5);

					flag = false;
					exception = true;
				}
				else

					if (*(char*)position.present == '-')
					{
						replace(position.present, 1, ",", 1);

						add(position.future, ")", 1);

						pAdd = add((unsigned*)((char*)position.past + 1), "minus(", sizeof("minus(") - 1);

						position.future = (unsigned*)((char*)position.future + 6);

						flag = false;
						exception = true;
					}

			}
		}
		if (exception == false)
		{
			if (*(char*)position.future == ')')return (unsigned*)((char*)position.future + 1);
			if (*(char*)position.future == '\n') return position.future;

		}
		exception = false;

		position.future = (unsigned*)((char*)position.future + 1);
	}
}






unsigned* StrFormatC(unsigned* StrCurrentAddress)
{
	pointers position;

	bool flag = false;
	bool exception = false;


	unsigned* pAdd = NULL;

	position.past = (unsigned*)((char*)StrCurrentAddress - 1);
	position.present = position.past;
	position.future = StrCurrentAddress;




	while (true)
	{
		if (*(char*)position.future == '(')
		{
			position.future = StrFormatC((unsigned*)((char*)position.future + 1));
		}

		if ((*(char*)position.future == '^') or (*(char*)position.future == '+') or (*(char*)position.future == '-') or (*(char*)position.future == '*') or (*(char*)position.future == '/') or (*(char*)position.future == '\n') or (*(char*)position.future == ')'))
		{
			if (flag == false)
			{
				if ((*(char*)position.future == '^'))
				{

					position.present = position.future;
					flag = true;

				}
				else
				{
					position.past = position.future;
				}
			}
			else
			{
				if (*(char*)position.present == '^')
				{


					replace(position.present, 1, ",", 1);

					add((unsigned*)((char*)position.future), ")", 1);

					pAdd = add((unsigned*)((char*)position.past + 1), "pow(", sizeof("pow(") - 1);

					position.future = (unsigned*)((char*)position.future + 4);

					flag = false;
					exception = true;
				}
			}
		}
		if (exception == false)
		{
			if (*(char*)position.future == ')')return (unsigned*)((char*)position.future + 1);
			if (*(char*)position.future == '\n') return position.future;

		}
		exception = false;

		position.future = (unsigned*)((char*)position.future + 1);
	}
}

//распознавания стандартного вида числа
void StdTypeOfNumberRecognize(unsigned* StrCurrentAddress)
{
	int i = 0;
	while (true)
	{
		if (*((char*)StrCurrentAddress + i) == 10)break;

		if (
			((*((char*)StrCurrentAddress + i) == 'e') or (*((char*)StrCurrentAddress + i) == 'E'))
			and
			((*((char*)StrCurrentAddress + i - 1) <= '9') and (*((char*)StrCurrentAddress + i - 1) >= '0'))
			and
			((*((char*)StrCurrentAddress + i + 2) <= '9') and (*((char*)StrCurrentAddress + i + 2) >= '0'))
			)
		{
			replace((unsigned*)((char*)StrCurrentAddress + i), 1, "*10^(", sizeof("*10^(") - 1);
			i += 6;
			while (true)
			{if ((*((char*)StrCurrentAddress + i) == '+')or (*((char*)StrCurrentAddress + i) == '-')or(*((char*)StrCurrentAddress + i) == '*') or (*((char*)StrCurrentAddress + i) == '/') or (*((char*)StrCurrentAddress + i) == '^') or (*((char*)StrCurrentAddress + i) == ')')or (*((char*)StrCurrentAddress + i) == '\n'))
				{
					add((unsigned*)((char*)StrCurrentAddress + i),")",1);
					break;
				}

				if (*((char*)StrCurrentAddress + i) == 10)
				{
					i--;
					break;
				}
						

				inc(i);
			}

		}

		inc(i);
	}
}
