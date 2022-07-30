#include <bits/stdc++.h>

using namespace std;

/*
最大线段重合问题（用堆的实现）

给定很多线段，每个线段都有两个数组[start, end]，表示线段开始位置和结束位置，左右都是闭区间
规定：
1）线段的开始和结束位置一定都是整数值
2）线段重合区域的长度必须 >= 1
返回线段最多重合区域中，包含了几条线段
*/

class Line
{
public:
    int start;
    int end;
    Line(int s, int e) : start(s), end(e){};
};

bool startCmp(const Line *l1, const Line *l2)
{
    return l1->start < l2->start;
}

int maxCover(vector<vector<int> > &m)
{
    vector<Line *> lines;

    for (int i = 0; i < m.size(); i++)
    {
        lines.push_back(new Line(m[i][0], m[i][1]));
    }
    // 按线段起点升序排序
    sort(lines.begin(), lines.end(), startCmp);

    // 创建小根堆
    priority_queue<int, vector<int>, greater<int> > heap;

    int maxCount = 0;
    for (int i = 0; i < lines.size(); i++)
    {
        while (!heap.empty() && heap.top() <= lines[i]->start)
        {
            heap.pop();
        }
        heap.push(lines[i]->end);
        maxCount = max(maxCount, (int)heap.size());
    }
    return maxCount;
}

int main() {
    return 0;
}