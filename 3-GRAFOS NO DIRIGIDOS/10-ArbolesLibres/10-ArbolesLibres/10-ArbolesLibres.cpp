
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase



using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(const Grafo & g) {
    vector<bool> visitados(g.V(), false);
    int totalVisitados = 0;
    return dfs(g,0,)
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int v, a;
    cin >> v;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> a;
    Grafo g(v);
    for (int i = 0; i < a; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g.ponArista(v1, v2);
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
