#pragma once

//распознание умножения и деления
unsigned* StrFormatMD(unsigned* StrCurrentAddress);

//распознавание сложения и вычитания
unsigned* StrFormatPM(unsigned* StrCurrentAddress);

//распознавание показательных и степенных функций
unsigned* StrFormatC(unsigned* StrCurrentAddress);

//распознавания стандартного вида числа
void StdTypeOfNumberRecognize(unsigned* StrCurrentAddress);