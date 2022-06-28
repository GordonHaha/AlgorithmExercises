#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : val(v) {}
};

// 先序遍历 头左右
void pre(TreeNode *head)
{
    if (!head)
        return;

    cout << head->val << endl;
    pre(head->left);
    pre(head->right);
}

// 中序遍历 左头右
void in(TreeNode *head)
{
    if (!head)
        return;

    in(head->left);
    cout << head->val << endl;
    in(head->right);
}

// 后序遍历 左右头
void pos(TreeNode *head)
{
    if (!head)
        return;
    pos(head->left);
    pos(head->right);
    cout << head->val << endl;
}

int main()
{
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);
    pre(head);
    cout << "==========" << endl;
    in(head);
    cout << "==========" << endl;
    pos(head);
    cout << "==========" << endl;
}

// https://leetcode.cn/problems/same-tree/、
/*
相同的树
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
*/
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p ^ !q)
    {
        return false;
    }

    if (!p && !q)
    {
        return true;
    }

    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// https://leetcode.cn/problems/symmetric-tree/
/*
给你一个二叉树的根节点 root ，检查它是否轴对称。
*/

bool isSymmetric(TreeNode *root)
{
    return isMirror(root, root);
}

bool isMirror(TreeNode *h1, TreeNode *h2)
{
    if (!h1 ^ !h2)
    {
        return false;
    }

    if (!h1 && !h2)
    {
        return true;
    }

    return h1->val == h2->val && isMirror(h1->left, h2->right) && isMirror(h1->right, h2->left);
}

// https://leetcode.cn/problems/maximum-depth-of-binary-tree/
/*
二叉树的最大深度
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
*/

int maxDepth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
/*
从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
*/

// 方法1
TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
    {
        return nullptr;
    }

    return myBuild1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

/*
有一棵树，先序结果是preorder[L1...R1], 中序结果是inorder[L2...R2]
建出整棵树返回头结点
*/
TreeNode *myBuild1(const vector<int> &preorder, int L1, int R1, const vector<int> &inorder, int L2, int R2)
{
    if (L1 > R1)
    {
        return nullptr;
    }

    TreeNode *head = new TreeNode(preorder[L1]);
    // 只有一个节点
    if (L1 == R1)
    {
        return head;
    }

    int find = L2;

    while (inorder[find] != preorder[L1])
    {
        find++;
    }

    head->left = myBuild1(preorder, L1 + 1, L1 + find - L2, inorder, L2, find - 1);
    head->right = myBuild1(preorder, L1 + find - L2 + 1, R1, inorder, find + 1, R2);
    return head;
}

// 方法2
TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
    {
        return nullptr;
    }

    unordered_map<int, int> valIndexMap;
    for (size_t i = 0; i < inorder.size(); i++)
    {
        valIndexMap.insert({inorder[i], i});
    }

    return myBuild2(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, valIndexMap);
}

TreeNode *myBuild2(const vector<int> &preorder, int L1, int R1, const vector<int> &inorder, int L2, int R2, unordered_map<int, int> &valIndexMap)
{
    if (L1 > R1)
    {
        return nullptr;
    }

    TreeNode *head = new TreeNode(preorder[L1]);
    // 只有一个节点
    if (L1 == R1)
    {
        return head;
    }

    int find = valIndexMap[preorder[L1]];

    head->left = myBuild2(preorder, L1 + 1, L1 + find - L2, inorder, L2, find - 1, valIndexMap);
    head->right = myBuild2(preorder, L1 + find - L2 + 1, R1, inorder, find + 1, R2, valIndexMap);
    return head;
}

// https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
/*
二叉树的层序遍历 II
给你二叉树的根节点root,返回其节点值自底向上的层序遍历。（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
*/

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
    {
        return ans;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int size = queue.size();
        vector<int> curAns;
        for (int i = 0; i < size; i++)
        {
            TreeNode *curNode = queue.front();
            queue.pop();
            curAns.push_back(curNode->val);
            if (curNode->left)
            {
                queue.push(curNode->left);
            }
            if (curNode->right)
            {
                queue.push(curNode->right);
            }
        }
        ans.push_back(curAns);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// https://leetcode.cn/problems/balanced-binary-tree/
/*
平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/

bool isBalanced(TreeNode *root)
{
    return process(root)->isBalanced;
}

// 以某个节点头的时候，1）整棵树是否平 2）整棵树的高度是什么
class Info
{
public:
    bool isBalanced;
    int height;

    Info(bool i, int h) : isBalanced(i), height(h){};
};

Info *process(TreeNode *x)
{
    if (!x)
    {
        return new Info(true, 0);
    }

    Info *leftInfo = process(x->left);
    Info *rightInfo = process(x->right);
    int height = max(leftInfo->height, rightInfo->height) + 1;
    bool isBalanced = leftInfo->isBalanced && rightInfo->isBalanced && abs(leftInfo->height - rightInfo->height) < 2;
    return new Info(isBalanced, height);
}

// https://leetcode.cn/problems/validate-binary-search-tree/
/*
验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/

bool isValidBST(TreeNode *root)
{
    return process2(root)->isBST;
}

class Info2
{
public:
    bool isBST;
    int max;
    int min;

    Info2(bool is, int ma, int mi) : isBST(is), max(ma), min(mi){};
};

Info2 *process2(TreeNode *x)
{
    if (!x)
    {
        return nullptr;
    }

    Info2 *leftInfo = process2(x->left);
    Info2 *rightInfo = process2(x->right);
    int maxVal = x->val;
    int minVal = x->val;
    if (leftInfo)
    {
        maxVal = max(leftInfo->max, maxVal);
        minVal = min(leftInfo->min, minVal);
    }

    if (rightInfo)
    {
        maxVal = max(rightInfo->max, maxVal);
        minVal = min(rightInfo->min, minVal);
    }

    bool isBST = true;
    if (leftInfo && !leftInfo->isBST)
    {
        isBST = false;
    }

    if (rightInfo && !rightInfo->isBST)
    {
        isBST = false;
    }

    bool leftMaxLessX = leftInfo ? (leftInfo->max < x->val) : true;
    bool rightMinMoreX = rightInfo ? (rightInfo->min > x->val) : true;

    if (!leftMaxLessX || !rightMinMoreX)
    {
        isBST = false;
    }

    return new Info2(isBST, maxVal, minVal);
}

// https://leetcode.cn/problems/path-sum/
/*
路径总和
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点
*/

bool hasPathSum(TreeNode *root, int sum)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}

// https://leetcode.cn/problems/path-sum-ii/
/*
路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点
*/

vector<vector<int>> res;
void dfs(TreeNode *root, vector<int> &tmp, int sum)
{
    if (!root)
        return;
    tmp.push_back(root->val);
    if (root->val == sum && (root->left == NULL && root->right == NULL))
    {
        res.push_back(tmp);
    }
    dfs(root->left, tmp, sum - root->val);
    dfs(root->right, tmp, sum - root->val);
    tmp.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    vector<int> tmp;
    dfs(root, tmp, sum);
    return res;
}
