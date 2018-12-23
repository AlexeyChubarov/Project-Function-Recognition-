#pragma once

struct countstack
{
	int command;
	int constant;
};



//количество элементов до конца строки
unsigned CheckEOPage(unsigned* str);

//увеличение размера водимой стпроки
unsigned SizeUp(unsigned** str, unsigned size);

//добавление памяти для перевода распознаваемых операций
int CountAddMemory(unsigned* StrCurrentAddress);

//подсчёт места под стеки 
countstack CountContrAndConstStack(unsigned* StrCurrentAddress);

//подсчёт исполняемого стека
int CountExeStack(control* command_stack);


