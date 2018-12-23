#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

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

unsigned* InitEPage(int PageSize)
{
	unsigned* EPage = (unsigned*)malloc(PageSize);

	*((char*)EPage + PageSize - 1) = '¸';

	return EPage;
}

stack_t recognize(unsigned* EPage)
{
	countstack STACK = CountContrAndConstStack(EPage);

	ConstNumber* constant_stack = ConstantStackCreator(EPage, STACK.constant);
	control* command_stack = CommandStackCreator(EPage, STACK.command);

	return {command_stack,constant_stack};
}