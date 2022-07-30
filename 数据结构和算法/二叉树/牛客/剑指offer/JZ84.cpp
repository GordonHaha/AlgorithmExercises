// https://www.nowcoder.com/practice/965fef32cae14a17a8e86c76ffe3131f
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return int整型
     */
    int count = 0;
    void find(TreeNode *root, int sum)
    {
        if (!root)
            return;
        if (sum == root->val)
        {
            count++;
        }

        find(root->left, sum - root->val);
        find(root->right, sum - root->val);
    }

    int FindPath(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        find(root, sum);
        FindPath(root->left, sum);
        FindPath(root->right, sum);
        return count;
    }
};