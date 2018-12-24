#pragma once

struct stack_t 
{
	control* command;
	ConstNumber* constant;
};


//инициализаци€ страницы дл€ распознавани€
unsigned* InitEPage(int PageSize);

//распознавание постфиксной записи
stack_t recognize(unsigned* EPage);

//подсчЄт значени€
double calculate(stack_t stack, double x);