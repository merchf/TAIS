
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
Mediante el algoritmo de Disjkstra representaremos las casas como vertices y las calles como aristas. Como solo se puede repartir un paquete a la vez para calcular el camino minimo
se debe aplicar el algoritmo dos veces, utilizando para ello el grafo inverso para la vuelta. Se calcula por un lado el camino minimo para ir y por otro el camino min para volver, de tal forma que la 
suma dara el tiempo min

El coste de la solucion es O(2 * ElogV) 

*/

#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include "IndexPQ.h"
#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
using namespace std;


// función que resuelve el problema
class RepartoPaquetes {
private:
	const int INF = std::numeric_limits<int>::max();
	int tiempo;
	bool posible;
	std::vector<int> dist;
	std::vector<int> distVuelta;
	IndexPQ<int> pq;

	void relajar(AristaDirigida<int> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			pq.update(w, dist[w]);
		}
	}

	void relajarVuelta(AristaDirigida<int> a) {
		int v = a.desde(), w = a.hasta();
		if (distVuelta[w] > distVuelta[v] + a.valor()) {
			distVuelta[w] = distVuelta[v] + a.valor();
			pq.update(w, distVuelta[w]);
		}
	}

public:
	RepartoPaquetes(DigrafoValorado<int> const& g, int orig) : tiempo(0),posible(true),
		dist(g.V(), INF), distVuelta(g.V(), INF), pq(g.V()) {

		//la idea ahora es calcular el camino minimo de ida y posteriormente se suma la vuelta
		dist[orig] = 0;
		pq.push(orig, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}

		//ahora aplicamos para el inverso para la vuelta
		DigrafoValorado<int> inv = g.inverso();
		distVuelta[orig] = 0;
		pq.push(orig, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : inv.ady(v))
				relajarVuelta(a);

		}		
	}


	int getTiempo(const vector<int>& v) {
		for (int i = 0; i < v.size(); i++) {
			if (dist[v[i]] == INF || distVuelta[v[i]] == INF) {
				posible = false;
			}
			tiempo += dist[v[i]] + distVuelta[v[i]];
		}
		return (posible) ? tiempo : -1;
	}

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, C;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> C;
    DigrafoValorado<int> g(N);
    int v, w, valor;
    for (int i = 0; i < C; i++)
    {
        cin >> v >> w >> valor;
        g.ponArista({ v - 1,w - 1,valor });
    }
    int inicio, p,numPaquetesCasa;
    vector<int> entregaPaquetes;
    cin >> inicio>>p;
    inicio--;
    for (int i = 0; i < p; i++)
    {
        cin >> numPaquetesCasa;
        entregaPaquetes.push_back(numPaquetesCasa - 1);
    }
  
    // escribir sol
	RepartoPaquetes sol(g, inicio);
	int resultado = sol.getTiempo(entregaPaquetes);
	(resultado == -1) ? cout << "Imposible" : cout << resultado;
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
