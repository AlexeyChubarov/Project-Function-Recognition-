#pragma once

//замена аргументов на число
void FinalRepalce(unsigned** StrCurrentAddress, int* SizeOfPage, unsigned accurancy);

//удаление лишних скобок
unsigned* OddBracketsDeleter(unsigned* StrCurrentAddress);

//проверка на соответствие скобок
bool BracketAccordance(unsigned* StrCurrentAddress);

//удаление пробелов и табуляций
void OddSpacesDeleter(unsigned* StrCurrentAddress);