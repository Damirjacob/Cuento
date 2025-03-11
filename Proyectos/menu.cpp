#include <iostream>
#include <stack>

using namespace std;

void insertarPila(stack<int>& pila) {
    int num;
    cout << "Ingrese un número entero: ";
    cin >> num;
    pila.push(num);
    cout << "Número " << num << " insertado en la pila.\n";
}

void borrarPila(stack<int>& pila) {
    if (!pila.empty()) {
        cout << "Número " << pila.top() << " eliminado de la pila.\n";
        pila.pop();
    } else {
        cout << "La pila está vacía, no hay elementos para eliminar.\n";
    }
}

void listarPila(stack<int> pila) {
    if (pila.empty()) {
        cout << "La pila está vacía.\n";
        return;
    }
    cout << "Elementos en la pila (de arriba hacia abajo):\n";
    while (!pila.empty()) {
        cout << pila.top() << "\n";
        pila.pop();
    }
}

int main() {
    stack<int> pila;
    int opcion;
    
    do {
        cout << "\nMenú de gestión de pilas:\n";
        cout << "1. Insertar en la pila\n";
        cout << "2. Borrar de la pila\n";
        cout << "3. Listar pila\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                insertarPila(pila);
                break;
            case 2:
                borrarPila(pila);
                break;
            case 3:
                listarPila(pila);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (opcion != 4);
    
    return 0;
}
