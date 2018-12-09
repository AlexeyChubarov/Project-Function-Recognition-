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


control* CommandStackCreator(unsigned* StrCurrentAddress)
{
	control* CommandStack = (control*)calloc(COMMAND_STACK_MAX, sizeof(control));

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

			if ((buf[0] <= '9') and (buf[0] >= '0'))
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
			
			if (*((char*)StrCurrentAddress + i) == '(')
		{
			//арифметические операции
			if ((buf[0] == 'p') and (buf[1] == 'l') and (buf[2] == 'u')and (buf[3] = 's'))
			{
				PushToCommand(CommandStack, { (unsigned*)0x10001000, 2 });
				j = -1;
			}
			else 

				if ((buf[0] == 'm') and (buf[1] == 'i') and (buf[2] == 'n') and (buf[3] == 'u') and (buf[4] = 's'))
				{
					PushToCommand(CommandStack, { (unsigned*)0x10002000, 2 });
					j = -1;
				} 
				else
					  
					if ((buf[0] == 'm') and (buf[1] == 'u') and(buf[2]=='l')and (buf[3] == 't')and (buf[4] = 'i') and (buf[5] = 'p') and (buf[6] = 'l') and (buf[7] = 'y'))
						{
							PushToCommand(CommandStack, { (unsigned*)0x10003000, 2 });
							j = -1;
						}
					 
					else
					
						if ((buf[0] == 'd') and (buf[1] == 'i') and (buf[2] == 'v') and (buf[3] == 'i') and (buf[4] = 'd') and (buf[5] = 'e'))
							{
								PushToCommand(CommandStack, { (unsigned*)0x10004000, 2 });
								j = -1;
							}

						else
			//степенная, показательная, степенно-показательная функция, логарифмическая функция
			if ((buf[0] == 'p') and (buf[1] == 'o') and (buf[2] == 'w'))
			{
				PushToCommand(CommandStack, { (unsigned*)0x20001000, 2 });
				j = -1;
			} 
			else
				if ((buf[0] == 'e') and (buf[1] == 'x') and (buf[2] == 'p'))
				{
					PushToCommand(CommandStack, { (unsigned*)0x20002000, 1 });
					j = -1;
				}
				else
					if ((buf[0] == 's') and (buf[1] == 'q') and (buf[2] == 'r'))
					{
						PushToCommand(CommandStack, { (unsigned*)0x20003000, 1 });
						j = -1;
					}
					else
						if ((buf[0] == 'l') and (buf[1] == 'n'))
						{
							PushToCommand(CommandStack, { (unsigned*)0x20004000, 1 });
							j = -1;
						}
						else
							if ((buf[0] == 'l') and (buf[1] == 'g'))
							{
								PushToCommand(CommandStack, { (unsigned*)0x20005000, 1 });
								j = -1;
							}
							else
								if ((buf[0] == 'l') and (buf[1] == 'o') and (buf[2] == 'g'))
								{
									PushToCommand(CommandStack, { (unsigned*)0x20006000, 2 });
									j = -1;
								}
								else
									if ((buf[0] == 's') and (buf[1] == 'q') and (buf[2] == 'r') and (buf[3] == 't'))
									{
										PushToCommand(CommandStack, { (unsigned*)0x20007000, 1 });
										j = -1;
									}
									else
										if ((buf[0] == 'c') and (buf[1] == 'b') and (buf[2] == 'r') and (buf[3] == 't'))
										{
											PushToCommand(CommandStack, { (unsigned*)0x20008000, 1 });
											j = -1;
										}
						
			//тригонометрические функции
	
							if ((buf[0] == 's') and (buf[1] == 'i') and (buf[2] == 'n'))
							{
							  PushToCommand(CommandStack, { (unsigned*)0x30001000, 1 });
							  j = -1;
							} 
							else 
								if ((buf[0] == 'c') and (buf[1] == 'o') and (buf[2] == 's')and(buf[3]!='e')and(buf[4]!='c'))
								{
									PushToCommand(CommandStack, { (unsigned*)0x30002000, 1 });
									j = -1;
								}
								else
									if (
										((buf[0] == 't') and (buf[1] == 'a') and (buf[2] == 'n'))
										or
										((buf[0] == 't') and (buf[1] == 'g'))
									   )
									{
										PushToCommand(CommandStack, { (unsigned*)0x30003000, 1 });
										j = -1;
									}
									else
										if (
											((buf[0] == 'c') and (buf[1] == 'o') and (buf[2] == 't'))
											or
											((buf[0]=='c')and(buf[1] == 't') and (buf[2] == 'g'))
											)
										{
											PushToCommand(CommandStack, { (unsigned*)0x30004000, 1 });
											j = -1;
										}
										else
											if (
												(buf[0] == 's') and (buf[1] == 'e') and (buf[2] == 'c')
											   )
											{
												PushToCommand(CommandStack, { (unsigned*)0x30005000, 1 });
												j = -1;
											}
											else
												if (
													((buf[0] == 'c') and (buf[1] == 'o') and (buf[2] == 's')and(buf[3]=='e')and(buf[4]='c'))
													or
													((buf[0] == 'c') and (buf[1] == 's') and (buf[2] == 'c'))
													)
												{
													PushToCommand(CommandStack, { (unsigned*)0x30006000, 1 });
													j = -1;
												}

			//обратные тригонометрические функции
			if (
				((buf[0] == 'a') and (buf[1] == 'r') and (buf[2] == 'c') and (buf[3] == 's') and (buf[4] = 'i') and (buf[5] = 'n'))
				or
				((buf[0] == 'a') and (buf[1] == 's') and (buf[2] == 'i') and (buf[3] = 'n'))
			   )
			{
				PushToCommand(CommandStack, { (unsigned*)0x40001000, 1 });
				j = -1;
			}
			else
				if (
					((buf[0] == 'a') and (buf[1] == 'r') and (buf[2] == 'c') and (buf[3] == 'c') and (buf[4] = 'o') and (buf[5] = 's'))
					or
					((buf[0] == 'a') and (buf[1] == 'c') and (buf[2] == 'o') and (buf[3] = 's'))
					)
				{
					PushToCommand(CommandStack, { (unsigned*)0x40002000, 1 });
					j = -1;
				}
				else
					if (
						((buf[0] == 'a') and (buf[1] == 'r') and (buf[2] == 'c') and (buf[3] == 't') and (buf[4] = 'g'))
						or
						((buf[0] == 'a') and (buf[1] == 't') and (buf[2] == 'a') and (buf[3] = 'n'))
						)
					{
						PushToCommand(CommandStack, { (unsigned*)0x40003000, 1 });
						j = -1;
					}
					else
						if (
							((buf[0] == 'a') and (buf[1] == 'r') and (buf[2] == 'c') and (buf[3] == 'c') and (buf[4] = 't') and (buf[5] = 'g'))
							or
							((buf[0] == 'a') and (buf[1] == 'c') and (buf[2] == 'o') and (buf[3] = 't'))
							)
						{
							PushToCommand(CommandStack, { (unsigned*)0x40004000, 1 });
							j = -1;
						}
			

			
		} 
		else 
			buf[j] = *((char*)StrCurrentAddress + i);

		inc(i);
		inc(j);

	}
	
	return CommandStack;
}

ConstNumber* ConstantStackCreator(unsigned* StrCurrentAddress)
{
	ConstNumber* ConstantStack = (ConstNumber*)calloc(CONSTANT_STACK_MAX, sizeof(ConstNumber));

	ConstantStack[0].constant = 0.;
	ConstantStack[0].position = -1;

	int i = 0;
	int j = 0;

	char buf[20] = {};
	
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
							buf[k] = ' ';

						j = -1;

						break;

					}
					else
						buf[j] = *((char*)StrCurrentAddress + i);


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
						buf[j] = *((char*)StrCurrentAddress + i);


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


/* double Counter(ConstNumber* constant_stack, control* command_stack, double x)
{


}
*/