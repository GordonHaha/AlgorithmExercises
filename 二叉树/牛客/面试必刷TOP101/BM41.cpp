// https://www.nowcoder.com/practice/c9480213597e45f4807880c763ddd5f0

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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */

    unordered_map<int, int> index;
    TreeNode *myBuild(const vector<int> &xianxu, int L1, int R1, const vector<int> &zhongxu, int L2, int R2)
    {
        if (L1 > R1)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(xianxu[L1]);
        if (L1 == R1)
        {
            return root;
        }

        int find = index[root->val];

        root->left = myBuild(xianxu, L1 + 1, L1 + find - L2, zhongxu, L2, find - 1);
        root->right = myBuild(xianxu, L1 + find - L2 + 1, R1, zhongxu, find + 1, R2);
        return root;
    }

    vector<int> solve(vector<int> &xianxu, vector<int> &zhongxu)
    {
        vector<int> res;
        if (xianxu.empty() || zhongxu.empty() || xianxu.size() != zhongxu.size())
        {
            return res;
        }

        for (int i = 0; i < xianxu.size(); i++)
        {
            index[zhongxu[i]] = i;
        }

        TreeNode *root = myBuild(xianxu, 0, xianxu.size() - 1, zhongxu, 0, zhongxu.size() - 1);
        // 层序遍历，每层最后一个节点加入数组
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (i == n - 1)
                    res.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return res;
    }
};