#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Estructura para un nodo que representa un poste de electricidad
struct Poste {
    int id;
    int capacidad;
    Poste* izquierdo;
    Poste* derecho;
    string zona; // Zona para los puntos cardinales

    Poste(int id, int capacidad, string zona = "Centro") {
        this->id = id;
        this->capacidad = capacidad;
        this->zona = zona;
        izquierdo = derecho = nullptr;
    }
};

// Función para insertar un poste en el árbol binario
Poste* insertar(Poste* raiz, int id, int capacidad, string zona = "Centro") {
    if (raiz == nullptr) {
        return new Poste(id, capacidad, zona);
    }

    if (id < raiz->id) {
        // Si el ID es menor, va a la izquierda (Zona Sur u Oeste)
        string nuevaZona = (raiz->zona == "Centro" || raiz->zona == "Norte") ? "Sur" : "Oeste";
        raiz->izquierdo = insertar(raiz->izquierdo, id, capacidad, nuevaZona);
    } else {
        // Si el ID es mayor, va a la derecha (Zona Norte o Este)
        string nuevaZona = (raiz->zona == "Centro" || raiz->zona == "Sur") ? "Norte" : "Este";
        raiz->derecho = insertar(raiz->derecho, id, capacidad, nuevaZona);
    }
    return raiz;
}

// Función para imprimir el recorrido en orden de los postes
void imprimirRecorrido(Poste* raiz) {
    if (raiz != nullptr) {
        imprimirRecorrido(raiz->izquierdo);
        cout << "Poste ID: " << raiz->id << ", Capacidad: " << raiz->capacidad << " kW, Zona: " << raiz->zona << endl;
        imprimirRecorrido(raiz->derecho);
    }
}

// Función para clasificar los postes por zona (Norte, Sur, Este, Oeste)
void clasificarPorZona(Poste* raiz, map<string, vector<int>>& zonas) {
    if (raiz != nullptr) {
        zonas[raiz->zona].push_back(raiz->id);
        clasificarPorZona(raiz->izquierdo, zonas);
        clasificarPorZona(raiz->derecho, zonas);
    }
}

int main() {
    Poste* redDePostes = nullptr;
    int id, capacidad, numPostes;

    cout << "Ingrese el número de postes que desea agregar: ";
    cin >> numPostes;

    // Insertar postes
    for (int i = 0; i < numPostes; i++) {
        cout << "Ingrese el ID del poste " << (i+1) << ": ";
        cin >> id;
        cout << "Ingrese la capacidad del poste " << (i+1) << " (en kW): ";
        cin >> capacidad;

        // Insertar el poste en la red
        redDePostes = insertar(redDePostes, id, capacidad);
    }

    // Clasificar postes por zona
    map<string, vector<int>> zonas;
    clasificarPorZona(redDePostes, zonas);

    // Imprimir los postes clasificados por zona
    cout << "\nPostes clasificados por zona (Puntos Cardinales):\n";
    for (const auto& zona : zonas) {
        cout << zona.first << ": ";
        for (int id : zona.second) {
            cout << id << " ";
        }
        cout << endl;
    }

    // Imprimir el recorrido de los postes
    cout << "\nRecorrido de la red de postes (en orden de ID):\n";
    imprimirRecorrido(redDePostes);

    return 0;
}






 



