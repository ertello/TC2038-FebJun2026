/**
 * Algoritmo de Manacher para resolver el problema
 * del palindromo más largo
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -Wall -o main *.cpp
 * Ejecucion con valgrind:
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -Wall -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < TestCases/test01.txt
 **/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::min;
using std::vector;

// O(n^2)
pair<int, int> longestPalindromeNaive(string S) {
    int n = S.length();
    int maxLong = 1, startAt = 0;
    int i, j;
    for (i = 0; i < n-1; i++) {
        j = 1;  // substrings de longitud impar con centro en i
        while ((i-j) >= 0 && (i+j) < n && S[i-j] == S[i+j])
            j++;
        if ((2*j) - 1 > maxLong) {
            maxLong = (2*j) - 1;
            startAt = i - j + 1;
        }
        j = 0;  // substrings de longitud par con centro en i
        while ((i-j-1) >= 0 && (i+j) < n && S[i-j-1] == S[i+j])
            j++;
        if ((2*j) > maxLong) {
            maxLong = (2*j);
            startAt = i - j;
        }
    }
    return {startAt, maxLong};
}

// O(n)
pair<int, int> manacher(string S) {
    int i;
    string T = "";
    for (i = 0; i < (int)S.length(); i++) {
        T += "|";
        T += S[i];
    }
    T += "|";
    int m = T.length();
    vector<int> L(m, 0);
    int center = 0;
    int right = 0;
    int maxPalindrome = 0;
    int centerIdx = 0;
    for (i = 1; i < m-1; i++) {
        int iMirror = (2 * center) - i;
        if (right > i)
            L[i] = min(right-i, L[iMirror]);
        while ((i-1-L[i] >= 0) && (i+1+L[i] < m) && (T[i+1+L[i]] == T[i-1-L[i]]))
            L[i]++;
        if (i+L[i] > right) {
            center = i;
            right = i + L[i];
        }
        if (L[i] > maxPalindrome) {
            maxPalindrome = L[i];
            centerIdx = i;
        }
    }
    return {(centerIdx-maxPalindrome)/2, maxPalindrome};
}


int main() {
    string texto;
    getline(cin, texto);
    cout << "texto: " << texto << endl;
    cout << "Algoritmo naive" << endl;
    pair<int, int> result = longestPalindromeNaive(texto);
    cout << "Resultado: {" << result.first << ", " << result.second << "}"
        << endl;
    for (int i = result.first; i < result.first+result.second; i++)
        cout << texto[i];
    cout << endl;

    cout << "Algoritmo Manacher" << endl;
    pair<int, int> result2 = manacher(texto);
    cout << "Resultado: {" << result2.first << ", " << result2.second << "}"
        << endl;
    for (int i = result2.first; i < result2.first+result.second; i++)
        cout << texto[i];
    cout << endl;

    return 0;
}