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

auto log_(double a, double x)
{
	return log10(x) / log10(a);
}

auto exp_(double a, double x)
{
	return exp(x*log_(M_E, a));
}

auto p_(double x, double alpha)
{
	return exp(alpha*log_(M_E, x));
}
