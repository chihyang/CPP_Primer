#include <iostream>
#include <forward_list>
#include <list>
using std::cout;
using std::endl;
using std::forward_list;
using std::list;
int main()
{
	forward_list<int> fi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> li = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto fiter_prev = fi.before_begin();
	auto fiter = fi.begin();
	auto liter = li.begin();
	while(fiter != fi.end())
	{
		if(*fiter % 2)
		{
			// for iterator of a forward_list, we have to use insert_after, which 
			// returns an iterator to the last inserted element
			fi.insert_after(fiter_prev, *fiter);
			fiter_prev = fiter;
			++fiter;
		}
		else
		{
			// erase_after returns an iterator to the element after the one deleted
			// so just assigning it to fiter is okay, but we have to use fiter_prev 
			// as argument
			fiter = fi.erase_after(fiter_prev);
		}
	}
	while(liter != li.end())
	{
		if(*liter % 2)
		{
			li.insert(liter, *liter);
			// we cannot use += for iterator of a list, but using after insert, 
			// the iterator keeps valid, so we can use liter directly
			++liter;
		}
		else
		{
			liter = li.erase(liter);
		}
	}
	for(auto &i : fi)
		cout << i << " ";
	cout << endl;
	for(auto &i : li)
		cout << i << " ";
	cout << endl;
	return 0;
}