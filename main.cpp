#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

#include "InternalDefines.h"
#include "StrFuncBase.h"
#include "FunctionBase.h"
#include "formater.h"
#include "FuncForRec.h"



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

	p= StrFormatC(EPage);
	p= StrFormatMD(EPage);
	p= StrFormatPM(EPage);

	OddBracketsDeleter(EPage);

	FinalRepalce(EPage,6);


	
	printf("\n");
	writeln(EPage);
	printf("\n");


	//BinaryWrite(EPage);

	//printf("\n%p \n",EPage);

	system("pause");
	return 0;
}