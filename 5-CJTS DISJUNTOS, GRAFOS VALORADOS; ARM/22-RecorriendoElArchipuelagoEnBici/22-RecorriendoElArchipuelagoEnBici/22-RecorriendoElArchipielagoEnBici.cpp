
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include "IndexPQ.h"
#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class Archipielago {
private:
    int minimo;
    vector<bool> visitados;
    queue<Arista<int>> cola;
    std::priority_queue<Arista<int>,vector<Arista<int>>,greater<Arista<int>>> pq;

    void visit(GrafoValorado<int> const& g, int v) {
        visitados[v] = true;
        for (Arista<int> e : g.ady(v)) {
            if(!visitados[e.otro(v)]){
                pq.push(e);
            }
        }

    }

public:
    Archipielago(GrafoValorado<int> const& g): minimo(-1),visitados(g.V(),false) {
        visit(g, 0);
        while (!pq.empty()) {
            auto aux = pq.top(); pq.pop();
            int v = aux.uno(), w = aux.otro(v);
            if (!visitados[v] || !visitados[w]) {
                cola.push(aux);
                if (!visitados[v]) {
                    visit(g, v);
                }
                if (!visitados[w]) {
                    visit(g, w);
                }
            }
        }
    
        if (conexo(g)) {
            int coste = 0;
            for (int i = 0; i < cola.size(); i++)
            {
                coste += cola.front().valor();
                cola.pop();
            }
            minimo = coste;
        }
       
    }
    bool conexo(GrafoValorado<int> const& g) {
        return cola.size() == g.V() - 1;
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
