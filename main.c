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
	// i = ft_printf("%010 ##000c\n", 'A');
	// i = ft_printf("%05v\n");
	i = ft_printf("|%+10.0d|\n", 0);
	// i = ft_printf("%c %3s %p %d %i %u %#x %#X %010hjl qtzqqty'hj-lqtzL30h@|$-abcdef\n", 'A', p, p, INT_MAX, INT_MIN, UINT64_MAX, 0, 0);
	// i = ft_printf("%-10 ## +'hjlqt9zLhjlqtz&qh$abcdef\n");
	ft_printf("return ; %d\n", i);
	j = printf("|%+10.0d|\n", 0);
	j =    printf("%c %3s %p %d %i %u %#x %#X %010hjl qtzqqty'hj-lqtzL30h@|$-abcdef\n", 'A', p, p, INT_MAX, INT_MIN, UINT64_MAX, 0, 0);
	// j =    printf("%*%\n", INT_MAX-1);
	// j =    printf("%010 ##000c\n", 'A');
	j =    printf("%-10 ## +'hjlqt9zLhjlqtz&qh$abcdef");
	// j = printf("%05v\n");
	printf("return ; %d\n", j);
	// system("leaks a.out");
	// int max = int_max;
	// int min = int_min;
	// printf("\n\n%d", max);
	// adiouxefgcspnm変換指定子
	// hjlqtz長さ修飾子 
	// bkrwy特殊
	// 超特殊 'v'
	return 0;
}

