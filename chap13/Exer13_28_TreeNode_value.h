#ifndef EXER13_28_1_VALUE_H
#define EXER13_28_1_VALUE_H
#include <iostream>
#include <string>
#include <cstddef>
class TreeNode {
public:
    TreeNode() : count(1), left(nullptr), right(nullptr) {} // an empty node
    TreeNode(const std::string &s) : value(s), count(1), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &tp);
    TreeNode& operator=(const TreeNode&);
    std::ostream& read(std::ostream& os) const { os << value << "\t" << count; return os; }
    void write(const std::string &str) { value = str; }
    ~TreeNode();
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};
TreeNode::TreeNode(const TreeNode &tp) : value(tp.value), count(tp.count), left(new TreeNode()), right(new TreeNode())
{
    if(tp.left)
        *left = *tp.left;
    else
        left = nullptr;
    if(tp.right)
        *right = *tp.right;
    else
        right = nullptr;
}
TreeNode& TreeNode::operator=(const TreeNode& tp)
{
    if(tp.left){
        auto newp_left = new TreeNode(*tp.left);
        delete left;
        left = newp_left;
    }
    else
        left = nullptr;
    if(tp.right) {
        auto newp_right = new TreeNode(*tp.right);
        delete right;
        right = newp_right;
    }
    else
        right = nullptr;
    value = tp.value;
    count = tp.count;
    return *this;
}
TreeNode::~TreeNode()
{
    if(left) {
        delete left;
        left = nullptr;
    }
    if(right) {
        delete right;
        right = nullptr;
    }
}
#endif
// Note: TreeNode has pointer members of its own type. That implies constructor
// and destructor might be called recursively. Thus we have to find out a way to
// suspend the recursion. Because the node of a tree can have no child, the value
// of left and right might be null. We can use this as the condition to judge if
// the recursion should stop. First we write copy constructor and destructor, then
// combine them to copy-assignment operator.
