#pragma once
#include "Graph.h"
#include "PriorityQueue.h"
#include <vector>


class Graph;

class ShortestPath
{
private:
    const Graph& graph;
    PriorityQueue pq;
    std::vector<double> dist;
    std::vector<int> prev;
public:
    ShortestPath(const Graph& g);
    void Dijklstra(int start);
    std::vector<int> getPath(int targetNode) const;

};