#include "ShortestPath.h"

ShortestPath::ShortestPath(const Graph& g)
	: graph(g), pq(g)
{
	dist.assign(graph.m_V, std::numeric_limits<double>::infinity());
	prev.assign(graph.m_V, -1);
}

void ShortestPath::Dijklstra(int start)
{
	dist[start] = 0;
	pq.insert({ 0.0,start});

	while (pq.size() > 0)
	{
		auto top = pq.top(); // select vertice with lowest value,initially its start point
		pq.minPriority();   // pops the lowest value

		double d = top.first;
		int u = top.second;
		
		if (d > dist[u]) continue;

		for (int v : graph.m_AdjList[u])
		{
			double weight = dist[u] + graph.getWeight(u, v);

			if (dist[v] >  weight) {
				dist[v] =  weight;
				prev[v] = u;
				pq.insert({ dist[v], v });
			}
		}
	}
	std::cout << "Shortest distances from vertex " << start << ":\n";
	for (int i = 0; i < graph.m_V; ++i) {
		std::cout << "Vertex " << i << ": " << dist[i] << "\n";
	}
}

std::vector<int> ShortestPath::getPath(int targetNode) const
{
	std::vector<int> path;
	if (dist[targetNode] == std::numeric_limits<double>::infinity())
	{
		// Target node is unreachable, return an empty path or a special marker
		return path; // Empty path
	}

	for (int at = targetNode; at != -1; at = prev[at])
	{
		path.push_back(at);
	}
	std::reverse(path.begin(), path.end());
	return path;
}
