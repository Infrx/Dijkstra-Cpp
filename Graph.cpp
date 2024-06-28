#include "Graph.h"

Graph::Graph()
	: m_V(50), m_Density(20), m_AdjList(50)
{
	m_DistRange = new double[2];
	m_DistRange[0] = 1.0;
	m_DistRange[1] = 10.0;
	std::vector<int> m_Vector;
	randEngine = std::default_random_engine(static_cast<unsigned long>(std::time(nullptr)));
	randDensity = std::uniform_int_distribution<unsigned int>(0, 100);
	randDistance = std::uniform_real_distribution<double>(m_DistRange[0], m_DistRange[1]);
}

Graph::Graph(int& V, double& density, double* distRange)
	: m_V(V), m_Density(density), m_AdjList(V)
{
	m_DistRange = new double[2];
	m_DistRange[0] = distRange[0];
	m_DistRange[1] = distRange[1];

	randEngine = std::default_random_engine(static_cast<unsigned long>(std::time(nullptr)));
	randDensity = std::uniform_int_distribution<unsigned int>(0, 100);
	randDistance = std::uniform_real_distribution<double>(m_DistRange[0], m_DistRange[1]);
}

Graph::~Graph()
{
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

double Graph::getWeight(int u, int v) const
{
	std::pair<int, int> key = { u, v };
	auto it = m_Weights.find(key);
	if (it != m_Weights.end()) {
		return it->second;  // Return the weight if found
	}
	else {
		// Return a default value or handle the case where the edge is not found
		std::cerr << "Edge (" << key.first << ", " << key.second << ") not found." << std::endl;
		return std::numeric_limits<double>::infinity();  //
	}
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

void Graph::printAdjList()
{
	for (int i = 0; i < m_V; ++i) {
		std::cout << "Vertex " << i << " -> ";
		for (auto it = m_AdjList[i].begin(); it != m_AdjList[i].end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << "\n";
	}
}
