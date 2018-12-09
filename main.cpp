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



int main()
{
	unsigned *EPage,*p;
	EPage = (unsigned*)malloc(PageSize);
	
	readln(EPage);

	if (BracketAccordance(EPage) == false)
	{
		fprintf(stderr, "Fatal Error: the discrepancy in the number of opening and closing brackets\n please, try again\n");

		system("pause");
		//getchar();

		system("cls");

		free(EPage);
		main();
		return 0;
	}
	
	
	OddBracketsDeleter(EPage);

	StdTypeOfNumberRecognize(EPage);

	p= StrFormatC(EPage);
	p= StrFormatMD(EPage);
	p= StrFormatPM(EPage);

	OddBracketsDeleter(EPage);

	FinalRepalce(EPage,6);


	
	printf("\n");
	writeln(EPage);
	printf("\n");

	/*count exe_stack[2];
	exe_stack[0].number = 0;
	exe_stack[0].position = -1;

	PushToStack(exe_stack, {2.5,1});
	printf("%lf\n\n", PopFromStack(exe_stack));
	for (int i = 0; i < 2; i++)
		printf("%lf\t%d\n", exe_stack[i].number, exe_stack[i].position);

*/	
	ConstNumber* constant_stack=ConstantStackCreator(EPage);
	

	printf("\nConstantStack\n\n");
	for (int i = 0; i <= 6; i++)
		printf("%lf\t%d\n", constant_stack[i].constant, constant_stack[i].position);


	//BinaryWrite(EPage);

	 control* command_stack = CommandStackCreator(EPage);
	
	 printf("\nCommandStack\n\n");

	for (int i = 0; i <= 30; i++)
	{
		printf("%p\t%d\n", command_stack[i].pointer,command_stack[i].descriptor);
	}


	system("pause");
	return 0;
}