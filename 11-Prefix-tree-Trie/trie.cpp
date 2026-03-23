#include "trie.h"

trie::trie() { 
  root = new nodeTrie(); 
}

trie::~trie() {
  // TO-DO
  // Implementa un recorrido del trie para
  // liberar su memoria
}

void trie::insert(std::string word) {
  nodeTrie *current = root;
  for (int i = 0; i < (int)word.length(); i++) {
    if (current->getChild(word[i]) == nullptr) {
      nodeTrie *newNode = new nodeTrie(word[i], current);
      current->setChild(newNode);
    }
    current = current->getChild(word[i]);
  }
  current->setIsLeaf(true);
}

bool trie::search(std::string word) {
  nodeTrie *current = root;
  if (current == nullptr)
    return false;
  for (int i = 0; i < (int)word.length(); i++) {
    current = current->getChild(word[i]);
    if (current == nullptr)
      return false;
  }
  return current->getIsLeaf();
}

void trie::dfs() {
  // TO-DO
  // Implementa un recorrido DFS del trie
  // para imprimir todas las palabras en orden 
  // lexicografico (alfabetico)
  // los parametros y return pueden variar
}

void trie::autoComplete(std::string prefix) {
  // TO-DO
  // Implementa la funcion autocomplete que
  // imprime cada una de las palabras contenidas 
  // en el TRIE que tengan como prefijo el 
  // string prefix
}

int trie::getTotalBytes() {
  // TO-DO
  // Implementa la funcion para conocer el tamaño total
  // en bytes que utiliza en RAM TRIE
  return 0;
}