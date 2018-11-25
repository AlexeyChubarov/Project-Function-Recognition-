#pragma once

//функция считывает символы до перевода строки
unsigned* readln(unsigned* StrCurrentAddress);

//функция считывает определённое количество символов
void read(unsigned* StrCurrentAddress, unsigned quantity);

//функция выводит символы до перевода строки
void writeln(unsigned* StrCurrentAddress);

//функция выводит определённое количество символов строки
void write(unsigned* StrCurrentAddress, unsigned quantity);

//сдвиг строки вправо
void shift(unsigned* StartPoint, unsigned step);

//сдвиг строки влево (удаление символов)
void del(unsigned* StartPoint, unsigned step);

//добавление в строку
unsigned * add(unsigned* StartPoint, const char *Element,unsigned length);

//замена символов в строке
unsigned * replace(unsigned * StartPoint, unsigned symbols, const char* Element, unsigned length);

//вывод символов в строке
unsigned BinaryWrite(unsigned* EPage);
