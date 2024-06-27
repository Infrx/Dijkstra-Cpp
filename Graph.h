#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <random>

class Graph
{
private:
	int m_V;
	double m_Density;
	double* m_DistRange;
	
	// Random number generation
	std::default_random_engine randEngine;
	std::uniform_int_distribution<unsigned int> randDensity;
	std::uniform_int_distribution<unsigned int> randDistance;
public:
	Graph(); // default values
	Graph(int& V, double& density, double* distRange);
	~Graph();
	std::list<int>* m_AdjList;
	void addAllEdges();
private:
	void addEdge(int x, int y);  // Adds single edge , needs to be iterated
	
};