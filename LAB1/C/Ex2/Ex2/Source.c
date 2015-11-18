#include <stdio.h>

void main()
{
	int c;
	float x;

	//scanf_s("%d", &c);
	//scanf_s("%f", &x);

	scanf_s("%d, %f", &c, &x);
	
	printf("%d, %f", c, x);
	
}