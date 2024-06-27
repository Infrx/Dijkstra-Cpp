#include "Graph.h"


int main() 
{
	double distRange[2] = { 1.0, 10.0 };
	int V = 50;
	double dens = 0.20;
	Graph graph( V, dens, distRange);
	graph.addAllEdges();

	for (int i = 0; i < 50; i++) // Adjaceny List
	{
		std::cout << "\n ";
		std::cout << "Vertex " << i << "->";
		for (int x:graph.m_AdjList[i])
		{
			std::cout << x << " ";
		}
	}
	for (const auto& edge : graph.m_Weights) // Weight map
		std::cout << "(" << edge.first.first << ", " << edge.first.second << ") -> " << edge.second << "\n";

}