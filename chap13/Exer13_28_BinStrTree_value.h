#ifndef EXER13_28_2_VALUE_H
#define EXER13_28_2_VALUE_H
#include <cstddef>
#include "Exer13_28_TreeNode_value.h"
using std::size_t;
class BinStrTree {
public:
	BinStrTree() : root(new TreeNode()) {}
	BinStrTree(const BinStrTree &bp);
	BinStrTree& operator=(const BinStrTree &bp);
	~BinStrTree();
private:
	TreeNode *root;
};
BinStrTree::BinStrTree(const BinStrTree &bp) : root(new TreeNode())
{
	if(bp.root)
		*root = *bp.root;
}
BinStrTree& BinStrTree::operator=(const BinStrTree &bp)
{
	auto newp = new TreeNode(*root);
	delete root;
	root = newp;
	return *this;
}
BinStrTree::~BinStrTree()
{
	delete root;
}
#endif
// Note: because the copy-control members of TreeNode have carefully handled
// everything, here we can use it directly without worrying about dereferencing
// a null pointer or something else.