#include <bits/stdc++.h>
using namespace std;
/*
贪心策略在实现时，经常使用到的技巧：
1）根据某标准建立一个比较器来排序
2）根据某标准建立一个比较器来组成堆
*/

/*
会议室问题
一些项目要占用一个会议室宣讲，会议室不能同时容纳两个项目的宣讲。给你每一个项目开始的时间和结束的时间（给你一个数组，里面是一个个具体的项目），你来安排宣讲的日程，要求会议室进行的宣讲的场次最多。
返回这个最多的宣讲场次
*/

class Program
{
public:
    int start;
    int end;

    Program(int s, int e) : start(s), end(e){};
};

struct ProgramCmp
{
    bool operator()(const Program *o1, const Program *o2)
    {
        return o1->end < o2->end;
    }
};

int bestArrange(vector<Program *> &programs, int timePoint)
{
    sort(programs.begin(), programs.end(), ProgramCmp());
    int result = 0;
    // 从左往右依次遍历所有会议
    for (int i = 0; i < programs.size(); i++)
    {
        if (timePoint <= programs[i]->start)
        {
            result++;
            timePoint = programs[i]->end;
        }
    }
    return result;
}

/*
一块金条切成两半，是需要花费和长度数值一样的铜板的。比如长度为20的金条，不管切成长度多大的两半，都要花费20个铜板。
一群人想整分整块金条，怎么分最省铜板？
例如，给定数组{10,20,30}，代表一共三个人，整块金条长度为10+20+30=60.
金条要分成10,20,30三个部分。如果先把长度60的金条分成10和50，花费60；再把长度50的金条分成20和30，花费50；一共花费110铜板。
但是如果先把长度60的金条分成30和30，花费60；再把长度30金条分成10和20，花费30；一共花费90铜板。
输入一个数组，返回分割的最小代价。
*/

int lessMoney(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> pQ;
    for (int i = 0; i < arr.size(); i++)
    {
        pQ.push(arr[i]);
    }
    int sum = 0;
    int cur = 0;
    while (pQ.size() > 1)
    {
        cur = pQ.top();
        pQ.pop();
        cur += pQ.top();
        pQ.pop();
        sum += cur;
        pQ.push(cur);
    }
    return sum;
}

/*
输入：
正数数组costs
正数数组profits
正数k
正数m
含义：
costs[i]表示i号项目的花费
profits[i]表示i号项目在扣除花费之后还能挣到的钱（利润）
k表示你只能串行的最多做k个项目
m表示你初始的资金
说明：
你每做完一个项目，马上获得的收益，可以支持你去做下一个项目。
输出：
你最后获得的最大钱数。
*/

class Node
{
public:
    int profit;
    int cost;
    Node(int p, int c) : profit(p), cost(c){};
};

struct MinCostCmp
{
    bool operator()(Node *o1, Node *o2)
    {
        return o1->cost < o2->cost;
    }
};

struct MaxProfitCmp
{
    bool operator()(Node *o1, Node *o2)
    {
        return o1->profit > o2->profit;
    }
};

int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital)
{
    priority_queue<Node *, vector<Node *>, MinCostCmp> minCostQ;
    priority_queue<Node *, vector<Node *>, MaxProfitCmp> maxProfitQ;
    // 所有项目扔到被锁池中，花费组织的小根堆
    for (int i = 0; i < Profits.size(); i++)
    {
        minCostQ.push(new Node(Profits[i], Capital[i]));
    }

    for (int i = 0; i < k; i++) // 进行k轮
    {
        // 能力所及的项目，全解锁
        while (!minCostQ.empty() && minCostQ.top()->cost <= W)
        {
            maxProfitQ.push(minCostQ.top());
            minCostQ.pop();
        }
        if (maxProfitQ.empty())
        {
            return W;
        }
        W += maxProfitQ.top()->profit;
        maxProfitQ.pop();
    }
    return W;
}





int main()
{
    return 0;
}