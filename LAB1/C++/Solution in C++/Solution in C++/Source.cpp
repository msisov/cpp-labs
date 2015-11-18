#include <iostream>

void f();

void main()
{
	f("abc", 2.0);
}

void f()
{
	std::cout << ("Hello\n");
}