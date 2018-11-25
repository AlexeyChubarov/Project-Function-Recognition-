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
	EPage = (unsigned*)VirtualAlloc(NULL, PageSize, MEM_COMMIT, PAGE_READWRITE);
	readln(EPage);

	p = StrFormat—(EPage);
	p=StrFormatMD(EPage);
	p= StrFormatPM(EPage);

	FinalRepalce(EPage, 4.5,2);

	
	printf("\n");
	writeln(EPage);
	printf("\n");


	//BinaryWrite(EPage);

	//printf("\n%p \n",EPage);

	system("pause");
	return 0;
}