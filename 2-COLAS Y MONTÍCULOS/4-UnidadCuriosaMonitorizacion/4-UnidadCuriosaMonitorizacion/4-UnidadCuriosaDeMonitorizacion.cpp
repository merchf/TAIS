
// Mercedes Herrero Fernandez
//TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
La clave de este ejercicio es controlar en que momento va a volver a tocar el envio de informacion
Para ello, se almacena un struct con el identificador del usuario, su periocidad y el momento en el que le va a volver a tocar la entrega de la informacion.
Cuando se selecciona por primera vez a un identificador, hay que actualizar si momento siguiente acumulando si valor mas la periocidad del usuario.
De esta forma en la cola siempre tendra prioridad el usuario que menor momento siguiente tenga y en caso de ser el mismo, el que menor identificador tenga.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

using namespace std;


struct registro
{
    long int id;
    int periodo;
    int siguiente;
};

bool operator<(registro const& a, registro const& b) {
    return a.siguiente < b.siguiente || a.siguiente == b.siguiente && a.id <= b.id;
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void  resolver(PriorityQueue<registro>& cola,int k) {
    for (int i = 0; i < k; i++)
    {
        registro actual = cola.top();
        cola.pop();
        cout << actual.id << '\n';
        actual.siguiente += actual.periodo;
        cola.push(actual);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numUsuarios, periocidadUser,k;
    long int idUser;
    // leer los datos de la entrada
    cin >> numUsuarios;
    if (numUsuarios == 0)
        return false;
    PriorityQueue<registro> cola;
    for (int i = 0; i < numUsuarios; i++)
    {
        cin >> idUser >> periocidadUser;
        cola.push({ idUser,periocidadUser,periocidadUser });
    }
    cin >> k;
    // escribir sol
    resolver(cola, k);
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
