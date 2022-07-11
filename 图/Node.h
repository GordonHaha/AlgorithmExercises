#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
#include "Edge.h"

using namespace std;

// 点
class Node
{
public:
    int value;            // 点的值
    int in;               // 入度 多少个点指向自己
    int out;              // 出度 指向多少个点
    vector<Node *> nexts; // 由自己直接指向（发散）的点集
    vector<Edge *> edges; // 由自己直接指向（发散）的边集
    Node()
    {
        value = 0;
        in = 0;
        out = 0;
    };

    Node(int v) : value(v){};

    Node(int v, int i, int o) : value(v), in(i), out(o){};
};

#endif