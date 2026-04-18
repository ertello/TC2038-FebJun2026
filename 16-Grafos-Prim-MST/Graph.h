#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>

#define INF 0x3f3f3f3f

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
    std::pair<int, std::vector<std::pair<std::pair<int, int>, int>>> primMST(int startNode);
};

#endif // _GRAPH_H_
