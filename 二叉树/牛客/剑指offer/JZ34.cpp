// https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca
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
    vector<vector<int>> res;
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        if (!root)
            return res;
        vector<int> track;
        process(root, expectNumber, track);
        return res;
    }

    void process(TreeNode *root, int expectNumber, vector<int> &track)
    {
        if (!root)
        {
            return;
        };

        track.push_back(root->val);
        if (!root->left && !root->right && expectNumber == root->val)
        {
            res.push_back(track);
        }

        process(root->left, expectNumber - root->val, track);
        process(root->right, expectNumber - root->val, track);
        track.pop_back();
    }
};