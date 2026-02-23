/**
* Ejemplo del uso de la funcion Z para resolver el problema
* de la coincidencia de un patron 
* Tiene complejidad O(n^2), pero es mejorable usando un mejor
* algoritmo para calcular la funcion Z -- O(n)
* 
* Compilacion para debug:
*    g++ -std=c++17 -Wall -g -o main *.cpp
*
* Compilacion para ejecucion:
*    g++ -std=c++17 -O3 -o main *.cpp
*
* Ejecucion:
*    ./main < TestCases/test01.txt
**/

#include <iostream>
#include <vector>
#include <string>   

// Algoritmo naive para calcular la funcion Z
// Complejidad O(n^2)
std::vector<int> computeZ_Function(const std::string& S) {
    int n = S.size();
    std::vector<int> Z(n, 0);
    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n; j++) {
            if (S[j] == S[j-i])
                Z[i]++;
            else
                break;
        }
    }
    return Z;
}

int main() {
    std::string texto, patron;
    std::getline(std::cin, texto);
    std::getline(std::cin, patron);
    std::string Tp = patron + "$" + texto;
    int m = patron.length();
    int result = -1;
    std::vector<int> resZ = computeZ_Function(Tp);
    for (int i = m+1; i < (int)resZ.size(); i++) {
        if (resZ[i] == m) {
            result = i - (m+1);
            break;
        }
    }
    if (result != -1)
        std::cout << "La primera coincidencia de P en T esta en: " << result << std::endl;
    else
        std::cout << "El patron P no existe en el texto T" << std::endl;
    return 0;
}
