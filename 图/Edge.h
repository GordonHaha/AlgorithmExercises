#ifndef EDGE_H
#define EDGE_H

#include <bits/stdc++.h>
class Node;
using namespace std;

// 边
class Edge
{
public:
    int weight; // 权值
    Node *from; // 来源点
    Node *to;   // 目标点

    Edge()
    {
        weight = 0;
    };

    Edge(int w, Node *f, Node *t) : weight(w), from(f), to(t){};
};

#endif