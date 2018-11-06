#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

#include "InternalDefines.h"
#include "StrFuncBase.h"
#include "FunctionBase.h"


int main()
{
	unsigned *EPage;

	EPage = (unsigned*)VirtualAlloc(NULL, PageSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	readln(EPage);

	printf("\n");

	del((unsigned*)((char*)EPage+4), 4);

	writeln(EPage);
	printf("\n");
	
	system("pause");
	return 0;
}