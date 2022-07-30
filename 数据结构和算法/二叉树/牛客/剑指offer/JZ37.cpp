// https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84
#include<bits/stdc++.h>
using namespace std;

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution
{
public:
    // 通过前序遍历序列化
    void SerializeFunc(TreeNode *root, string &str)
    {
        if (!root)
        {
            str += '#';
            return;
        }

        str += to_string(root->val) + ',';

        SerializeFunc(root->left, str);
        SerializeFunc(root->right, str);
    }

    char *Serialize(TreeNode *root)
    {
        if (!root)
            return "#";
        string str;
        SerializeFunc(root, str);
        char *res = new char[str.length()];
        strcpy(res, str.c_str());
        return res;
    }

    TreeNode *DeserializeFunc(char **str)
    {

        if (**str == '#')
        {
            (*str)++;
            return NULL;
        }

        int num = 0;
        while (isdigit(**str))
        {
            num = num * 10 + (**str - '0');
            (*str)++;
        }
        (*str)++;

        TreeNode *root = new TreeNode(num);
        root->left = DeserializeFunc(str);
        root->right = DeserializeFunc(str);
        return root;
    }

    TreeNode *Deserialize(char *str)
    {
        if (!str)
            return NULL;
        return DeserializeFunc(&str);
    }
};