#include <bits/stdc++.h>
#include "Node.h"
#include "Edge.h"

using namespace std;

class Graph
{
public:
    unordered_map<int, Node *> nodes;
    unordered_set<Edge *> edges;
};

// 举例一个转化接口,将二维数组表示的图转化成上述类结构
Graph *createGraph(vector<vector<int>> &matrix)
{
    Graph *graph = new Graph();
    for (int i = 0; i < matrix.size(); i++)
    {
        int from = matrix[i][0];
        int to = matrix[i][1];
        int weight = matrix[i][2];

        if (graph->nodes.find(from) == graph->nodes.end())
        {
            graph->nodes[from] = new Node(from);
        }
        if (graph->nodes.find(to) == graph->nodes.end())
        {
            graph->nodes[to] = new Node(to);
        }

        Node *fromNode = graph->nodes[from];
        Node *toNode = graph->nodes[to];
        Edge *newEdge = new Edge(weight, fromNode, toNode);
        fromNode->nexts.push_back(toNode);
        fromNode->out++;
        toNode->in++;
        fromNode->edges.push_back(newEdge);
        graph->edges.insert(newEdge);
    }
    return graph;
}

/*
图的宽度优先遍历
1）利用队列实现
2）从源节点开始依次按照宽度进队列，然后弹出
3）每弹出一个点，把该节点所有没有进过队列的邻接点放入队列
4）直到队列变空

图的深度优先遍历
1）利用栈实现
2）从源节点开始把节点按照深度放入栈，然后弹出
3）每弹出一个点，把该节点下一个没有进过栈的邻接点放入栈
4）直到栈变空
*/

// 从node出发，进行宽度优先遍历
void bfs(Node *node)
{
    if (!node)
    {
        return;
    }

    queue<Node *> queue;
    unordered_set<Node *> set;
    queue.push(node);
    set.insert(node);

    while (!queue.empty())
    {
        Node *cur = queue.front();
        queue.pop();
        cout << cur->value << endl;
        for (Node *next : cur->nexts)
        {
            if (set.find(next) == set.end())
            {
                set.insert(next);
                queue.push(next);
            }
        }
    }
}

// 从node出发，进行深度优先遍历
void dfs(Node *node)
{
    if (!node)
    {
        return;
    }

    stack<Node *> stack;
    unordered_set<Node *> set;
    stack.push(node);
    set.insert(node);
    cout << node->value << endl;
    while (!stack.empty())
    {
        Node *cur = stack.top();
        stack.pop();
        for (Node *next : cur->nexts)
        {
            if (set.find(next) == set.end())
            {
                stack.push(cur);
                stack.push(next);
                set.insert(next);
                cout << next->value << endl;
                break;
            }
        }
    }
}

// 拓扑排序算法 适用范围：要求有向图，且有入度为0的节点，且没有环

vector<Node *> sortedTopology(Graph *graph)
{
    // key:某一个node
    // value:剩余的入度
    unordered_map<Node *, int> inMap;
    // 入度为0的点，才能进这个队列
    queue<Node *> zeroInQueue;
    for (auto iter : graph->nodes)
    {
        Node *node = iter.second;
        inMap[node] = node->in;
        if (node->in == 0)
        {
            zeroInQueue.push(node);
        }
    }

    // 拓扑排序的结果，依次加入result
    vector<Node *> result;
    while (!zeroInQueue.empty())
    {
        Node *cur = zeroInQueue.front();
        zeroInQueue.pop();
        for (Node *next : cur->nexts)
        {
            inMap[next] = inMap[next] - 1;
            if (inMap[next] == 0)
            {
                zeroInQueue.push(next);
            }
        }
    }
    return result;
}

// kruskal算法
// 适用范围：要求无向图
// 使用并查集

class UnionFind
{
public:
    unordered_map<Node *, vector<Node *>> setMap;
    UnionFind(vector<Node *> nodes)
    {
        for (Node *cur : nodes)
        {
            vector<Node *> set;
            set.push_back(cur);
            setMap[cur] = set;
        }
    };

    bool isSameSet(Node *from, Node *to)
    {
        vector<Node *> fromSet = setMap[from];
        vector<Node *> toSet = setMap[to];
        return fromSet == toSet;
    };

    void unionSet(Node *from, Node *to)
    {
        vector<Node *> fromSet = setMap[from];
        vector<Node *> toSet = setMap[to];
        for (Node *toNode : toSet)
        {
            fromSet.push_back(toNode);
            setMap[toNode] = fromSet;
        }
    };
};

struct EdgeCmp
{
    bool operator()(Edge *o1, Edge *o2)
    {
        return o1->weight < o2->weight;
    }
};

unordered_set<Edge *> kruskalMST(Graph *graph)
{
    vector<Node *> nodes;
    for (pair<int, Node *> pair : graph->nodes)
    {
        nodes.push_back(pair.second);
    }
    UnionFind *unionFind = new UnionFind(nodes);
    priority_queue<Edge *, vector<Edge *>, EdgeCmp> priorityQueue;
    for (Edge *edge : graph->edges)
    {
        priorityQueue.push(edge);
    }

    unordered_set<Edge *> result;
    while (!priorityQueue.empty())
    {
        Edge *edge = priorityQueue.top();
        priorityQueue.pop();
        if (!unionFind->isSameSet(edge->from, edge->to))
        {
            result.insert(edge);
            unionFind->unionSet(edge->from, edge->to);
        }
    }
    return result;
}

// prim算法
// 适用范围：要求无向图
// 使用哈希表

