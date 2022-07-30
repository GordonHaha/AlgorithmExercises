#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    int pass;
    int end;
    TrieNode *nexts[26];
    TrieNode()
    {
        pass = 0;
        end = 0;
    }
};

class TrieTree
{
private:
    TrieNode *root;
public:
    TrieTree()
    {
        root = new TrieNode();
    }
    ~TrieTree(){
        delete root;
    }

    void insert(string word)
    {
        if (word.empty())
        {
            return;
        }

        TrieNode *node = root;
        node->pass++;
        int path = 0;
        for (int i = 0; i < word.length(); i++)
        {
            path = word[i] - 'a';
            if (node->nexts[path] == NULL)
            {
                node->nexts[path] = new TrieNode();
            }
            node = node->nexts[path];
            node->pass++;
        }
        node->end++;
    }

    // word这个单词之前加入过几次
    int search(string word)
    {
        if (word.empty())
        {
            return 0;
        }

        TrieNode *node = root;
        int index = 0;
        for (int i = 0; i < word.length(); i++)
        {
            index = word[i] - 'a';
            if (node->nexts[index] == NULL)
            {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->end;
    }

    // 所有加入的字符串中，有几个是以pre这个字符串作为前缀的
    int prefixNumber(string pre)
    {
        if (pre.empty())
        {
            return 0;
        }

        TrieNode *node = root;
        int index = 0;
        for (int i = 0; i < pre.length(); i++)
        {
            index = pre[i] - 'a';
            if (node->nexts[index] == NULL)
            {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->pass;
    }

    void deleteWord(string word)
    {
        if (search(word) != 0)
        {
            TrieNode *node = root;
            node->pass--;
            int path = 0;
            for (int i = 0; i < word.length(); i++)
            {
                path = word[i] - 'a';
                if (--node->nexts[path]->pass == 0)
                {
                    delete node->nexts[path];
                }
                node = node->nexts[path];
            }
            node->end--;
        }
    }
};

int main()
{
    return 0;
}