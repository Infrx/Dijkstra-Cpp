#include "Graph.h"


int main() 
{
	double distRange[2] = { 1.0, 10.0 };
	int V = 50;
	double dens = 1.0;
	Graph graph( V, dens, distRange);
	graph.addAllEdges();
	for (int i = 0; i < 50; i++) 
	{
		std::cout << "\n ";
		std::cout << "Vertex " << i << "->";
		for (int x:graph.m_AdjList[i])
		{
			std::cout << x << " ";
		}
	}
	
}