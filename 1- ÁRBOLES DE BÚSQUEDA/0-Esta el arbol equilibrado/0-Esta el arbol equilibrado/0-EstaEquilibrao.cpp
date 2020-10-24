
// Mercedes Herrero Fernandez
//TAIS40 

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "bintree.h"  // propios o los de las estructuras de datos de clase

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(bintree<char> const & arbol) {
    if (!arbol.empty()) {
        int izq, dcha;
        izq = resolver(arbol.left());
        if (izq != -1) {

            dcha = resolver(arbol.right());
        }
        if (izq != -1 && dcha != -1) {
            return (abs(dcha - izq) < 2) ? max(dcha + 1, izq + 1) : -1;
        }
        return -1;
    }
    return 0;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    cout <<  ((resolver(arbol) != -1)?"SI" : "NO" )<< endl;

    // escribir solución
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
