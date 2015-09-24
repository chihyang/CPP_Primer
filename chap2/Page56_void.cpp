#include<iostream>

int main()
{
	int iobj = 0, *pi = &iobj;
	double dobj = 3.14, *pd = &dobj;
	void *pv = &dobj;
	// compare void pointer with another type.
	if(pv == pd)
		std::cout << "void pointer can be compared with any pointer." << std::endl;
	pv = pi;
	if(pv == pd)
		std::cout << "pv is equal to pd." << std::endl;
	else
		std::cout << "pv isn't equal to pd." << std::endl;
	return 0;
}