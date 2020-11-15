
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <string>
#include "IndexPQ.h"
#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


class Dijkstra {
private:
    std::vector<int> dist;
    std::vector<AristaDirigida<int>> ult;
    IndexPQ<int> pq;
    void relajar(AristaDirigida<int> a, vector<int> const & carga) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()+ carga[w]) {
            dist[w] = dist[v] + a.valor() + carga[w]; ult[w] = a;
            pq.update(w, dist[w]);
        }
    }

public:
    Dijkstra(DigrafoValorado<int> const& g, vector<int> const & carga) :dist(g.V(), INT_MAX), ult(g.V()), pq(g.V()) {
        dist[0] = carga[0];
        pq.push(0, carga[0]);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a,carga);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INT_MAX; }
    int distancia(int v) const { return dist[v]; }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)  // fin de la entrada
        return false;
    vector <int> costes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> costes[i];
    }
    int m;
    cin >> m;
    int v, w, coste;
    DigrafoValorado<int> g(n);

    for (int i = 0; i < m; i++)
    {
        cin >> v >> w >> coste;
        g.ponArista({ v - 1,w - 1,coste });

    }

    Dijkstra sol(g, costes);

    // escribir sol
    (sol.distancia(g.V() - 1) != INT_MAX ? cout << sol.distancia(g.V() - 1) : cout << "IMPOSIBLE");
    cout <<'\n';


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
