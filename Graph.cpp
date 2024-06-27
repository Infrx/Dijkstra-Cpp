#include "Graph.h"

Graph::Graph()
	: m_V(50), m_Density(20)
{
	m_AdjList = new std::list<int>[m_V];
	m_DistRange = new double[2];
	m_DistRange[0] = 1.0;
	m_DistRange[1] = 10.0;

	randEngine = std::default_random_engine(static_cast<unsigned long>(std::time(nullptr)));
	randDensity = std::uniform_int_distribution<unsigned int>(0, 100);
	randDistance = std::uniform_real_distribution<double>(m_DistRange[0], m_DistRange[1]);
}

Graph::Graph(int& V, double& density, double* distRange)
	: m_V(V), m_Density(density)
{
	m_AdjList = new std::list<int>[m_V];
	m_DistRange = new double[2];
	m_DistRange[0] = distRange[0];
	m_DistRange[1] = distRange[1];

	randEngine = std::default_random_engine(static_cast<unsigned long>(std::time(nullptr)));
	randDensity = std::uniform_int_distribution<unsigned int>(0, 100);
	randDistance = std::uniform_real_distribution<double>(m_DistRange[0], m_DistRange[1]);
}

Graph::~Graph()
{
	delete[] m_AdjList;
	delete[] m_DistRange;
}

void Graph::addEdge(int x, int y)
{
	// for undirected graph
	m_AdjList[x].push_back(y);
	m_AdjList[y].push_back(x);
}

void Graph::setEdgeValue(int x, int y, double weight)
{
	// Store the weight for the edge (x, y)
	m_Weights[std::make_pair(x, y)] = weight;
	m_Weights[std::make_pair(y, x)] = weight; // For undirected graph, store both directions
}

void Graph::addAllEdges()
{
	for (int i = 0; i < m_V; ++i)
	{
		for (int j = i + 1; j < m_V; ++j) 
		{
			double rand = randDensity(randEngine);
			if (rand <= m_Density * 100)
			{
				addEdge(i, j);
				double weight = randDistance(randEngine);
				setEdgeValue(i, j, weight);
			}
				
		}
	}
}
