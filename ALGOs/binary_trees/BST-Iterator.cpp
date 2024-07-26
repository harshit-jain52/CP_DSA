#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
    stack<TreeNode *> st1, st2;

    void pushAll1(TreeNode *root)
    {
        while (root)
        {
            st1.push(root);
            root = root->left;
        }
    }

    void pushAll2(TreeNode *root)
    {
        while (root)
        {
            st2.push(root);
            root = root->right;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAll1(root);
        pushAll2(root);
    }

    int next()
    {
        TreeNode *topNode = st1.top();
        st1.pop();
        pushAll1(topNode->right);
        return topNode->val;
    }

    bool hasNext()
    {
        return !st1.empty();
    }

    int prev()
    {
        TreeNode *topNode = st2.top();
        st2.pop();
        pushAll2(topNode->left);
        return topNode->val;
    }

    bool hasPrev()
    {
        return !st2.empty();
    }
};