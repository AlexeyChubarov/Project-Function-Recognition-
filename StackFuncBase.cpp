#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

#include "InternalDefines.h"
#include "StrFuncBase.h"
#include "FunctionBase.h"
#include "formater.h"
#include "FuncForRec.h"
#include "StackFuncBase.h"


void PushToCommand(control* StackBasePoint, control element)
{
	int n = 0;
	while (true)
	{
		if ((StackBasePoint[n].pointer == NULL) and (StackBasePoint[n].descriptor == -1)) break;
		inc(n);
	}


	for (int i = n; i >= 0; i--)
	{
		StackBasePoint[i + 1].pointer = StackBasePoint[i].pointer;
		StackBasePoint[i + 1].descriptor = StackBasePoint[i].descriptor;
	}

	StackBasePoint[0].pointer = element.pointer;
	StackBasePoint[0].descriptor = element.descriptor;

	return;
}

void PushToConstant(ConstNumber* StackBasePoint, ConstNumber element)
{
	int n = 0;
	while (true)
	{
		if (StackBasePoint[n].position == -1) break;
		inc(n);
	}


	for (int i = n; i >= 0; i--)
	{
		StackBasePoint[i + 1].constant = StackBasePoint[i].constant;
		StackBasePoint[i + 1].position = StackBasePoint[i].position;
	}

	StackBasePoint[0].constant = element.constant;
	StackBasePoint[0].position = element.position;

	return;
}

//кладёт элемент в исполняемый стек
void PushToStack(count* StackBasePoint, count element)
{
	int n = 0;
	while (true)
	{
		if (StackBasePoint[n].position == -1) break;
		inc(n);
	}


	for (int i = n; i >= 0; i--)
	{
		StackBasePoint[i + 1].number = StackBasePoint[i].number;
		StackBasePoint[i + 1].position = StackBasePoint[i].position;
	}

	StackBasePoint[0].number = element.number;
	StackBasePoint[0].position = element.position;

	return;
}

//забирает элемент из исполняемого стека
double PopFromStack(count* StackBasePoint)
{
	int n = 0;
	double result=StackBasePoint[0].number;

	while (true)
	{
		if (StackBasePoint[n].position == -1) break;

		StackBasePoint[n].number = StackBasePoint[n+1].number;
		StackBasePoint[n].position = StackBasePoint[n+1].position;
		inc(n);
	}

	return result;

}