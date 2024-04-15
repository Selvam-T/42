#include <inttypes.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int i = 0;
	int j = 0;
	char c = 'A';
	char *ptr = NULL;
	char *s = "";
	unsigned int num = 4294967295;
	char	*f;

	//%%
  printf("================================================================\n");
	printf("\n1, Test: %%\n");
  i = printf("%%");
  printf("\n---\n");
  j = ft_printf("%%");
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
  printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	//%c
  printf("================================================================\n");
	printf("\n2, Test: c\n");
  i = ft_printf("%c, %c, %c, %c ,%c, %c \n",'\n', c, ' ', '$', '\t', 90);
  printf("--------------------\n");
  j = ft_printf("%c, %c, %c, %c ,%c, %c \n",'\n', c, ' ', '$', '\t', 90);
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
	printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	//%s
	printf("================================================================\n");
  printf("\n3, Test: s\n");
  //i = printf("%s, %s, %s, %s\n",ptr, "", "Hello",s);
  i = printf("%s\n",ptr);
  printf("-----------------\n");
  //j = ft_printf("%s, %s, %s, %s\n",ptr, "", "Hello",s);
  j = ft_printf("%s\n",ptr);
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
	printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	//%d %i
	printf("================================================================\n");
  printf("\n4, Test: d,i\n");
  i = printf("%d, %d, %d, %d, %d\n",-2147483647, -1, 0, 1, 2147483647);
  printf("---------------------------------\n");
  j = ft_printf("%d, %d, %d, %d, %d\n",-2147483647, -1, 0, 1, 2147483647);
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
	printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	//%u
	printf("================================================================\n");
  printf("\n5, Test: u\n");
  i = printf("%u %u %u\n",0, -1, num);
  printf("------------------------\n");
  j = ft_printf("%u %u %u\n",0, -1, num);
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
	printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	printf("Fail? Did -1 roll over to Max value? Ignore if it does not ?\n");
	//%p
	printf("================================================================\n");
  printf("\n6, Test: p\n");
	f = "%p, %p, %p, %p\n";
  i = printf(f,ptr, s, LONG_MAX, ULONG_MAX);
  printf("-------------------------------------------------------------\n");
  j = ft_printf(f,ptr, s, LONG_MAX, ULONG_MAX);
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
	printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	//%x
	printf("================================================================\n");
  printf("\n7, Test: x\n");
  i = printf("%x, %x, %x, %x, %x, %x \n",-1, 0, 1, num, 2748, 53441);
  printf("------------------------------------\n");
  j = ft_printf("%x, %x, %x, %x, %x, %x \n",-1, 0, 1, num, 2748, 53441);
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
	printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	printf("Note that -1 in Hex rolls over to Unsigned integer MAX ffffffff\n");
	//%X
	printf("================================================================\n");
  printf("\n8, Test: X\n");
  i = printf("%X, %X \n",43962, 241);
  printf("--------\n");
  j = ft_printf("%X, %X \n",43962, 241);
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
	printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	//normal string
	printf("================================================================\n");
  printf("\n9, Test: no specifiers\n");
  i = printf("This line has no format specifiers.\n");
  printf("------------------------------------\n");
  j = ft_printf("This line has no format specifiers.\n");
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
	printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	//all
  printf("================================================================\n");
  printf("\n10, Test: all specifiers\n");
  i = printf("%X %s %c%c %d%% cheaper.\n",43962, "ticket", 'i','s', 10);
  printf("----------------------------\n");
  j = ft_printf("%X %s %c%c %d%% cheaper.\n",43962, "ticket", 'i','s', 10);
  printf("\n");
  printf("p = %d, ft_p = %d \n",i, j);
	printf((i - j == 0) ? "\x1b[32m[Pass]\x1b[0m\n" : "\x1b[31m[Fail]\x1b[0m\n");
	printf("================================================================\n");
  return (0);
}
