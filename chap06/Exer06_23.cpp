#include <iostream>
using std::cout;
using std::endl;
void print(const int (&arr)[10])
{
	for(auto elem : arr)
		cout << elem << " ";
	cout << endl;
}
void print(const int (&arr)[2])
{
	for(auto elem : arr)
		cout << elem << " ";
	cout << endl;
}
void print(const int i)
{
	cout << i << endl;
}
int main()
{
	int i = 0, j[2] = {0, 1};
	int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "int i:" << endl;
	print(i);
	cout << "array j[2]:" << endl;
	print(j);
	cout << "array k[10]:" << endl;
	print(k);
	return 0;
}