// https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution
{
public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        if (!pRoot)
            return res;
        queue<TreeNode *> q;
        q.push(pRoot);
        while (!q.empty())
        {
            vector<int> row;
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                row.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back(row);
        }
        return res;
    }
};