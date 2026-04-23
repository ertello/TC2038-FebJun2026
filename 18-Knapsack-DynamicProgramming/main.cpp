/**
 * Ejemplo que implementa programacion dinamica para 
 * resolver el problema de la mochila 0/1
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

#include <iostream>
#include <vector>
#include <utility>

int mochilaDP(const std::vector<std::pair<int, int>> &data, int n, int W) {
  std::vector<std::vector<int>> M(n+1, std::vector<int>(W+1,0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      if (data[i-1].second > j)
        M[i][j] = M[i-1][j];
      else
        M[i][j] = std::max(M[i-1][j], data[i-1].first + M[i-1][j-data[i-1].second]);
    }
  }
  std::cout << "Matriz DP:"<< std::endl;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= W; j++)
      std::cout << M[i][j] << "\t";
    std::cout << std::endl;
  }
  return M[n][W];
}


int main() {
  int n, W, v, p;
  // leer numero de objetos y capacidad de la mochila
  std::cin >> n >> W;
  // leer pares (valor, peso) para cada objeto
  std::vector<std::pair<int, int>> data;
  for (int i = 0; i < n; i++) {
    std::cin >> v >> p;
    data.push_back({v, p});
  }
  std::cout << std::endl;
  int resultado = mochilaDP(data, n, W);
  std::cout << std::endl;
  std::cout << "Resultado DP: " << resultado << std::endl;
  return 0;
}