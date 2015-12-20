#include <iostream>
#include <forward_list>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::forward_list;
using std::istream_iterator;
int main()
{
	// #1, single-pass iterator
	istream_iterator<int> in_iter(cin), in_iter2;
	int i = *in_iter;
	cin.setstate(istream::failbit); // invalidate cin
	in_iter2 = in_iter++; // increment in_iter and assign original to in_iter2
	cout << *in_iter << " " << *in_iter2 << endl;
	if(++in_iter2 == in_iter)
		cout << "in_iter == in_iter2" << endl;
	else
		cout << "in_iter != in_iter2" << endl;
	// #2, multi-pass iterator
	forward_list<int> flst = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto flst_iter = flst.begin(), flst_iter2 = flst_iter++;
	cout << *flst_iter << " " << *flst_iter2 << endl;
	flst_iter = flst_iter2;
	cout << *flst_iter << " " << *flst_iter2 << endl;
	if(++flst_iter2 == flst_iter)
		cout << "flst_inter2 == flst_iter" << endl;
	else
		cout << "flst_inter2 != flst_iter" << endl;
	return 0;
}
// ******Result compiled by cl******
// 1
// 1 1
// in_iter == in_iter2
// 2 1
// 1 1
// flst_inter2 != flst_iter

// ******Result compiled by G++******
// 1
// 1 1
// in_iter == in_iter2
// 2 1
// 1 1
// flst_inter2 != flst_iter

// Note #1: first take a look at #1, line 13 defines two istream_iterators. in_iter
// is initialized with cin, while in_iter2 is off-the-end iterator. Then we
// initialize int i with *in_iter, which means getting an int from standard 
// input and initializing i with it. Then we set flag fail of cin, thus we can't
// input anything else. But we can still increment in_iter and assign its old 
// value to in_iter2. Now it seems that in_iter and in_iter2 have different 
// values. However, when we output both values that in_iter and in_iter2 refer 
// to, we get the same result. When we increment in_iter2 and then compare it with
// in_iter, the result is still equal. It seems as if before we increment in_iter2
// and after it in_iter2 is still the same as in_iter, although not really. 
// Because increment of istream_iterator is defined as reading next value from 
// the input stream using the >> operator for the element type. Dereference is 
// defined to return the value read from the stream. After we increment or 
// dereference an istream_iterator, the state of a stream might change. When we 
// use the in_iter2 assigned with in_iter, we are not guaranteed the state of 
// in_iter2 keeps unchanged. This is why line 17 outputs two identical values.

// Note #2: Here things seem much clearer. When we assign a forward iterator with
// another, state of the former is certain. We know what it refers to. So the
// output result is easy to predict.

// Note #3: "pass" in "single-pass" and "multi-pass" on page 410 means "go or move 
// past something", it doesn't mean "give". So the "multi-pass" means one 
// iterator can "pass by" one element or position multiple times, "single-pass" 
// means one can only "pass by" one element once.