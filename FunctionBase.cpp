#include <math.h>

#include "InternalDefines.h"
#include "FunctionBase.h"
auto plus(double a, double b)
{
	return a + b;
}

auto minus(double a, double b)
{
	return a - b;
}

auto multiply(double a, double b)
{
	return a * b;
}

auto divide(double a, double b)
{
	return a / b;
}

int entier(double a)
{
	return (int)a;
}

auto log(double a, double x)
{
	return log(x) / log(a);
}

auto exp(double a, double x)
{
	return exp(x*log(a));
}
