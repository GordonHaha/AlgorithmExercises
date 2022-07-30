#include <bits/stdc++.h>

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

void pre1(TreeNode *head)
{
    if (head)
    {
        stack<TreeNode *> stack;
        stack.push(head);
        while (!stack.empty())
        {
            head = stack.top();
            stack.pop();
            cout << head->val << endl;
            if (head->right != NULL)
            {
                stack.push(head->right);
            }
            if (head->left != NULL)
            {
                stack.push(head->left);
            }
        }
    }
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

void in1(TreeNode *head)
{
    if (head)
    {
        stack<TreeNode *> stack;
        while (!stack.empty() || head)
        {
            if (head)
            {
                stack.push(head);
                head = head->left;
            }
            else
            {
                head = stack.top();
                stack.pop();
                cout << head->val << endl;
                head = head->right;
            }
        }
    }
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

void pos1(TreeNode *head)
{
    if (head)
    {
        stack<TreeNode *> s1, s2;
        s1.push(head);
        while (!s1.empty())
        {
            head = s1.top();
            s1.pop();
            s2.push(head);
            if (head->left != NULL)
            {
                s1.push(head->left);
            }
            if (head->right != NULL)
            {
                s1.push(head->right);
            }
        }
        while (!s2.empty())
        {
            head = s2.top();
            s2.pop();
            cout << head->val << endl;
        }
    }
}

void pos2(TreeNode *head)
{
    if (head)
    {
        stack<TreeNode *> stack;
        stack.push(head);
        TreeNode *cur;
        while (!stack.empty())
        {
            cur = stack.top();
            if (cur->left && head != cur->left && head != cur->right)
            {
                stack.push(cur->left);
            }
            else if (cur->right && head != cur->right)
            {
                stack.push(cur->right);
            }
            else
            {
                TreeNode *temp = stack.top();
                stack.pop();
                cout << temp->val << endl;
                head = cur;
            }
        }
    }
}

// 二叉树的层序遍历

void level(TreeNode *head)
{
    if (!head)
    {
        return;
    }

    queue<TreeNode *> queue;
    queue.push(head);
    while (!queue.empty())
    {
        TreeNode *cur = queue.front();
        queue.pop();
        cout << cur->val << endl;
        if (cur->left)
        {
            queue.push(cur->left);
        }
        if (cur->right)
        {
            queue.push(cur->right);
        }
    }
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

bool isSymmetric(TreeNode *root)
{
    return isMirror(root, root);
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

TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
    {
        return nullptr;
    }

    return myBuild1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

// 方法2

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

bool isBalanced(TreeNode *root)
{
    return process(root)->isBalanced;
}

// 判断一棵二叉树是否是完全二叉树

bool isCBT1(TreeNode *head)
{
    if (!head)
    {
        return true;
    }

    queue<TreeNode *> queue;
    // 是否遇到过左右两个孩子不双全的节点
    bool leaf = false;
    TreeNode *l, *r;
    queue.push(head);
    while (!queue.empty())
    {
        head = queue.front();
        queue.pop();
        l = head->left;
        r = head->right;
        if ((leaf && (l || r)) || (!l && r))
        {
            return false;
        }
        if (l)
        {
            queue.push(l);
        }
        if (r)
        {
            queue.push(r);
        }
        if (!l || !r)
        {
            leaf = true;
        }
    }
    return true;
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

bool isValidBST(TreeNode *root)
{
    return process2(root)->isBST;
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

// 二叉树序列化

void pres(TreeNode *head, queue<string> ans)
{
    if (!head)
    {
        ans.push(NULL);
    }
    else
    {
        ans.push(to_string(head->val));
        pres(head->left, ans);
        pres(head->right, ans);
    }
}

queue<string> preSerial(TreeNode *head)
{
    queue<string> ans;
    pres(head, ans);
    return ans;
}

// 二叉树反序列化

TreeNode *preb(queue<string> &prelist)
{
    string value = prelist.front();
    prelist.pop();
    if (value.empty())
    {
        return NULL;
    }
    TreeNode *head = new TreeNode(stoi(value));
    head->left = preb(prelist);
    head->right = preb(prelist);
    return head;
}

TreeNode *buildByPreQueue(queue<string> &prelist)
{
    if (prelist.empty())
    {
        return NULL;
    }
    return preb(prelist);
}

// 二叉树层序序列化
queue<string> levelSerial(TreeNode *head)
{
    queue<string> ans;
    if (!head)
    {
        ans.push(NULL);
    }
    else
    {
        ans.push(to_string(head->val));
        queue<TreeNode *> queue;
        queue.push(head);
        while (!queue.empty())
        {
            head = queue.front();
            queue.pop();
            if (head->left)
            {
                ans.push(to_string(head->left->val));
                queue.push(head->left);
            }
            else
            {
                ans.push(NULL);
            }
            if (head->right)
            {
                ans.push(to_string(head->right->val));
                queue.push(head->right);
            }
            else
            {
                ans.push(NULL);
            }
        }
    }
    return ans;
}

// 二叉树层序反序列化

TreeNode *generateNode(string val)
{
    if (val.empty())
    {
        return NULL;
    }
    return new TreeNode(stoi(val));
}

TreeNode *buildByLevelQueue(queue<string> levelList)
{
    if (levelList.empty())
    {
        return NULL;
    }

    TreeNode *head = generateNode(levelList.front());
    levelList.pop();
    queue<TreeNode *> queue;
    if (!head)
    {
        queue.push(head);
    }
    TreeNode *node;
    while (!queue.empty())
    {
        node = queue.front();
        queue.pop();
        node->left = generateNode(levelList.front());
        levelList.pop();
        node->right = generateNode(levelList.front());
        levelList.pop();
        if (node->left)
        {
            queue.push(node->left);
        }
        if (node->right)
        {
            queue.push(node->right);
        }
    }
    return head;
}

// 给定一棵二叉树的头结点head，任何两个节点之间都存在距离，返回整棵二叉树的最大距离
class Info3
{
public:
    int maxDistance;
    int height;

    Info3(int m, int h) : maxDistance(m), height(h){};
};

Info3 *process3(TreeNode *x)
{
    if (!x)
    {
        return new Info3(0, 0);
    }

    Info3 *leftInfo = process3(x->left);
    Info3 *rightInfo = process3(x->right);
    int height = max(leftInfo->height, rightInfo->height) + 1;

    int p1 = leftInfo->maxDistance;
    int p2 = rightInfo->maxDistance;
    int p3 = leftInfo->height + rightInfo->height + 1;
    int maxDistance = max(max(p1, p2), p3);
    return new Info3(maxDistance, height);
}

int maxDistance(TreeNode *head)
{
    return process3(head)->maxDistance;
}

// 判断一棵树是不是满二叉树

class Info4
{
public:
    int height;
    int nodes;

    Info4(int h, int n) : height(h), nodes(n){};
};

Info4 *process4(TreeNode *head)
{
    if (!head)
    {
        return new Info4(0, 0);
    }

    Info4 *leftInfo = process4(head->left);
    Info4 *rightInfo = process4(head->right);
    int height = max(leftInfo->height, rightInfo->height) + 1;
    int nodes = leftInfo->nodes + rightInfo->nodes + 1;
    return new Info4(height, nodes);
}

bool isFull(TreeNode *head)
{
    if (!head)
    {
        return true;
    }
    Info4 *all = process4(head);
    return (1 << all->height) - 1 == all->nodes;
}

// 寻找最大二叉搜索树节点个数

class Info5
{
public:
    int maxBSTSubtreeSize;
    int allSize;
    int max;
    int min;

    Info5(int ms, int as, int max, int min) : maxBSTSubtreeSize(ms), allSize(as), max(max), min(min){};
};

Info5 *process5(TreeNode *x)
{
    if (!x)
    {
        return NULL;
    }

    Info5 *leftInfo = process5(x->left);
    Info5 *rightInfo = process5(x->right);
    int maxVal = x->val;
    int minVal = x->val;
    int allSize = 1;
    if (leftInfo)
    {
        maxVal = max(leftInfo->max, maxVal);
        minVal = min(leftInfo->min, minVal);
        allSize += leftInfo->allSize;
    }

    if (rightInfo)
    {
        maxVal = max(rightInfo->max, maxVal);
        minVal = min(rightInfo->min, minVal);
        allSize += rightInfo->allSize;
    }

    int p1 = -1;
    if (leftInfo)
    {
        p1 = leftInfo->maxBSTSubtreeSize;
    }

    int p2 = -1;
    if (rightInfo)
    {
        p2 = rightInfo->maxBSTSubtreeSize;
    }

    int p3 = -1;
    bool leftBST = leftInfo == NULL ? true : (leftInfo->maxBSTSubtreeSize == leftInfo->allSize);
    bool rightBST = rightInfo == NULL ? true : (rightInfo->maxBSTSubtreeSize == rightInfo->allSize);
    if (leftBST && rightBST)
    {
        bool leftMaxLessX = leftInfo == NULL ? true : (leftInfo->max < x->val);
        bool rightMinMoreX = rightInfo == NULL ? true : (rightInfo->min > x->val);
        if (leftMaxLessX && rightMinMoreX)
        {
            int leftSize = leftInfo == NULL ? 0 : leftInfo->allSize;
            int rightSize = rightInfo == NULL ? 0 : rightInfo->allSize;
            p3 = leftSize + rightSize + 1;
        }
    }

    int maxBSTSubtreeSize = max(max(p1, p2), p3);

    return new Info5(maxBSTSubtreeSize, allSize, maxVal, minVal);
}

int maxSubBSTSize(TreeNode *head)
{
    if (!head)
    {
        return 0;
    }

    return process5(head)->maxBSTSubtreeSize;
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



/*
二叉树的递归套路
1）假设以X节点为头，假设可以向X左树和X右树要任何信息
2）在上一步的假设下，讨论以x为头节点的树，得到答案的可能性（最重要）
3）列出所有可能性后，确定到底需要向左树和右树要什么样的信息
4）把左树信息和右树信息求全集，就是任何一棵子树都需要返回的信息S
5）递归函数都返回S，每一棵子树都这么要求
6）写代码，在代码中考虑如何把左树的信息和右树的信心整合出整棵树的信息
*/