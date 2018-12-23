#pragma once

struct control
{
	unsigned* pointer;
	int descriptor;
};

struct ConstNumber
{
	double constant;
	int position;
};

struct count
{
	double number;
	int position;
};

struct function
{
	const char* name;
	control setting;
};

//кладёт элемент в стек управления
void PushToCommand(control* StackBasePoint, control element);

//кладёт элемент в стек констант
void PushToConstant(ConstNumber* StackBasePoint, ConstNumber element);

//кладёт элемент в исполняемый стек
void PushToStack(count* StackBasePoint, count element);

//забирает элемент из исполняемого стека
double PopFromStack(count* StackBasePoint);


