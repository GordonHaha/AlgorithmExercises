// https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *myBuild(vector<int> pre, int l1, int r1, vector<int> vin, int l2, int r2)
    {
        if (l1 > r1)
            return NULL;
        if (l1 == r1)
            return new TreeNode(pre[l1]);

        TreeNode *root = new TreeNode(pre[l1]);
        int find = 0;
        while (vin[find] != pre[l1])
        {
            find++;
        }

        root->left = myBuild(pre, l1 + 1, l1 + find - l2, vin, l2, find - 1);
        root->right = myBuild(pre, l1 + 1 + find - l2, r1, vin, find + 1, r2);
        return root;
    }

    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() * vin.size() == 0 || pre.size() != vin.size())
            return NULL;
        TreeNode *root = myBuild(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
        return root;
    }
};