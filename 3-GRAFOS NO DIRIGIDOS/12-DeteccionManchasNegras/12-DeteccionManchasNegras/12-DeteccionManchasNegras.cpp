
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
using Mapa = vector<string>;
class Manchas {
private:
    int f, c;
    vector<vector<bool>> visitados; //visitado[i][j] es un pixel
    int num;
    int max;

    bool correcto(int i, int j) const {//para que no se salga del mapa
        return 0 <= i && i < f && 0 <= j && j < c;
    }
    const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };
    int dfs(const Mapa& m, int i, int j) {
        visitados[i][j] = true;
        int tam = 1;
        for (auto d : dirs) {
            int ni = i + d.first, nj = j + d.second;
            if (correcto(ni, nj) && m[ni][nj] == '#' && !visitados[ni][nj]) {
                tam += dfs(m, ni, nj);
            }
        }
        return tam;
    }
public:
    Manchas(Mapa const& m) :f(m.size()),c(m[0].size()),visitados(f,vector<bool>(c,false)), num(0),max(0){
        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (!visitados[i][j] && m[i][j] == '#') {//hay mancha
                    num++;
                    int nuevoMax = dfs(m, i, j);
                    max = std::max(max, nuevoMax);
                }
            }
        }
    }
    int numero() { return num; }
    int maximo() { return max; }
};


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {//O(f*c)

    // leer los datos de la entrada
    int f, c;
    cin >> f >> c;
    if (!std::cin)  // fin de la entrada
        return false;
    Mapa g(f);
    for (string& l : g) {
        cin >> l;
    }

    // escribir sol
    Manchas m(g);
    cout << m.numero() << " " << m.maximo() << '\n';
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
