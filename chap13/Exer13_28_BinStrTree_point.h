#ifndef EXER13_28_2_POINT_H
#define EXER13_28_2_POINT_H
#include <cstddef>
#include "Exer13_28_TreeNode_point.h"
using std::size_t;
class BinStrTree {
public:
	BinStrTree() : root(new TreeNode()), use(new size_t(1)) {}
	BinStrTree(const BinStrTree &bp) : root(bp.root), use(bp.use) { ++*use; }
	BinStrTree& operator=(const BinStrTree &bp);
	~BinStrTree();
private:
	TreeNode *root;
	size_t *use;
};
BinStrTree& BinStrTree::operator=(const BinStrTree &bp)
{
	++*bp.use;
	if(--*use == 0)
	{
		delete root;
		delete use;
	}
	root = bp.root;
	use = bp.use;
	return *this;
}
BinStrTree::~BinStrTree()
{
	if(--*use == 0)
	{
		delete root;
		delete use;
	}
}
#endif