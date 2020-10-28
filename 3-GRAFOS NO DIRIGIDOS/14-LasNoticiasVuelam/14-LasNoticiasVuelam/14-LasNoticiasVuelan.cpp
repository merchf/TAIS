
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
class Noticias {
private:
    vector<bool> visitados;
    vector<int> amigos;
    vector<bool> marcados;
    int numAmigos;

    void dfs(const Grafo& g, int v) {
        visitados[v] = true;

        for (int w : g.ady(v)) {
            if (!visitados[w]) {
                numAmigos++;
                dfs(g, w);
            }
        }
    }
    void guardarAmigos() {
        for (int i = 0; i < visitados.size(); i++)
        {
            if (visitados[i]&& !marcados[i]) {
                amigos[i] = numAmigos;
                marcados[i] = true;
            }
        }
    }

public:
    Noticias(Grafo const& g) :visitados(g.V(), false),numAmigos(0),amigos(g.V(),0), marcados(g.V(), false) {
        for (int i = 0; i < g.V(); i++)
        {

            if (!visitados[i]) {
                numAmigos = 1;
                dfs(g, i);
                guardarAmigos();
            }
        }
    }
    vector<int> getAmigos() {
        return amigos;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int usuarios, grupos;
    cin >> usuarios;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> grupos;
    Grafo g(usuarios);
    for (int i = 0; i < grupos; i++)
    {
        cin >> usuarios;
        int v = -1;
        int w;
        for (int j = 0; j < usuarios; j++)
        {
            cin >> w;
            if (v > 0) {
                g.ponArista(v - 1, w - 1);
            }
            v = w;
        }
    }
    Noticias sol(g);
    for (int i : sol.getAmigos()) {
        cout << i << " ";
    }
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
