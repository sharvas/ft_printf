#include <stdio.h>
#include <string.h>

int main(void)
{
	char *p;

	p = strdup("hhh");
	printf("%8p\n", p);
	p = strcat(p, "x");
	printf("%8p\n", p);
}
