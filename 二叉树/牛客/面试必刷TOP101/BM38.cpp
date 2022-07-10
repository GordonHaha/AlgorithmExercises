// https://www.nowcoder.com/practice/e0cc33a83afe4530bcec46eba3325116
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 方法一 暴力递归
class Solution1
{
public:
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    TreeNode *LCA(TreeNode *root, int o1, int o2)
    {
        if (!root)
            return NULL;
        if (root->val == o1 || root->val == o2)
            return root;

        TreeNode *ln = LCA(root->left, o1, o2);
        TreeNode *rn = LCA(root->right, o1, o2);

        if (!ln)
            return rn;
        if (!rn)
            return ln;
        return root;
    }

    int lowestCommonAncestor(TreeNode *root, int o1, int o2)
    {
        return LCA(root, o1, o2)->val;
    }
};

// 方法二 层序遍历
class Solution2
{
public:
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode *root, int o1, int o2)
    {
        // 记录每个节点的父节点
        unordered_map<int, int> f;
        // 记录bfs队列
        queue<TreeNode *> q;
        q.push(root);
        // 找到o1和o2的父节点即可停止
        while (!f[o1] || !f[o2])
        {
            TreeNode *cur = q.front();
            q.pop();
            TreeNode *l = cur->left, *r = cur->right;

            // 如果当前点有左孩子，那么记录下左孩子的父子关系，并且加入队列
            if (l)
            {
                q.push(l);
                f[l->val] = cur->val;
            }
            if (r)
            {
                q.push(r);
                f[r->val] = cur->val;
            }
        }

        // path记录root到o1的路径，无序即可
        unordered_set<int> path;
        while (f[o1])
        {
            path.insert(o1);
            o1 = f[o1];
        }

        // 找到o2到root的路径中，第一个跟path有交集的点，即为答案
        while (path.find(o2) == path.end() && o2 != root->val)
        {
            o2 = f[o2];
        }

        return o2;
    }
};