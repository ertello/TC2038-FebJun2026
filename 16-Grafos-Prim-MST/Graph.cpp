
#include "Graph.h"

Graph::Graph() {
  //std::cout << "Constructor " << this << std::endl;
  adjList.clear();
  numNodes = 0;
  numEdges = 0;
}

Graph::~Graph() {
  //std::cout << "Destructor " << this << std::endl;
  adjList.clear();
  numNodes = 0;
  numEdges = 0;
  //std::cout << "Size adjList " << adjList.size() << std::endl;
}

void Graph::split(std::string line, std::vector<int> &res) {
  size_t strPos = line.find(" ");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::readGraph(std::istream &input) {
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) { // Ignorar primera linea de texto
      i++;
      continue;
    }
    if (i == 1) {
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[1];
      // Reservar memoria para los renglones de la lista de adyacencia
      // cada uno tiene una lista vacia
      adjList.resize(numNodes, std::list<std::pair<int, int>>());
      i++;
      continue;
    }
    std::vector<int> res;
    split(line, res);
    int u = res[0] - 1; // convierte nodo a cero-basado
    int v = res[1] - 1; // convierte nodo a cero-basado
    int weight = res[2];
    // Grafos no dirigidos agrega la arista (u,v) y la (v,u)
    // Grafo ponderado guarda pares(nodo, peso)
    adjList[u].push_back(std::make_pair(v, weight));
    adjList[v].push_back(std::make_pair(u, weight));
    i++;
  }
}

// Imprime grafo 
void Graph::print() {
  std::cout << "Adjacency List" << std::endl;
  for (int u = 0; u < numNodes; u++) {
    std::cout << "vertex " << u + 1 << ":"; // convierte nodo a uno-basado
    for (auto const& edge : adjList[u]) {
      // convierte nodo a uno-basado
      std::cout << '\t' << "{" << edge.first + 1 << "," << edge.second << "}";
    }
    std::cout << std::endl;
  }
}

// Recorrido del grafo DFS a partir del nodo v (cero-basado)
void Graph::DFS(int v) {
  // Declaramos un set del STL de C++ (elementos unicos y ordenados)
  std::set<int> visited;
  // Creamos un stack
  std::stack<int> stack;
  bool isInVisited = false;
  std::cout << "Recorrido DFS " << std::endl;
  // Entra al stack el vertice inicial
  stack.push(v);
  while (!stack.empty()) {
    // Extraemos un vertice del stack y lo procesamos (print)
    v = stack.top();
    stack.pop();
    isInVisited = visited.find(v) != visited.end();
    if (!isInVisited) {
      visited.insert(v);
      // convierte nodo a uno-basado
      std::cout << v + 1 << " ";
    }
    // Obtenemos los vertices adyacentes del vertice v
    // Si estos no han sido visitados se marcan como visitados
    // y los metemos al stack
    for (auto const& edge : adjList[v]) {
      int u = edge.first;
      // Verificar si el vecino u ya fue visitado
      isInVisited = visited.find(u) != visited.end();
      if (!isInVisited) // no visitado
        stack.push(u);
    }
  }
  std::cout << std::endl;
}

// Recorrido del grafo BFS a partir del nodo v (cero-basado)
void Graph::BFS(int v) {
  // Declarar un set del STL de C++ (elementos unicos y ordenados)
  std::set<int> visited;
  // Crear un queue
  std::queue<int> queue;
  bool isInVisited = false;
  std::cout << "Recorrido BFS" << std::endl;
  // Entra al queue el vertice inicial
  queue.push(v);
  while (!queue.empty()) {
    // Extraer un vertice del queue y lo procesamos (print)
    v = queue.front();
    queue.pop();
    isInVisited = visited.find(v) != visited.end();
    if (!isInVisited) {
      visited.insert(v);
      // convierte nodo a uno-basado
      std::cout << v + 1 << " ";
    }
    // Obtenemos los vertices adyacentes del vertice v
    // Si estos no han sido visitados se marcan como visitados
    // y los metemos al queue
    for (auto const& edge : adjList[v]) {
      int u = edge.first;
      // Verificar si el vecino u ya fue visitado
      isInVisited = visited.find(u) != visited.end();
      if (!isInVisited) // no visitado
        queue.push(u);
    }
  }
  std::cout << std::endl;
}

std::pair<int, std::vector<std::pair<std::pair<int, int>, int>>> Graph::primMST(int startNode) {
  // Validar que el nodo inicial exista
  if (startNode < 0 || startNode >= numNodes) {
      return {0, {}};
  }
  // minHeap contine pares <peso, <nodoOrigen, nodoDestino>>
  typedef std::pair<int, std::pair<int, int>> EdgeEntry;
  std::priority_queue<EdgeEntry, std::vector<EdgeEntry>, std::greater<EdgeEntry>> pq;
  std::vector<bool> visited(numNodes, false);
  std::vector<std::pair<std::pair<int, int>, int>> mstEdges;
  int totalCost = 0;  
  // Marcamos el nodo de inicio como visitado
  visited[startNode] = true;
  // Agregamos todas las aristas que salen del nodo inicial al heap
  for (auto const& edge : adjList[startNode]) { 
      // edge contiene un par <nodo, peso>
      pq.push({edge.second, {startNode, edge.first}});
  }
  // El MST de un grafo con n nodos debe tener exactamente n-1 aristas
  while (!pq.empty() && mstEdges.size() < (size_t)(numNodes - 1)) {
    int weight = pq.top().first;
    int u = pq.top().second.first; // nodo origen
    int v = pq.top().second.second; // nod destino
    pq.pop();
    // Si el nodoDestino ya esta en el arbol, esta arista crearia un ciclo
    if (visited[v]) continue;
    // Utilizamos el nuevo nodo en el MST
    visited[v] = true;
    totalCost += weight;
    mstEdges.push_back({{u, v}, weight});
    // Agregamos las aristas del nuevo nodo recien integrado al MST
    for (auto const& nextEdge : adjList[v]) {
      // nextEdge contiene un par <nodo, peso>
      if (!visited[nextEdge.first])
        pq.push({nextEdge.second, {v, nextEdge.first}});
    }
  }
  // Imprimir resultado
  std::cout << std::endl << "Aristas del MST con inicio en: " << startNode+1 << std::endl;
  for (auto const& edge : mstEdges) {
    std::cout << edge.first.first+1 << " - " << edge.first.second+1 << ": " << edge.second << std::endl;
  }
  std::cout << "Costo total del MST: " << totalCost << std::endl;
  return {totalCost, mstEdges};
}

