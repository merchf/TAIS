
// Mercedes Herrero Fernandez   TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


class Sumidero {
private:

public:
    Sumidero() {

    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int v, a;
    cin >> v >> a;
    if (!std::cin)  // fin de la entrada
        return false;
    Digrafo g(v);
    int a1, a2;
    for (int i = 0; i < a; i++)
    {
        cin >> a1 >> a2;
        g.ponArista(a1, a2);
    }
    Solucion sol = resolver(datos);

    // escribir sol

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
