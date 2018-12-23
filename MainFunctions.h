#pragma once

struct stack_t 
{
	control* command;
	ConstNumber* constant;
};

//инициализация страницы для распознавания
unsigned* InitEPage(int PageSize);

//распознавание постфиксной записи
stack_t recognize(unsigned* EPage);