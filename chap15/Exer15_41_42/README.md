* Exercise 15.41

This exercise uses pointer-like assignment and copy, so we need substitute ```new```, ```delete``` and reference count for ```shared_ptr```. We have to define all of the copy-control members.

* Exercise 15.42
	* (a) - [x] To be solved.
	* (b)
	We can use a ```vector<Query>``` to store query history. But this might not be the best way. There could be some enhancement.
	* (c)
	We can add another two parameter to the function ```print```:
	```cpp
	std::ostream& print(std::ostream &os, const QueryResult &qr, TextQuery::line_no min, TextQuery::line_no max);
	```
	Thus the user is allowed to limit the range of output.