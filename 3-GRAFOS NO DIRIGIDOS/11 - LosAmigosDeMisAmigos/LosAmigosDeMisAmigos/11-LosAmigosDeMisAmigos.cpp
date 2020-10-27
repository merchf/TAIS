
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
El grupo de amigos se representara con un grafo. Si dos personas son amigas
estaran unidas por una arista. Recorremos cual es el mayor siendo conexo.

*/
#include <iostream>
#include <fstream>
#include <vector>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(V+A)

class MaximaComponenteConexa {
private:
    int maximo;
    vector<bool> visitados;

    int dfs(const Grafo &g, int v) {
        visitados[v] = true;
        int tam = 1;
        for (int w: g.ady(v) ) {
            if (!visitados[w]) {
                tam += dfs(g, w);
            }
        }
        return tam;
    }
public:
    MaximaComponenteConexa(const Grafo& g) :visitados(g.V(), false), maximo(0) {
        for (int i = 0; i < g.V(); i++)
        {
            if (!visitados[i]) {
                int tam = dfs(g, i);
                maximo = max(maximo, tam);
            }
        }
    }
    int getMaximo() {
        return maximo;
    }
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n, m,a,b;
    // leer los datos de la entrada
    cin >> n >> m;
    Grafo g(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g.ponArista(a - 1, b - 1);
    }
    MaximaComponenteConexa sol(g);
    cout << sol.getMaximo() << '\n';

    // escribir solución
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
