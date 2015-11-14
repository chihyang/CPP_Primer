#include <iostream>
#include <string>
#include "Exer13_34_36_37.h"
using std::cout;
using std::endl;
int main()
{
	Folder f1("Inbox");
	Folder f2("Send Box");
	Folder f3("Important Mails");
	Message m1("To Mr. John");
	Message m2 = m1;
	Message m3("To Mrs. King");
	m1.save(f1);
	m2.save(f1);
	m3.save(f2);
	cout << "f1" << endl;
	f1.show();
	cout << "f2" << endl;
	f2.show();
	f3 = f2;
	cout << "f3" << endl;
	f3.show();
	cout << "f3" << endl;
	m3.save(f3);
	m1.save(f3);
	m2.save(f3);
	f3.show();
	cout << "f3" << endl;
	m1.remove(f3);
	f3.show();
	cout << "f2" << endl;
	f2 = f3;
	f2.show();
	return 0;
}