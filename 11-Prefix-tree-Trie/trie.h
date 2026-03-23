#ifndef _TRIE_H
#define _TRIE_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include "nodeTrie.h"

class trie {
private:
  nodeTrie *root;

public:
  trie();
  ~trie(); // TO-DO Act 3.1
  void insert(std::string word);
  bool search(std::string word);
  void dfs(); // TO-DO Act 3.1 (parametros y return pueden variar)
  void autoComplete(std::string prefix); // TO-DO Act 3.1 (parametros y return pueden variar)
  int getTotalBytes(); // TO-DO Act 3.1 regresa el tamaño en bytes total del trie (parametros y return pueden variar)
};


#endif // _TRIE_H