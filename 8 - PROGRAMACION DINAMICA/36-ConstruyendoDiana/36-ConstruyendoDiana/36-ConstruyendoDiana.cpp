
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


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int valor, s;
    cin >> valor >> s;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> v(s+1);
    for (int i = 1; i <= s; i++)
    {
        cin >> v[i];
    }
    
    int n = v.size()-1;
    Matriz<EntInf> m(n + 2, valor + 1, Infinito);
  
    for (int i = 1; i <= n; i++)
    {
        m[i][0] = 0;
    }
    for(int i =n;i>=1;i--){
        for (int j = 1; j <= valor; j++)
        {
            if (v[i]<= j) {
                m[i][j] = min(m[i +1][j], m[i][j - v[i]] + 1);
            }
        }
    }
   

    // escribir sol
    if (m[1][valor] == Infinito) {
        cout << "Imposible\n";
    }
    else {
        vector<int> sol;
        if (m[n][valor] != Infinito) {
            int i = n, j = valor;
            while (j > 0) {
                if (v[i - 1] <= j && m[i][j] != m[i - 1][j]) {
                    sol.push_back(v[i - 1]);
                    j = j - v[i - 1];
                }
                else {
                    --i;
                }
            }
        }
        cout << m[1][valor] << ": ";
        for (int i = 0; i < sol.size(); i++)
        {
            cout << sol[i] << " ";
        }
        cout << '\n';
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
