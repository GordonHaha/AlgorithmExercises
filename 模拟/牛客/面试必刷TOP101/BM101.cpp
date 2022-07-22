// https://www.nowcoder.com/practice/93aacb4a887b46d897b00823f30bfea1
#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct Node
    {
        int key;
        int val;
        int fre;
        Node(int k, int v, int f) : key(k), val(v), fre(f){};
    };

    unordered_map<int, list<Node>::iterator> kmap; // key的哈希表
    unordered_map<int, list<Node>> fmap;           // 频率的哈希表
    int minFre = 0;                                // 当前最小频率次数
public:
    /**
     * lfu design
     * @param operators int整型vector<vector<>> ops
     * @param k int整型 the k
     * @return int整型vector
     */

    void set(int key, int val, int k)
    {
        if (k == 0)
            return;
        // 缓存中不存在时
        if (kmap.count(key) == 0)
        {
            // 如果缓存已满，需要先删除频率最低访问最早的元素
            if (kmap.size() == k)
            {
                // 取得最末尾的点然后删除
                auto it = fmap[minFre].back();
                kmap.erase(it.key);
                fmap[minFre].pop_back();
                // 当前频率空了时，需要整体删除掉
                if (fmap[minFre].size() == 0)
                {
                    fmap.erase(minFre);
                }
            }

            // 重新放入新的点，然后更新末尾点位置
            fmap[1].push_front(Node(key, val, 1));
            kmap[key] = fmap[1].begin();
            minFre = 1;
            return;
        }

        // 当缓存中存在时，先取出来
        auto tmp = kmap[key];
        int fre = tmp->fre;
        // 因为访问频率增加，需要在原来的频率链表中删除
        fmap[fre].erase(tmp);
        // 删完后如果空了，整个链表都要删掉
        if (fmap[fre].size() == 0)
        {
            fmap.erase(fre);
            // 更新下最小频率
            if (minFre == fre)
                minFre++;
        }

        fmap[fre + 1].push_front(Node(key, val, fre + 1));
        // 更新缓存值
        kmap[key] = fmap[fre + 1].begin();
    }

    int get(int key, int k)
    {
        if (k == 0)
            return -1;
        if (kmap.count(key) == 0)
            return -1;
        auto tmp = kmap[key];
        int val = tmp->val, fre = tmp->fre;
        // 先找到链表位置删除掉这个值
        fmap[fre].erase(tmp);
        // 链表空了就整体删掉
        if (fmap[fre].size() == 0)
        {
            fmap.erase(fre);
            if (minFre == fre)
                minFre++;
        }

        fmap[fre + 1].push_front(Node(key, val, fre + 1));
        // 更新缓存值
        kmap[key] = fmap[fre + 1].begin();
        return val;
    }

    vector<int> LFU(vector<vector<int>> &operators, int k)
    {
        vector<int> res;
        for (auto &it : operators)
        {
            if (it.size() == 2)
            {
                res.push_back(get(it[1], k));
            }
            else
            {
                set(it[1], it[2], k);
            }
        }
        return res;
    }
};