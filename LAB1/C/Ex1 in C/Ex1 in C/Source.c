#include <stdio.h>

void f();

void main(void)
{
	f("abc", 2.0); //Nothing happens here
}

void f()
{
	printf("Hello\n");
}