
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "IndexPQ.h"  
#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class DijkstraCaminoCole {
private:
    std::vector<int> dist;
    vector<int> caminos;
    IndexPQ<int> pq;
    void relajar(Arista<int> a,int v) {
        int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            caminos[w] = caminos[v];
            pq.update(w, dist[w]);
        } else if(dist[w] == dist[v] + a.valor()){
            caminos[w] += caminos[v];
        }
    }

public:
    DijkstraCaminoCole(GrafoValorado<int> const& g) :dist(g.V(), INT_MAX),caminos(g.V(),0), pq(g.V()) {
        dist[0] = 0;
        pq.push(0, 0);
        caminos[0] = 1;
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a,v);
        }
    }
    int getCaminos()  { 
        return caminos[caminos.size()-1]; 
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, c, v, w, valor;
    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> c;
    GrafoValorado<int> g(n);
    for (int i = 0; i < c; i++)
    {
        cin >> v >> w >> valor;
        g.ponArista({v-1,w-1,valor});
    }
    DijkstraCaminoCole sol(g);

    // escribir sol
        cout << sol.getCaminos() << '\n';
  
  
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
