
// Mercedes Herrero Fernandez
//TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
Hay que tener en cuenta en el momento de la entrada de datos si es tipo I o tipo A:
Si es tipo I se guardaran los datos del nuevo paciente en la cola siendo el más prioritario el paciente con mayor gravedad y en caso de coincidir, el que menor posicion tenga
(la posicion representa el tiempo de espera a menor pos significa que ha entrado primero)
Si es de tipo A se mostrara el paciente mas prioritario( cola.top()), eliminandolo de la cola para pasar al siguiente
*/

#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase
using namespace std;

struct tPacientes {
    string nombre;
    long int gravedad;
    int pos;
};

bool operator<(tPacientes const& a, tPacientes const& b) {
    return a.gravedad > b.gravedad || (a.gravedad == b.gravedad && a.pos < b.pos);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int eventos;
    cin >> eventos;
    if (eventos == 0)
        return false;
    char tipo;
    PriorityQueue<tPacientes> cola;
    for (int i = 0; i < eventos; i++)
    {
        cin >> tipo;
        if (tipo == 'I') {
            tPacientes nuevo;
            cin >> nuevo.nombre >> nuevo.gravedad;
            nuevo.pos = i;
            cola.push(nuevo);
        }
        else {//doctor libre
            tPacientes consulta = cola.top();
            cola.pop();
            cout << consulta.nombre << '\n';
        }
    }

    cout << "---" << '\n';
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
