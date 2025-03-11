#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;

class Grafo {
private:
    unordered_map<string, list<string>> adj; // Lista de adyacencia usando un mapa
    unordered_map<string, bool> visitado; // Mapa para marcar los nodos visitados

public:
    void agregarRuta(const string& origen, const string& destino); // Agregar una ruta entre dos ciudades
    void imprimirRutas(); // Imprimir todas las rutas
    bool tieneRuta(const string& origen, const string& destino); // Verificar si existe una ruta
    void dfs(const string& nodo, const string& destino, bool& encontrado); // DFS para encontrar la ruta
};

void Grafo::agregarRuta(const string& origen, const string& destino) {
    adj[origen].push_back(destino);
}

void Grafo::imprimirRutas() {
    for (const auto& ciudad : adj) {
        cout << ciudad.first << " -> ";
        for (const auto& ruta : ciudad.second) {
            cout << ruta << " ";
        }
        cout << endl;
    }
}

void Grafo::dfs(const string& nodo, const string& destino, bool& encontrado) {
    if (nodo == destino) {
        encontrado = true;
        return; // Si encontramos la ciudad de destino, terminamos
    }

    visitado[nodo] = true; // Marcamos el nodo actual como visitado

    // Recorremos todas las rutas del nodo actual
    for (const string& vecino : adj[nodo]) {
        if (!visitado[vecino]) {
            dfs(vecino, destino, encontrado);
        }
    }
}

bool Grafo::tieneRuta(const string& origen, const string& destino) {
    visitado.clear(); // Limpiar el mapa de visitados antes de comenzar el DFS
    bool encontrado = false;
    dfs(origen, destino, encontrado);
    return encontrado;
}

int main() {
    Grafo redDeRutas;

    // Agregar rutas entre ciudades
    redDeRutas.agregarRuta("CiudadA", "CiudadB");
    redDeRutas.agregarRuta("CiudadA", "CiudadC");
    redDeRutas.agregarRuta("CiudadB", "CiudadD");
    redDeRutas.agregarRuta("CiudadC", "CiudadD");
    redDeRutas.agregarRuta("CiudadD", "CiudadE");

    // Imprimir las rutas del grafo
    cout << "Rutas entre las ciudades:\n";
    redDeRutas.imprimirRutas();

    // Consultar si existe una ruta entre dos ciudades
    string origen, destino;
    cout << "\nIngrese la ciudad de origen: ";
    cin >> origen;
    cout << "Ingrese la ciudad de destino: ";
    cin >> destino;

    if (redDeRutas.tieneRuta(origen, destino)) {
        cout << "Sí, hay una ruta de " << origen << " a " << destino << ".\n";
    } else {
        cout << "No, no hay una ruta de " << origen << " a " << destino << ".\n";
    }

    return 0;
}

