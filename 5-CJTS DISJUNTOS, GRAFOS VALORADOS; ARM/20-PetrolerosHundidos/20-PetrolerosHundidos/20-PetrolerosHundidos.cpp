
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase
using namespace std;

struct tDirecciones {
    int i;
    int j;
};

const tDirecciones dir[] = { {-1,0},{0,-1},{-1,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };

class PetroleroHundido {
private:
    int f, c, maxMancha;
    ConjuntosDisjuntos grafo;
    vector<vector<bool>> visitados; //doble para ver si ha visitado i,j


    bool correcto(int i, int j) {
        return i < f&& i >= 0 && j < c&& j >= 0;
    }
    void dfs(vector<string> const& matriz, int i, int j, int& tam) {
        visitados[i][j] = true;
        tam++;
        for (auto d : dir) {
            int v = i * c + j;
            int siguienteI = i + d.i;
            int siguienteJ = j + d.j;
            if (correcto(siguienteI, siguienteJ) && matriz[siguienteI][siguienteJ] == '#' && !visitados[siguienteI][siguienteJ]) {
                int w = siguienteI * c + siguienteJ;
                grafo.unir(v, w);
                dfs(matriz, siguienteI, siguienteJ, tam);
            }
        }
    }
public:
    PetroleroHundido(vector<string> const& m) : f(m.size()), c(m[0].size()),visitados(f,vector<bool> (c,false)),grafo(f*c),maxMancha(0) {
        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (m[i][j] == '#' && !visitados[i][j]) {
                    int newTam = 0;
                    dfs(m, i, j, newTam);
                    maxMancha = max(maxMancha, newTam);
                }
            }
        }
    }
    int maximaMancha() {
        return maxMancha;
    }
    void controlarManchas(vector<string> const& m, int i, int j) {
       
        bool vacio = true;
        int v = i * c + j;
        for (auto d : dir) {
            int siguienteI = i + d.i;
            int siguienteJ = j + d.j;
            if (correcto(siguienteI, siguienteJ) && m[siguienteI][siguienteJ] == '#') {
                int w = siguienteI * c + siguienteJ;
                grafo.unir(v, w);
                maxMancha = max(maxMancha, grafo.cardinal(v));
                vacio = false;
            }
        }
        if (vacio) {
            maxMancha = max(maxMancha, grafo.cardinal(v));
        }
    }
};


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int f, c;
    cin >> f >> c;
    if (!std::cin)  // fin de la entrada
        return false;
    //todas las posibles direcciones:

    vector<string> m(f);
    std::cin.ignore(1,'\n');
    for (string& line : m) {
        getline(cin, line);
    }

    //montamos el conjunto
    PetroleroHundido p(m);
    cout << p.maximaMancha();
    int imagenesAdicionales;
    cin >> imagenesAdicionales;
    for (int a = 0; a < imagenesAdicionales ;a++)
    {
        int i, j;
        cin >> i >> j;
        i--; j--;
        m[i][j] = '#';
        p.controlarManchas(m, i, j);
        cout << " " << p.maximaMancha();
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
