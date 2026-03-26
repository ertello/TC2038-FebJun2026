#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>


class Graph {
  private:
    int numNodes;
    int numEdges;
    // Lista de adyacencia
    // vector de listas ligadas de pares (vertice, peso)
    std::vector<std::list<std::pair<int, int>>> adjList;
  
    void split(std::string line, std::vector<int> &res);
  
  public:
    Graph();
    ~Graph();
    void readGraph(std::istream &input);
    void print();
    void DFS(int v);
    void BFS(int v);
};

#endif // _GRAPH_H_
