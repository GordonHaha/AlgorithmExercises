// https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84

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
    void Serialize(TreeNode *root, string &str)
    {
        if (!root)
        {
            // 遇到NULL拼上#
            str += "#";
            return;
        }

        str += to_string(root->val);
        //用逗号分割节点
        str += ",";
        Serialize(root->left, str);
        Serialize(root->right, str);
    }

    char *Serialize(TreeNode *root)
    {
        if (!root)
            return NULL;
        string str = "";
        Serialize(root, str);
        char *res = new char[str.length()];
        strcpy(res, str.c_str());
        return res;
    }

    TreeNode *deserialize(char **str)
    {
        if (**str == '#')
        {
            // 遇到#返回空指针，指针往后移动一位
            ++(*str);
            return NULL;
        }

        int num = 0;
        while (**str != ',')
        {
            // 循环转换个位数字，拼接完整数值，直到遇到逗号分隔符
            num = num * 10 + (**str - '0');
            ++(*str);
        }
        // 拼接完后再移动一位跳过逗号
        ++(*str);
        TreeNode *root = new TreeNode(num);
        root->left = deserialize(str);
        root->right = deserialize(str);
        return root;
    }

    TreeNode *Deserialize(char *str)
    {
        if (!str)
            return NULL;
        return deserialize(&str);
    }
};