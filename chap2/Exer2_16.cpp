#include<iostream>
int main()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	// all of the operations below are legal.
	r2 = 3.14159;
	r2 = r1;
	i = r2;
	r1 = d;
	return 0;
}