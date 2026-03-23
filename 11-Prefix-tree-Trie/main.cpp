/** 
* Ejemplo que implementa un Trie (Arbol de prefijos)
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main < TestCases/test01.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < TestCases/test01.txt
**/
#include <iostream>
#include "trie.h"

using namespace std;

int main() {
  trie T;
  int N = 0;
  int M = 0;
  string palabra = "";
  string prefix = "";

  // Insertar N palabras
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> palabra;
    T.insert(palabra);
  }  
  // Recorrido DFS

  // Buscar M palabras
  cin >> M;
  for(int i = 0; i < M; i++){
    cin >> palabra;
    cout << boolalpha << T.search(palabra) << endl;
  }
  cin >> prefix;
  // AutoComplete (prefix)

  // Imprimir el tamaño total en bytes del trie
  
  return 0;
}