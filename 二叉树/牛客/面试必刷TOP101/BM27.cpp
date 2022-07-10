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
        vector<vector<int>> ans;
        if (!pRoot)
            return ans;

        queue<TreeNode *> q;
        q.push(pRoot);
        TreeNode *cur;
        int level = 0;
        while (!q.empty())
        {
            vector<int> row;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                cur = q.front();
                q.pop();
                if (level % 2 == 0)
                {
                    row.push_back(cur->val);
                }
                else
                {
                    row.insert(row.begin(), cur->val);
                }
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
            level++;
            if (!row.empty())
            {
                ans.push_back(row);
            }
        }
        return ans;
    }
};