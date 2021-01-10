
// Mercedes Herrero Fernandez   TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
using namespace std;

const int INF = 9999999;
void Floyd(Matriz<int> const& G, Matriz<int>& C, Matriz<int>& A) {
    int V = G.numfils(); // número de vértices de G
    // inicialización
    C = G;
    A = Matriz<int>(V, V, 0);
    // actualizaciones de las matrices
    for (int k = 1; k < V; ++k) {
        for (int i = 1; i < V; ++i) {
            for (int j = 1; j < V; ++j) {
                auto temp = C[i][k] + C[k][j];
                if (temp < C[i][j]) { // es mejor pasar por k
                    C[i][j] = temp;
                    A[i][j] = k;
                }
            }
        }
    }
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int p, r;
    cin >> p >> r;
    if (!std::cin)  // fin de la entrada
        return false;
    unordered_map<string, int> mapPersonas;
    string p1, p2;
    Matriz<int> uniones(p + 1, p + 1, INF);
    for (int i = 0; i <=p; i++)
    {
        uniones[i][i] = 0;
    }
    int cont = 1;
    for (int i = 0; i < r; i++)
    {
        cin >> p1 >> p2;
        if (mapPersonas[p1] == 0) {
            mapPersonas[p1] = cont;
            cont++;
        }
        if (mapPersonas[p2] == 0) {
            mapPersonas[p2] = cont;
            cont++;
        }
        //relacion amistad ida y vuelta
        uniones[mapPersonas[p1]][mapPersonas[p2]] = 1;
        uniones[mapPersonas[p2]][mapPersonas[p1]] = 1;
    }
    Matriz<int> C(0, 0); Matriz<int> A(0, 0);
    Floyd(uniones, C, A);
    // escribir sol
    int max = 0;

    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) {
            max = std::max(max, C[i][j]);
        }
    }

    if (max == INF) std::cout << "DESCONECTADA\n";
    else std::cout << max << "\n";
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
