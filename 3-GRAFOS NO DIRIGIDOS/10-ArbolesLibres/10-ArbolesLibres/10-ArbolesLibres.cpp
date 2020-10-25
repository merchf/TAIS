
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

/*
En este problema hay que comprobar dos cuestiones:
-Sea aciclico-> para ello se verá que no tiene mas de V-1 aristas
-Sea conexo-> se aplicara dfs para comprobar q el numero de de vertices del grafo corresponde con el numero de nodos recorridos.
*/

#include <iostream>
#include <fstream>
#include <vector>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(V + A), recorrido dfs

class ArbolLibreDFS {
private:
    vector<bool> visitados;
    bool conexo;
    void dfs(const Grafo& g, int v, int & totalVisitados) {
        visitados[v] = true;
        totalVisitados++;
        for (int w : g.ady(v)) {
            if (!visitados[w]) {
                dfs(g, w, totalVisitados);
            }
        }
    }
public:
    ArbolLibreDFS(const Grafo& g) : visitados(g.V(), false), conexo(false) {
        int totalVisitados = 0;
        dfs(g, 0, totalVisitados);
        if (totalVisitados == g.V()) {
            conexo = true;
        }
    }

    bool esAciclico(const Grafo& g, int a) {
        return g.V() - 1 == a;
    }
    bool esLibre(const Grafo& g, int a) {
        return conexo && esAciclico(g, a);
    }
};

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
    ArbolLibreDFS sol(g);
    (sol.esLibre(g,a)) ? cout << "SI" : cout << "NO";
    cout << '\n';

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
