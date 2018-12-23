#pragma once

//подсчёт интеграла от функции введённой с клавиатуры
double dIntegral(ConstNumber* constant_stack, control* command_stack, double from, double to, double step);

//подсчёт интеграла от функции по указателю
double dIntegral(double(*func)(double x), double from, double to, double step);