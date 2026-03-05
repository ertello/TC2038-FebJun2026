/**
 * Programa que implementa la construccion del arreglo 
 * de sufijos y el arreglo de prefijos comunes mas
 * largos de un string
 *
 * Referencias:
 * https://www.geeksforgeeks.org/count-distinct-substrings-string-using-suffix-array/
 * 
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
  *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < test01.txt
 **/

#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::map;
using std::string;

// O(n log n)
vector <pair<string, int>> createSuffixArray(string S) {
  string T = S + "$";
  int n = T.length();
  map<string, int> M;
  vector<pair<string, int>> suffix;
  // crear los sufijos
  string sub = "";
  for (int i = n-1; i >= 0; i--) {
    sub = T[i] + sub;
    M[sub] = i;   // insercion en tiempo O(log n)
  }
  // recuperar los valores del map M ya ordenados
  for (auto x : M)
    suffix.push_back(make_pair(x.first, x.second));
  return suffix;
}

// O(n) Algoritmo de Kasai para crear el LCP
vector<int> createPrefixArray(string S, vector<pair<string,int>> sa) {
  string T = S + "$";
  int n = T.length();
  vector<int> lcp(n, 0);
  vector<int> invSA(n, 0);
  for (int i = 0; i < n; i++)
    invSA[sa[i].second] = i;
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (invSA[i] == n-1) {
      k = 0;
      continue;
    }
    int j = sa[invSA[i]+1].second;
    while (i+k < n && j+k < n && T[i+k] == T[j+k])
      k++;
    lcp[invSA[i]] = k;
    if (k > 0)
      k--;
  }
  return lcp;
}

int main() {
  string texto;
  getline(cin, texto);
  cout << "texto: " << texto << endl;
  cout << "Arreglo de sufijos" << endl;
  vector<pair<string, int>> suffixArray(createSuffixArray(texto));
  for (int i = 0; i < (int)suffixArray.size(); i++)
    cout << suffixArray[i].first << " " << suffixArray[i].second << endl;
  cout << endl;
  cout << "Arreglo de prefijos" << endl;
  vector<int> prefixArray(createPrefixArray(texto, suffixArray));
  for (int i = 0; i < (int)prefixArray.size(); i++)
    cout << "prefixArray[" << i << "] = " << prefixArray[i] << endl;
  cout << endl;
  return 0;
}