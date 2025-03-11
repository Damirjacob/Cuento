#include <iostream>
#include <list>
using namespace std;

class Grafo {
private:
    int V; // Número de vértices
    list<int>* adj; // Lista de adyacencia

public:
    Grafo(int V); // Constructor
    void agregarArista(int v, int w); // Agregar arista
    void imprimirGrafo(); // Imprimir el grafo
};

Grafo::Grafo(int V) {
    this->V = V;
    adj = new list<int>[V]; // Crear la lista de adyacencia
}

void Grafo::agregarArista(int v, int w) {
    adj[v].push_back(w); // Agregar w a la lista de adyacencia de v
    adj[w].push_back(v); // Como es no dirigido, agregar v a la lista de adyacencia de w
}

void Grafo::imprimirGrafo() {
    for (int i = 0; i < V; i++) {
        cout << "Vértice " << i << ": ";
        for (int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    Grafo g(5); // Crear un grafo con 5 vértices
    g.agregarArista(0, 1);
    g.agregarArista(0, 4);
    g.agregarArista(1, 2);
    g.agregarArista(1, 3);
    g.agregarArista(1, 4);
    g.agregarArista(3, 4);

    cout << "Representación del grafo (lista de adyacencia):" << endl;
    g.imprimirGrafo();

    return 0;
}
