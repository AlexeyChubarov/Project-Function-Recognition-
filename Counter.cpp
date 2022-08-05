#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

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


control* CommandStackCreator(unsigned* StrCurrentAddress,int size)
{
	function e_func[NUMBER_OF_FUNCTION]
	{
		{"plus", {(unsigned*)0x10001000,2}},
		{"minus", {(unsigned*)0x10002000,2}},
		{"multiply", {(unsigned*)0x10003000,2}},
		{"divide", {(unsigned*)0x10004000,2}},

		{"pow", {(unsigned*)0x20001000,2}},
		{"exp", {(unsigned*)0x20002000,1}},
		{"sqr", {(unsigned*)0x20003000,1}},
		{"ln", {(unsigned*)0x20004000,1}},
		{"lg", {(unsigned*)0x20005000,1}},
		{"log", {(unsigned*)0x20006000,2}},
		{"sqrt", {(unsigned*)0x20007000,1}},
		{"cbrt", {(unsigned*)0x20008000,1}},

		{"sin", {(unsigned*)0x30001000,1}},
		{"cos", {(unsigned*)0x30002000,1}},
		{"tg", {(unsigned*)0x30003000,1}},
		{"tan", {(unsigned*)0x30003000,1}},
		{"ctg", {(unsigned*)0x30004000,1}},
		{"cot", {(unsigned*)0x30004000,1}},
		{"sec", {(unsigned*)0x30005000,1}},
		{"cosec", {(unsigned*)0x30006000,1}},
		{"csc", {(unsigned*)0x30006000,1}},

		{"arcsin", {(unsigned*)0x40001000,1}},
		{"asin", {(unsigned*)0x40001000,1}},
		{"arccos", {(unsigned*)0x40002000,1}},
		{"acos", {(unsigned*)0x40002000,1}},
		{"arctg", {(unsigned*)0x40003000,1}},
		{"atan", {(unsigned*)0x40003000,1}},
		{"arcctg", {(unsigned*)0x40004000,1}},
		{"acot", {(unsigned*)0x40004000,1}},

		{"sh", {(unsigned*)0x50001000,1}},
		{"sinh", {(unsigned*)0x50001000,1}},
		{"ch", {(unsigned*)0x50002000,1}},
		{"cosh", {(unsigned*)0x50002000,1}},
		{"th", {(unsigned*)0x50003000,1}},
		{"tanh", {(unsigned*)0x50003000,1}},
		{"cth", {(unsigned*)0x50004000,1}},
		{"coth", {(unsigned*)0x50004000,1}},

		{"arsh", {(unsigned*)0x60001000,1}},
		{"asinh", {(unsigned*)0x60001000,1}},
		{"arch", {(unsigned*)0x60002000,1}},
		{"acosh", {(unsigned*)0x60002000,1}},
		{"arth", {(unsigned*)0x60003000,1}},
		{"atanh", {(unsigned*)0x60003000,1}},
		{"arcth", {(unsigned*)0x60004000,1}},
		{"acoth", {(unsigned*)0x60004000,1}}

	};

	control* CommandStack = (control*)calloc(size+1, sizeof(control));

	CommandStack[0].pointer = NULL;
	CommandStack[0].descriptor = -1;

	unsigned ConstStackNumber = 1;
	char buf[10] = {};

	int i = 0;

	int j = 0;
	while (true)
	{
		if (*((char*)StrCurrentAddress + i) == 10)break;

		if ((*((char*)StrCurrentAddress + i) == ',')or (*((char*)StrCurrentAddress + i) == ')'))
		{
			if ((buf[0] == 'x'))
			{
				PushToCommand(CommandStack, { (unsigned*)(0x00000000), 0 });
				for (int k = 0; k < j; k++)
					buf[k] = ' ';
				j = -1;
			} else

			if (
				((buf[0] <= '9') and (buf[0] >= '0'))
				or
				((buf[0]== '.')and((buf[1] <= '9') and (buf[1] >= '0')))
			   )
			{
				PushToCommand(CommandStack, { (unsigned*)(ConstStackNumber), 0 });
				inc(ConstStackNumber);
				for (int k = 0; k < j; k++)
					buf[k] = ' ';
				j = -1;

			}
			else
				if ((*((char*)StrCurrentAddress + i) == ')')or (*((char*)StrCurrentAddress + i) == ',')) j = -1;
		} 
		else
			if ((*((char*)StrCurrentAddress + i) == '('))
			{
				buf[j] = '\0';

				for (int k = 0; k < NUMBER_OF_FUNCTION; k++)
				{
					if (strcmp(buf, (e_func[k].name)) == 0)
					{
						PushToCommand(CommandStack, e_func[k].setting);
						break;
					}
				}

				j = -1;
			}
			else
			{
				if (j == 10)j = 0;
				buf[j] = *((char*)StrCurrentAddress + i);
			}
			

		inc(i);
		inc(j);

	}
	
	return CommandStack;
}

