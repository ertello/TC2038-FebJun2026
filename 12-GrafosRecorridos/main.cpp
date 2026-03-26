/**
 * Ejemplo que implementa Grafos dirigidos ponderados con una
 * Lista de adyacencia y los algoritmos DFS y BFS
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    valgrind --leak-check=full ./main < TestCases/test01.txt
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < TestCases/test01.txt
 **/

#include "Graph.h"
#include <iostream>
#include <sstream>

int main() {
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf();

  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia+
  Graph g1;
  g1.readGraph(inputInfo);
  g1.print();
  g1.DFS(0);
  g1.BFS(0);
  return 0;
}
