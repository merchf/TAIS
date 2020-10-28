
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <deque>
#include <vector>

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class OrdenTopologico {
private:
    vector<bool> visitados;
    vector<bool> ant;
    deque<int> orden;
    bool ciclos;

    void dfs(Digrafo const & g, int v) {//V+A
        visitados[v] = true;
        ant[v] = true;
        for (int w : g.ady(v)){
            if (!visitados[w]) {
                dfs(g, w);
            }
            if (ant[w]) {
                ciclos = true;
            }
        }
        orden.push_front(v);
        ant[v] = false;
        
        
    }
public:
    OrdenTopologico(Digrafo const& g) :visitados(g.V(), false),ant(g.V(),false), ciclos(false) {
        
        for (int v = 0; v < g.V() && !ciclos; v++)
        {
            if (!visitados[v]) {
               dfs(g, v);
            }
        }
    }
    deque<int> const& getOrden()  {
        return orden;
    }
    bool hayCiclos() {
        return ciclos;
    }

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int tareas,relaciones;
    cin >> tareas;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> relaciones;
    Digrafo g(tareas);
    int v, w;
    for (int i = 0; i < relaciones; i++)
    {
        cin >> v >> w;
        g.ponArista(v-1, w-1);
    }
    OrdenTopologico sol(g);

    // escribir sol
    deque<int> orden = sol.getOrden();

    if(sol.hayCiclos()){
        cout << "Imposible";
    }
    else {
        while (!orden.empty()) {
            std::cout << orden.front() + 1 << " ";
            orden.pop_front();
        }
    }
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
