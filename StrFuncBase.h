#pragma once

//функция считывает символы до перевода строки
void readln(unsigned* StrCurrentAddress);

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
