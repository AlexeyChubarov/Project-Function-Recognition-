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
#include "Counter.h"
#include "Integral.h"
#include "FuncForMemControl.h"
#include "MainFunctions.h"

//функция считывает символы до перевода строки
void readln(unsigned** StrCurrentAddress,int* SizeOfPage)
{
	unsigned i = 0;

	while (true)
	{
		if ((i % STEP_OF_INCREACING == 0)and(i!=0))
		{
			*((char*)(*StrCurrentAddress) + i) = '\n';
			if (CheckEOPage((*StrCurrentAddress)) <= STEP_OF_INCREACING)
				*SizeOfPage = SizeUp(StrCurrentAddress, (*SizeOfPage));
		}
		*((char*)(*StrCurrentAddress) + i) = getchar();
		if (*((char*)(*StrCurrentAddress) + i) == 10) break;
		inc(i);
	}
	return;
}

//функция считывает символы до перевода строки из фаила
void freadln(FILE* file,unsigned** StrCurrentAddress,int* SizeOfPage)
{
	unsigned i = 0;

	while (true)
	{
		if ((i!=0)and(i % STEP_OF_INCREACING == 0))
		{
			*((char*)(*StrCurrentAddress) + i) = '\n';
			if (CheckEOPage((*StrCurrentAddress)) <= STEP_OF_INCREACING)
				*SizeOfPage = SizeUp(StrCurrentAddress, (*SizeOfPage));
		}

		*((char*)(*StrCurrentAddress) + i) = fgetc(file);
		if ((*((char*)(*StrCurrentAddress) + i) == 10)or (*((char*)(*StrCurrentAddress) + i) == '\0')) break;
		inc(i);
	}
	return;
}
//функция считывает определённое количество символов
void read(unsigned* StrCurrentAddress, unsigned quantity)
{
	if (quantity == 0)return;

	unsigned i = 0;
	
	while (true)
	{
		*((char*)StrCurrentAddress + i) = getchar();
		if (i==quantity-1) break;
		inc(i);
	}
	return;
}

//функция выводит символы до перевода строки
void writeln(unsigned* StrCurrentAddress)
{
	unsigned i = 0;
	while (true)
	{
		putchar(*((char*)StrCurrentAddress + i));
		if (*((char*)StrCurrentAddress + i + 1) == 10)break;
		inc(i);
	}
	return;
}

//функция выводит символы до перевода строки в фаил
void fwriteln(FILE* file,unsigned* StrCurrentAddress)
{
	unsigned i = 0;
	while (true)
	{
		fputc(*((char*)StrCurrentAddress + i),file);
		if (*((char*)StrCurrentAddress + i + 1) == 10)break;
		inc(i);
	}
	return;
}

//функция выводит определённое количество символов строки
void write(unsigned* StrCurrentAddress, unsigned quantity)
{
	if (quantity == 0)return;
	unsigned i = 0;
	while (true)
	{
		putchar(*((char*)StrCurrentAddress + i));
		if (i==quantity) break;
		inc(i);
	}
	return;
}

//сдвиг строки вправо
void shift(unsigned* StartPoint, unsigned step)
{
	unsigned ShiftStep = 0;


	while (true)
	{
		inc(ShiftStep);
		if (*(char*)((char*)StartPoint + ShiftStep - 1) == 10) break;

	}

	for (;; ShiftStep--)
	{
		if (ShiftStep == 0)break;
		*((char*)StartPoint + ShiftStep - 1 + step) = *((char*)StartPoint + ShiftStep - 1);
		*((char*)StartPoint + ShiftStep - 1) = ' ';
	}

	return;
}

//сдвиг строки влево (удаление символов)
void del(unsigned* StartPoint, unsigned step)
{
	unsigned ShiftStep = 0;

	while (true)
	{
		if (*(char*)((char*)StartPoint + ShiftStep) == 10) break;
		inc(ShiftStep);
	}
	for (unsigned i = 0; i <= ShiftStep; i++)
	{
		*((char*)StartPoint + i) = *((char*)StartPoint + step + i);
	}
	return;
}



//добавление элементов в строку
unsigned * add(unsigned* StartPoint, const char* Element, unsigned length)
{
	unsigned i = 0;
	shift(StartPoint, length);

	for (i = 0; i <= length - 1; i++)
	{
		*((char*)StartPoint + i) = Element[i];
	}
	return (unsigned*)((char*)StartPoint + length);

}

//замена символов в строке
unsigned * replace(unsigned * StartPoint, unsigned symbols, const char* Element, unsigned length)
{

	del((unsigned*)((char*)StartPoint), symbols);
	return add(StartPoint, Element, length);
}

//вывод символов в строке
unsigned BinaryWrite(unsigned* EPage)
{
	unsigned i = 0;
	while (true)
	{
		printf("%d ", (int)*((char*)EPage + i));
		if (*(char*)((char*)EPage + i) == 10) break;
		inc(i);
	}
	return i + 1;
}