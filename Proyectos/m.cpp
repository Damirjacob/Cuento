#include <iostream>
#include <queue>

using namespace std;

void mostrarMenu() {
    cout << "\nMENU:" << endl;
    cout << "1. Insertar en cola" << endl;
    cout << "2. Borrar en cola" << endl;
    cout << "3. Listar cola" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    queue<int> cola;
    int opcion, numero;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> numero;
                cola.push(numero);
                cout << "Numero insertado en la cola." << endl;
                break;
            case 2:
                if (!cola.empty()) {
                    cout << "Numero eliminado: " << cola.front() << endl;
                    cola.pop();
                } else {
                    cout << "La cola esta vacia, no hay elementos para borrar." << endl;
                }
                break;
            case 3:
                if (!cola.empty()) {
                    queue<int> temp = cola;
                    cout << "Elementos en la cola: ";
                    while (!temp.empty()) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                } else {
                    cout << "La cola esta vacia." << endl;
                }
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
    
    return 0;
}
