#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	int i;
	int j;
	char *p;
	p = "HELLO 42";
	//cspdiuxX
	i = ft_printf("%c %s %p %d %i %u %x %X %%", 'A', p, p, INT_MAX, INT_MIN, UINT64_MAX, INT_MAX, INT_MAX);
	ft_printf("return ; %d\n", i);
	j =    printf("%c %s %p %d %i %u %x %X %%", 'A', p, p, INT_MAX, INT_MIN, UINT64_MAX, INT_MAX, INT_MAX);
	printf("return ; %d\n", j);
	return (0);
}

