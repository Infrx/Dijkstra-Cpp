#include "Graph.h"
#include "PriorityQueue.h"
#include "ShortestPath.h"



template <typename S>
std::ostream& operator<<(std::ostream& os,
	const std::vector<S>& vector)
{
	// Printing all the elements
	// using <<
	for (auto element : vector) {
		os << element << " ";
	}
	return os;
}



int main() 
{
	double distRange[2] = { 1.0, 10.0 };
	int V = 50;
	double dens = 0.06;
	Graph graph( V, dens, distRange);
	
	

	graph.addAllEdges();

	graph.printAdjList();

	/*
	for (const auto& edge : graph.m_Weights) // Weight map
		std::cout << "(" << edge.first.first << ", " << edge.first.second << ") -> " << edge.second << "\n";
	*/
	ShortestPath sp(graph);

	sp.Dijklstra(0);

	std::vector<int> a = sp.getPath(30);

	
	std::cout << a;
	
}