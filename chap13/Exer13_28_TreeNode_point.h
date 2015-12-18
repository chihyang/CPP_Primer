#ifndef EXER13_28_1_POINT_H
#define EXER13_28_1_POINT_H
#include <iostream>
#include <string>
#include <cstddef>
class TreeNode {
public:
	TreeNode() : count(0), left(nullptr), right(nullptr), use(new std::size_t(1)) {} // an empty node
	TreeNode(const std::string &s) : value(s), count(1), left(nullptr), right(nullptr), use(new std::size_t(1)) {}
	TreeNode(const TreeNode &tp):
	    value(tp.value), count(tp.count), left(tp.left), right(tp.right), use(tp.use) { ++*use; }
	TreeNode& operator=(const TreeNode&);
	std::ostream& read(std::ostream& os) const { os << value << "\t" << count; return os; }
	void write(const std::string &str) { value = str; }
	~TreeNode();
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
	std::size_t *use;
};
TreeNode& TreeNode::operator=(const TreeNode& tp)
{
	++*tp.use;
	if(--*use == 0)
	{
		if(left)
			delete left;
		if(right)
			delete right;
		delete use;
	}
	value = tp.value;
	count = tp.count;
	left = tp.left;
	right = tp.right;
	use = tp.use;
	return *this;
}
TreeNode::~TreeNode()
{
	if(--*use == 0)
	{
		if(left) {
			delete left;
			left = nullptr;
		}
		if(right) {
			delete right;
			right = nullptr;
		}
		delete use;
	}
}
#endif
// Note: one thing we have to watch out for is that left and child might hold
// null. This version is easier to handle than value-like version.