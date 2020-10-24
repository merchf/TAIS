
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase
using namespace std;
struct tAtriles {
    int musicos;
    int partituras;
};

bool operator>(const tAtriles& a, const tAtriles& b) {
    return (a.musicos / a.partituras) > (b.musicos / b.partituras);
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int partituras, instrumentos;
    cin >> partituras >> instrumentos;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<tAtriles, greater<>> cola;
    for (int i = 0; i < instrumentos; i++)
    {
        tAtriles dato;
        cin >> dato.musicos;
        dato.partituras = 1;
        partituras--;
        cola.push(dato);
    }
    /* ahora tengo que repartir las partituras restantes*/
    while (partituras > 0) {
        tAtriles primero = cola.top();
        cola.pop();
        primero.partituras++;
        cola.push(primero);
        partituras--;
    }

    // escribir sol
    tAtriles sol = cola.top();
    int musicosJuntos = sol.musicos / sol.partituras;
    cout << musicosJuntos << '\n';
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
