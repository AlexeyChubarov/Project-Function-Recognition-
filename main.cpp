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

double exe_function(double x)
{
	return sin(x) - tan(sqr(x) + 2 * x + 4)*tanh(2 * x + 1) + 2 * exp(2) + pow(x, 1.2) + 4 * x - 3;
}

int main()
{
	double from,to,step;
	FILE* InFunction;
	
	int PageSize = 100;

	unsigned* EPage = InitEPage(PageSize);

	printf("%p %d\n", EPage, PageSize);

	fopen_s(&InFunction,"function.in", "r+");
	

	clock_t StartPoint1, StopPoint1, StartPoint2, StopPoint2;

	double d;
	
	
	//freadln(InFunction,&EPage);

	//printf("%d\n", (int)'\t');
	freadln(InFunction,&EPage,&PageSize);
	
	printf("%p %d\n",EPage,PageSize);
	//BinaryWrite(EPage);
	
	printf("\n");
	writeln(EPage);
	printf("\n");	
	
	if (PostfixTransfer(&EPage, &PageSize, 6) == -1)
	{
		system("pause");

		system("cls");

		free(EPage);

		main();
	}

	printf("%p %d\n", EPage, PageSize);
	writeln(EPage);
	printf("\n");

	
	printf("%p %d\n", EPage, PageSize);
	writeln(EPage);
	printf("\n");

	countstack STACK = CountContrAndConstStack(EPage);

	printf("\n%d %d\n",STACK.command,STACK.constant);

	stack_t Stack = recognize(EPage);

	ConstNumber* constant_stack=Stack.constant;
	

	 control* command_stack = Stack.command;

	 printf("exe Stack %d\n", CountExeStack(command_stack));
	 
	 printf("Constant Stack\n");
	 for (int s = 0; s < STACK.constant+1; s++)
		 printf("%lf\t%d\n", constant_stack[s].constant, constant_stack[s].position);

	 printf("Command Stack\n");
	 for (int s = 0; s < STACK.command+1; s++)
		 printf("%p\t%d\n", command_stack[s].pointer, command_stack[s].descriptor);

	 printf("%lf\n",calculate(Stack,1));

	 printf("%lf\n", exe_function(1));
	  scanf_s("%lf %lf", &from, &to);
	  scanf_s("%lf", &step);

	

	 StartPoint1 = clock();
	 d = dIntegral(constant_stack, command_stack, from, to, step);
	 StopPoint1 = clock();
	 printf("%lf\n",d );
	 int result = (StopPoint1 - StartPoint1);
	 printf("calculation time:\t%d\n\n",result);

	 StartPoint2 = clock();
	 d = dIntegral(exe_function, from, to, step);
	 StopPoint2 = clock();
	 printf("%lf\n", d);
	 result = (StopPoint2 - StartPoint2);
	 printf("calculation time:\t%d\n", result);
	

	system("pause");
	return 0;
}