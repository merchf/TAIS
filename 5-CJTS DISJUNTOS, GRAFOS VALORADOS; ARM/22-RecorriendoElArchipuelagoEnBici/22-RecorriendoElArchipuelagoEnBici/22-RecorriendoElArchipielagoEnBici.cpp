
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "IndexPQ.h"
#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class Archipielago {
private:
    int minimo;
    vector<Arista<int>> edgeTo;
    vector<bool> visitados;
    vector<int> distTo;
    IndexPQ<Arista<int>, greater<Arista<int>>> pq;

    void visit(GrafoValorado<int> const& g, int v) {
        visitados[v] = true;

        for (Arista<int> e : g.ady(v)) {

            int w = e.otro(v);

            if (visitados[w])continue;
            if (e.valor() < distTo[w]
                ) {
                edgeTo[w] = e;
                distTo[w] = e.valor();
                pq.update(w, e);
            }
        }

    }

public:
    Archipielago(GrafoValorado<int> const& g): minimo(-1),visitados(g.V(),false), distTo(g.V(), INT_MAX), edgeTo(g.V()), pq(g.V()) {
        distTo[0] = 0;
        visit(g, 0);
        while (!pq.empty()) {
            auto aux = pq.top(); pq.pop();
            visit(g, aux.elem);
        }

        bool conexo = true;
        for (int i = 0; i < g.V() && conexo; i++)
        {
            conexo = visitados[i];
        }
        if (conexo) {
            int coste = 0;
            for (auto i : distTo)
            {
                coste += (i<INT_MAX ? i : 0);
            }
            minimo = coste;
        }
       
       
    }
    int getMinimo() {
        return minimo;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int islas, puentes, v, w, valor;
    cin >> islas >> puentes;
    if (!std::cin)  // fin de la entrada
        return false;
    GrafoValorado<int> grafo(islas);
    for (int i = 0; i < puentes; i++)
    {
        cin >> v >> w >> valor;
        grafo.ponArista({ v - 1,w - 1,valor });
    }

    Archipielago sol(grafo);

    // escribir sol
    (sol.getMinimo() != -1) ? cout << sol.getMinimo() : cout << "No hay puentes suficientes";
    cout << '\n';

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
