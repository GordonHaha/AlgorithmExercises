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
    TreeNode *myBuild(const vector<int> &pre, int L1, int R1, const vector<int> &vin, int L2, int R2)
    {
        if (L1 > R1)
        {
            return NULL;
        }

        TreeNode *head = new TreeNode(pre[L1]);
        if (L1 == R1)
        {
            // 只有一个节点
            return head;
        }

        int find = 0;
        // 找到中序中头节点的位置
        while (vin[find] != head->val)
        {
            find++;
        }
        // 左树长度是find-L2
        head->left = myBuild(pre, L1 + 1, L1 + find - L2, vin, L2, find - 1);
        head->right = myBuild(pre, L1 + find - L2 + 1, R1, vin, find + 1, R2);
        return head;
    }
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.empty() || vin.empty() || pre.size() != vin.size())
        {
            return NULL;
        }

        return myBuild(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};