
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(V+E)
class CamionReparto {
private:
    vector<bool> visitado;

    void dfs(GrafoValorado<int> const& g, int v, int anchura) {
        visitado[v] = true;
        for (auto w: g.ady(v)){
            if (!visitado[w.otro(v)] && w.valor() >= anchura) {
                dfs(g, w.otro(v), anchura);
            }
        }
    }
public:
    CamionReparto(GrafoValorado<int> const& grafo, int v, int ancho): visitado(grafo.V(),false) {
        dfs(grafo, v, ancho);
    }
    bool existeCamino(int w) {
        return visitado[w];
    }
};


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int V, E, inicio, fin, anchuraMax;
    cin >> V;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> E;
    GrafoValorado<int> grafo(V);
    for (int i = 0; i < E; i++)
    {
        cin >> inicio>> fin >> anchuraMax;
        grafo.ponArista({inicio-1,fin-1,anchuraMax});
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> inicio>> fin >> anchuraMax;
        CamionReparto sol(grafo, inicio - 1, anchuraMax);
        (sol.existeCamino(fin - 1)) ? cout << "SI\n" : cout << "NO\n";
    }
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
