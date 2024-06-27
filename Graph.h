#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <random>
#include <map>

class Graph
{
private:
	int m_V;
	double m_Density;
	double* m_DistRange;
	
	// Random number generation
	std::default_random_engine randEngine;
	std::uniform_int_distribution<unsigned int> randDensity;
	std::uniform_real_distribution<double> randDistance;
public:
	Graph(); // default values
	Graph(int& V, double& density, double* distRange);
	~Graph();
	std::list<int>* m_AdjList;
	std::map<std::pair<int, int>, double> m_Weights;
	void addAllEdges();
private:
	void addEdge(int x, int y);  // Adds single edge , needs to be iterated
	void setEdgeValue(int x, int y, double weight);
	
};