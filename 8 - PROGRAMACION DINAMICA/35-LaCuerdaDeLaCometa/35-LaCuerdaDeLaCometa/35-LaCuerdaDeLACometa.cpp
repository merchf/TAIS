
// Mercedes Herrero Fernandez   TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
#include "EnterosInf.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct tDato {
    int longitud;
    int coste;
};

EntInf resolver(vector<tDato> const& v, int lon) {
    int n = v.size();
    Matriz<EntInf> m(n + 1, lon + 1, Infinito);
    m[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        m[i][0] = 0;
        for (int j = 1; j <= lon; j++)
        {
            if (v[i - 1].longitud > j) {
                m[i][j] = m[i - 1][j];
            }
            else {
                m[i][j] = min(m[i - 1][j],m[i][j-v[i-1].longitud]+1);
            }
        }
    }
    return m[n][lon];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, l;
    cin >> n >> l;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<tDato> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].longitud >> v[i].coste;
    }
    EntInf sol = resolver(v,l);

    // escribir sol
    if (sol == 0) {
        cout << "NO\n";
    }
    else {
        cout << sol << '\n';
    }
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
