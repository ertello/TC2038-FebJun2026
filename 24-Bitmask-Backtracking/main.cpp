/**
 * Resuelve el problema de la suma de subonjuntos
 * utilizando backtracking con bitmasking
 * Nota: funciona solo con conjuntos maximo
 * de 8 elementos (unsigned char - 1 byte)
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -Wall -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < TestCases/test01.txt
 **/
#include <iostream>
#include <set>
#include <vector>

unsigned char add(unsigned char mask, int pos) { 
  return (mask | (1 << pos)); 
}

unsigned char remove(unsigned char mask, int pos) {
  return (mask & (~(1 << pos)));
}

bool test(unsigned char mask, int pos) { 
  return ((mask & (1 << pos)) != 0); 
}

void printSolution(const std::vector<int> &S, unsigned char mask) {
  std::cout << "{";
  for (int i = 0; i < (int)S.size(); i++) {
    if (test(mask, i)) {
      std::cout << S[i] << " ";
    }
  }
  std::cout << "}" << std::endl;
}

void subset(const std::vector<int> &A, unsigned char mask, int acum, int target, int level) {
  if (acum > target) {
    return;
  }
  if (acum == target) {
    printSolution(A, mask);
    return;
  }
  if (level < (int)A.size()) {
    subset(A, mask, acum, target, level + 1);
    mask = add(mask, level);
    subset(A, mask, acum + A[level], target, level + 1);
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> A;
  unsigned char mask = 0;
  int n, aux, target;
  std::cin >> n >> target;
  std::cout << "Target sum " << target << std::endl;
  for (int i = 0; i < n; i++) {
    std::cin >> aux;
    A.push_back(aux);
  }
  subset(A, mask, 0, target, 0);
  return 0;
}