ConstNumber* ConstantStackCreator(unsigned* StrCurrentAddress,int size)
{
	ConstNumber* ConstantStack = (ConstNumber*)calloc(size+1, sizeof(ConstNumber));

	ConstantStack[0].constant = 0.;
	ConstantStack[0].position = -1;

	int i = 0;
	int j = 0;

	char buf[100] = {};
	
	int counter = 1;

	while (true)
	{
		if (*((char*)StrCurrentAddress + i) == 10)break;

		if ((i == 0) and (*((char*)StrCurrentAddress + i) <= '9') and (*((char*)StrCurrentAddress + i) >= '0'))
		{
			if ((*((char*)StrCurrentAddress + i) >= '0') and (*((char*)StrCurrentAddress + i) <= '9'))
			{
				while (true)
				{
					if ((*((char*)StrCurrentAddress + i) == ',') or (*((char*)StrCurrentAddress + i) == ')') or (*((char*)StrCurrentAddress + i) == '\n'))
					{
						double d;

						sscanf_s(buf, "%lf", &d);

						PushToConstant(ConstantStack, { d,counter });

						inc(counter);

						for (int k = 0; k < j; k++)
							buf[k] = '\0';

						j = -1;

						break;

					}
					else
					{
						if (j >= 100)
						{
							fprintf(stderr, "ERROR!! You printed too long number (more 100 sumbols). Please round it!!\n");
							system("pause");
							exit(0x10002000);
						} else
						buf[j] = *((char*)StrCurrentAddress + i);

					}

					if (*((char*)StrCurrentAddress + i) == 10)break;

					inc(i);
					inc(j);

				}


			}
		}
		if (
			(*((char*)StrCurrentAddress + i) == '(')or(*((char*)StrCurrentAddress + i) == ',')
		   )
		{
			inc(i);

			if ((*((char*)StrCurrentAddress + i) >= '0') and (*((char*)StrCurrentAddress + i) <= '9'))
			{
				while (true)
				{
					if ((*((char*)StrCurrentAddress + i) == ',') or (*((char*)StrCurrentAddress + i) == ')')or (*((char*)StrCurrentAddress + i) == '\n'))
					{
						double d;
						
						sscanf_s(buf, "%lf", &d);

						PushToConstant(ConstantStack, { d,counter });

						inc(counter);

						for (int k = 0; k < j; k++)
							buf[k] = 0;
						i--;

						j = 0;

						break;

					}
					else
					{
						if (j >= 100)
						{
							fprintf(stderr, "ERROR!! You printed too long number (more 100 sumbols). Please round it!!\n");
							system("pause");
							exit(0x10002000);
						}
						else
							buf[j] = *((char*)StrCurrentAddress + i);

					}

					

					if (*((char*)StrCurrentAddress + i) == 10)break;

					inc(i);
					inc(j);
					
				}


			} 
		}

		inc(i);

	}

	return ConstantStack;

	
}


 double Counter(ConstNumber* constant_stack, control* command_stack, double x)
{
	 func2arg func2a[F_2_ARG]=
	 {
		 {(unsigned*)0x10001000,plus},
		 {(unsigned*)0x10002000,minus},
		 {(unsigned*)0x10003000,multiply},
		 {(unsigned*)0x10004000,divide},

		 {(unsigned*)0x20001000,pow},
		 {(unsigned*)0x20006000,log}
	 };

	 func1arg func1a[F_1_ARG]=
	 {
		 {(unsigned*)0x20002000,exp},
		 {(unsigned*)0x20003000,sqr},
		 {(unsigned*)0x20004000,log},
		 {(unsigned*)0x20005000,log10},
		 {(unsigned*)0x20007000,sqrt},
		 {(unsigned*)0x20008000,cbrt},

		 {(unsigned*)0x30001000,sin},
		 {(unsigned*)0x30002000,cos},
		 {(unsigned*)0x30003000,tan},
		 {(unsigned*)0x30004000,cot},
		 {(unsigned*)0x30005000,sec},
		 {(unsigned*)0x30006000,csc},

		 {(unsigned*)0x40001000,asin},
		 {(unsigned*)0x40002000,acos},
		 {(unsigned*)0x40003000,atan},
		 {(unsigned*)0x40004000,acot},

		 {(unsigned*)0x50001000,sinh},
		 {(unsigned*)0x50002000,cosh},
		 {(unsigned*)0x50003000,tanh},
		 {(unsigned*)0x50004000,coth},

		 {(unsigned*)0x60001000,asinh},
		 {(unsigned*)0x60002000,acosh},
		 {(unsigned*)0x60003000,atanh},
		 {(unsigned*)0x60004000,acoth}

	 };

	 int i=0;
	 int j=0;
	 double arg1 = 0, arg2 = 0;
	 count* exe_stack = (count*)calloc((size_t)(CountExeStack(command_stack)+1), sizeof(count));
	 exe_stack[0].number = 0;
	 exe_stack[0].position = -1;

	 if (((command_stack)[i].descriptor == -1) and (command_stack[i].pointer == 0x00000000))
	 {
		 return constant_stack[i].constant;
	 }
	 while (true)
	 {
		 if (command_stack[i].descriptor == -1)break;

		 if ((command_stack[i].descriptor == 0)and(command_stack[i].pointer!=0x00000000))
		 {
			 PushToStack(exe_stack, { constant_stack[j].constant,1 });
			 inc(j);
		 }

		 if ((command_stack[i].descriptor == 0) and (command_stack[i].pointer == 0x00000000))
		 {
			 PushToStack(exe_stack, { x,1 });
		 }

		 if (command_stack[i].descriptor == 1)
		 {
			 for (int k = 0; k < F_1_ARG;k++)
			 {
				 if (func1a[k].description == command_stack[i].pointer)
				 {
					 arg1 = PopFromStack(exe_stack);
					 PushToStack(exe_stack, { func1a[k].func(arg1),1 });
					 break;
				 }
			 }
		 }

		 if (command_stack[i].descriptor == 2)
		 {
			 for (int k = 0; k < F_2_ARG; k++)
			 {
				 if (func2a[k].description == command_stack[i].pointer)
				 {
					 arg1 = PopFromStack(exe_stack);
					 arg2 = PopFromStack(exe_stack);
					 PushToStack(exe_stack, { func2a[k].func(arg1,arg2),2 });
					 break;

				 }
			 }
		 }

		 inc(i);
	 }
	 arg1 = exe_stack[0].number;
	 free(exe_stack);

	 return arg1;
}
