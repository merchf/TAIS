
// Esther Peñas Martinez 59
// Mercedes Herrero Fernandez 40
// Natalia Rodríguez-Peral Valiente 67
// Jorge Velasco Conde 87

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema

class ColocarGuardias {
private:
    vector<bool> visitados;
    vector<bool> coloresGuardias;
    int guardias;
    int blanco;
    int negro;
    bool posible;

    bool dfs(const Grafo& g, int v) {
        visitados[v] = true;
        for (int w : g.ady(v)) {
            if (!visitados[w]) {
                coloresGuardias[w] = !coloresGuardias[v];
                if (coloresGuardias[w]) {
                    blanco++;
                }
                else {
                   negro++;
                }
                if (!dfs(g, w)) return false;
            }
            else{
                if (coloresGuardias[w] == coloresGuardias[v]) {
                     return false;
                 }
            }
        }
        return true;
    }


    //color blanco 0 (guardia blanco)
    //color negro 1 (guardia negro)
public:
    ColocarGuardias(Grafo const& g) : visitados(g.V(), false), coloresGuardias(g.V()),guardias(0), negro(1),blanco(0), posible(true) {
       for (int v = 0; v < g.V() && posible; ++v) {
           if (!visitados[v]) {
               posible = dfs(g, v);
               guardias += std::min(blanco, negro);
               negro = 1; blanco = 0;
            }
        }
    }

    int minimo(){
        return guardias;
    }

    bool esPosible(){
        return posible;
    }
};


// resuelve un caso de prueba, leyendo de la entrada configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int cruces, calles;
    cin >> cruces;
    if (!std::cin)  // fin de la entrada
        return false;

    cin >> calles;

    //Grafo: V=cruces A=calles
    Grafo guardias(cruces);
    int v, w;
    for(int i=0;i<calles;i++){
        cin >> v >> w;
        guardias.ponArista(v-1, w-1);

    }

    //Crear objeto de la clase:
    ColocarGuardias cg(guardias);

    // escribir sol
     cg.esPosible() ? cout << cg.minimo() : cout << "IMPOSIBLE";

    cout << "\n";
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
