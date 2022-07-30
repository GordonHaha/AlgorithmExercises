// https://www.nowcoder.com/practice/8daa4dff9e36409abba2adbe413d6fae

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *l, *r;
        // 是否遇到过左右节点不双全的叶子节点
        bool leaf = false;
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            l = root->left;
            r = root->right;
            if ((leaf && (l || r)) || (!l && r))
            {
                return false;
            }

            if (l)
            {
                q.push(l);
            }
            if (r)
            {
                q.push(r);
            }

            if (!l || !r)
            {
                leaf = true;
            }
        }
        return true;
    }
};

class Solution2
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        queue<TreeNode *> q;
        q.push(root);
        TreeNode *cur;
        bool leaf = false;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                cur = q.front();
                q.pop();
                if (!cur)
                {
                    leaf = true;
                }
                else
                {
                    if (leaf)
                    {
                        return false;
                    } else {
                        q.push(cur->left);
                        q.push(cur->right);
                    }
                }
            }
        }
        return true;
    }
};