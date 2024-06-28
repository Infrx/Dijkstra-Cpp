#pragma once
#include <queue>
class Graph;

typedef std::pair<double, int> pair;

class PriorityQueue
{
private:
	const Graph& graphIns;
	std::priority_queue<pair, std::vector<pair>, std::greater<pair>> pq;
public:
	PriorityQueue(const Graph& graphRef);
	void minPriority();
	void insert(pair element);
	pair top();
	int size();
};