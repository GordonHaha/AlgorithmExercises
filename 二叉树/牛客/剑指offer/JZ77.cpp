// https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0
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
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        if (!pRoot)
            return res;

        queue<TreeNode *> q;
        int level = 0;
        q.push(pRoot);
        while (!q.empty())
        {
            vector<int> row;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (!cur)
                    continue;
                q.push(cur->left);
                q.push(cur->right);
                if (level % 2 == 0)
                {
                    row.push_back(cur->val);
                }
                else
                {
                    row.insert(row.begin(), cur->val);
                }
            }
            level++;
            if (!row.empty())
                res.push_back(row);
        }
        return res;
    }
};