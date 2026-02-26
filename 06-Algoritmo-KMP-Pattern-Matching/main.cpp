/**
* Algoritmo Knuth-Morris-Pratt (KMP) para resolver el problema
* Pattern Matching
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

// Complejidad temporal O(m)
// Complejidad espacial O(m)
std::vector<int> preprocessKMP(const std::string &P) {
    int m = P.length();
    std::vector<int> LPS(m,0);  // Longest prefix suffix
    int i = 1, j = 0;
    while (i < m) {
        if (P[i] == P[j]) {
            j++;
            LPS[i] = j;
            i++;
        }
        else {
            if (j == 0) {
                LPS[i] = 0;
                i++;
            }
            else
                j = LPS[j-1];
        }
    }
    return LPS;
}

// Complejidad temporal O(n+m)
// Complejidad espacial O(m)
int KMP(const std::string &P, const std::string &T) {
    int n = T.length();
    int m = P.length();
    std::vector<int> LPS(preprocessKMP(P));
    int i = 1, j = 0;
    while ((n-i) >= (m-j)) {
        if (T[i] == P[j]) {
            i++;
            j++;
        }
        if (j == m)
            return (i-j);  // Inicio del match de P en T
        if (i < n && T[i] != P[j]) {
            if (j != 0)
                j = LPS[j-1];
            else
                i++;
        }
    }
    return -1;  // No hay match de P en T
}

int main() {
    std::string texto;
    std::string patron;
    std::getline(std::cin, texto);
    std::getline(std::cin, patron);
    int resultado = KMP(patron, texto);
    std::cout << "Resultado KMP: " << resultado << std::endl;
    return 0;
}