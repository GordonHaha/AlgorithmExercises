// https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
public:
    int TreeDepth(TreeNode *pRoot)
    {
        if (!pRoot)
            return 0;
        return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
};