#pragma once

struct func2arg
{
	unsigned* description;
	double (*func)(double x,double y);
};

struct func1arg
{
	unsigned* description;
	double(*func)(double x);
};

//создание стека управления
control* CommandStackCreator(unsigned* StrCurrentAddress,int size);

//создание стека констант
ConstNumber* ConstantStackCreator(unsigned* StrCurrentAddress,int size);

//подсчёт значения
double Counter(ConstNumber* constant_stack, control* command_stack, double x);
