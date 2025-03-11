#include <iostream>
using namespace std;

// Estructura para un nodo
struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
};

// Función para crear un nodo
Nodo* nuevoNodo(int valor) {
    Nodo* nodo = new Nodo();
    nodo->valor = valor;
    nodo->izquierdo = nodo->derecho = nullptr;
    return nodo;
}

// Función para insertar un nodo en el árbol
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return nuevoNodo(valor);
    }
    if (valor < raiz->valor) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    return raiz;
}

// Función para recorrer el árbol en orden (In-Order)
void recorridoInOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        recorridoInOrden(raiz->izquierdo);
        cout << raiz->valor << " ";
        recorridoInOrden(raiz->derecho);
    }
}

int main() {
    Nodo* raiz = nullptr;

    // Insertando elementos
    raiz = insertar(raiz, 30);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 10);
    insertar(raiz, 25);

    // Imprimir recorrido en orden
    cout << "Recorrido en orden: ";
    recorridoInOrden(raiz);  // Salida esperada: 10 20 25 30 40
    cout << endl;

    return 0;
}

