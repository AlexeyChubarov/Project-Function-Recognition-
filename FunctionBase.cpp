#include <math.h>

#include "InternalDefines.h"
#include "FunctionBase.h"
double plus(double a, double b)
{
	return a + b;
}

double minus(double a, double b)
{
	return a - b;
}

double multiply(double a, double b)
{
	return a * b;
}

double divide(double a, double b)
{
	return a / b;
}


double log(double a, double x)
{
	return log(x) / log(a);
}

double sqr(double x)
{
	return x * x;
}

double cot(double x)
{
	return 1 / tan(x);
}

double sec(double x)
{
	return 1 / cos(x);
}

double csc(double x)
{
	return 1 / sin(x);
}

double acot(double x)
{
	return M_Pi / 2 - atan(x);
}

double coth(double x)
{
	return cosh(x) / sinh(x);
}

double acoth(double x)
{
	return 0.5*log((x + 1) / (x - 1));
}