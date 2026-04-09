/**
 * Ejemplo que implementa el algoritmo Welsh Powell 
 * para coloreo de grafos
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    valgrind ./main < TestCases/test01.txt
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < TestCases/test01.txt
 **/

#include <iostream>
#include <sstream>
#include "Graph.h"

int main() {
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf();

  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  Graph g1;
  g1.readGraph(inputInfo);
  //g1.print();
  
  g1.algoritmoWelshPowell();
  return 0;
}