unordered_set<Edge *> primMST(Graph *graph)
{
    // 解锁的边进入小根堆
    priority_queue<Edge *, vector<Edge *>, EdgeCmp> priorityQueue;
    unordered_set<Node *> set;
    unordered_set<Edge *> result; // 依次挑选的边放在result里

    for (pair<int, Node *> pair : graph->nodes)
    {
        // 随便挑一个点
        Node *node = pair.second;
        if (set.find(node) == set.end())
        {
            set.insert(node);
            for (Edge *edge : node->edges)
            { // 由一个点，解锁所有相连的边
                priorityQueue.push(edge);
            }
            while (!priorityQueue.empty())
            {
                Edge *edge = priorityQueue.top(); // 弹出解锁的边中最小的边
                priorityQueue.pop();
                Node *toNode = edge->to; // 可能的一个新的点
                if (set.find(toNode) == set.end())
                { // 不含有的时候，就是新的点
                    set.insert(toNode);
                    result.insert(edge);
                    for (Edge *nextEdge : toNode->edges)
                    {
                        priorityQueue.push(nextEdge);
                    }
                }
            }
        }
    }
    return result;
}

// Dijkstra算法
// 适用范围：没有权值累加和为负数的环

Node *getMinDistanceAndUnselectedNode(unordered_map<Node *, int> &distanceMap, unordered_set<Node *> &touchedNodes)
{
    Node *minNode = NULL;
    int minDistance = INT_MAX;
    for (pair<Node *, int> pair : distanceMap)
    {
        Node *node = pair.first;
        int distance = pair.second;
        if (touchedNodes.find(node) == touchedNodes.end() && distance < minDistance)
        {
            minNode = node;
            minDistance = distance;
        }
    }
    return minNode;
}

unordered_map<Node *, int> dijkstra(Node *head)
{
    // 从head出发到所有点最小距离
    // key：从head出发到达key
    // value：从head出发到达key的最小距离
    // 如果在表中，没有T的记录，含义是从head出发到T这个点的距离为正无穷
    unordered_map<Node *, int> distanceMap;
    distanceMap.emplace(head, 0);
    // 已经求过距离的节点，存在selectedNodes中，以后再也不碰
    unordered_set<Node *> selectedNodes;
    Node *minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
    while (!minNode)
    {
        int distance = distanceMap[minNode];
        for (Edge *edge : minNode->edges)
        {
            Node *toNode = edge->to;
            if (distanceMap.find(toNode) == distanceMap.end())
            {
                distanceMap.emplace(toNode, distance + edge->weight);
            }
            distanceMap.emplace(edge->to, min(distanceMap[toNode], distance + edge->weight));
        }
        selectedNodes.insert(minNode);
        minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
    }
    return distanceMap;
}

// 改写堆实现Dijkstra算法

class NodeRecord
{
public:
    Node *node;
    int distance;

    NodeRecord(Node *node, int distance) : node(node), distance(distance){};
};

class NodeHeap
{
public:
    vector<Node *> nodes;
    unordered_map<Node *, int> heapIndexMap;
    unordered_map<Node *, int> distanceMap;
    int size;

    NodeHeap(int size)
    {

        nodes.resize(size);
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isEntered(Node *node)
    {
        return heapIndexMap.find(node) != heapIndexMap.end();
    }

    bool inHeap(Node *node)
    {
        return isEntered(node) && heapIndexMap[node] != -1;
    }

    void swap(int index1, int index2)
    {
        heapIndexMap.emplace(nodes[index1], index2);
        heapIndexMap.emplace(nodes[index2], index1);
        Node tmp = nodes[index1];
        nodes[index1] = nodes[index2];
        nodes[index2] = tmp;
    }

    void insertHeapify(Node *node, int index)
    {
        while (distanceMap[nodes[index]] < distanceMap[nodes[(index - 1) / 2]])
        {
            swap(index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }

    void heapify(int index, int size)
    {
        int left = index * 2 + 1;
        while (left < size)
        {
            int smallest = left + 1 < size && distanceMap[nodes[left + 1]] < distanceMap[nodes[left]] ? left + 1 : left;
            smallest = distanceMap[nodes[smallest]] < distanceMap[nodes[index]] ? smallest : index;
            if (smallest == index)
            {
                break;
            }
            swap(smallest, index);
            index = smallest;
            left = index * 2 + 1;
        }
    }

    NodeRecord * pop() {
        NodeRecord *nodeRecord = new NodeRecord(nodes[0], distanceMap[nodes[0]]);
        swap(0, size - 1);
        heapIndexMap.emplace(nodes[size - 1], -1);
        distanceMap.erase(nodes[size - 1]);
        nodes[size - 1] = NULL;
        heapify(0, --size);
        return nodeRecord;
    }

    void addOrUpdateOrOgnore(Node *node, int distance)
    {
        if (inHeap(node))
        {
            distanceMap.emplace(node, min(distanceMap[node], distance));
            insertHeapify(node, heapIndexMap[node]);
        }
        if (!isEntered(node))
        {
            nodes[size] = node;
            heapIndexMap.emplace(node, size);
            distanceMap.emplace(node, distance);
            insertHeapify(node, size++);
        }
    }
};

// 改进后的dijkstra算法
// 从head出发，所有head能到达的节点，生成到达每个节点的最小路径记录并返回
unordered_map<Node*, int> dijkstra2(Node* head, int size) {
    NodeHeap nodeHeap = new NodeHeap(size);
    nodeHeap.addOrUpdateOrOgnore(head, 0);
    unordered_map<Node *, int> result;
    while (!nodeHeap.isEmpty())
    {
        NodeRecord *record = nodeHeap.pop();
        Node *cur = record->node;
        int distance = record->distance;
        for(Edge *edge : cur->edges) {
            nodeHeap.addOrUpdateOrOgnore(edge->to, edge->weight + distance);
        }
        result.emplace(cur.distance);
    }
    return result;
}

int main()
{
    return 0;
}