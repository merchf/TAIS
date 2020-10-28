
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "Grafo.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class NodoLejano {
private:
    vector<bool> visitados;
    vector<int> distancia;
    int inalcanzables;

    void bfs(const Grafo& g, int s) {
        queue<int> cola;
        distancia[s] = 0;
        visitados[s] = true;
        cola.push(s);
        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            for (int w: g.ady(v)){
                if (!visitados[w]) {
                    distancia[w] = distancia[v] + 1;
                    visitados[w] = true;
                    cola.push(w);
                }
            }
        }
    }
public:
    NodoLejano(const Grafo& g, int origen, int ttl): visitados(g.V(),false),distancia(g.V()),inalcanzables(g.V()) {
        bfs(g, origen);
        for ( int i = 0; i < g.V(); i++)
        {
            if (visitados[i] && distancia[i]<=ttl) {
                inalcanzables--;
            }
        }
    }
    int nodosInalcanzables() {
        return inalcanzables;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int nodos, conexiones;
    cin >> nodos >> conexiones;
    if (!std::cin)  // fin de la entrada
        return false;
    Grafo g(nodos);
    int v, w;
    for (int i = 0; i < conexiones; i++)
    {
        cin >> v >> w;
        g.ponArista(v - 1, w - 1);
    }
    int consultas, nodoInicial, ttl;
    cin >> consultas;
    for (int i = 0; i < consultas; i++)
    {
        cin >> nodoInicial >> ttl;
        NodoLejano sol(g, nodoInicial - 1, ttl);
        cout << sol.nodosInalcanzables() << '\n';
    }
    cout << "---" << '\n';
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
