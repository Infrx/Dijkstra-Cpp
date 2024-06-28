#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(const Graph& graphRef)
	: graphIns(graphRef)
{

}

void PriorityQueue::minPriority()
{
	pq.pop();
}

void PriorityQueue::insert(pair element)
{
	pq.push(element);
}

pair PriorityQueue::top()
{
	return pq.top();
}

int PriorityQueue::size()
{
	return pq.size();
}

