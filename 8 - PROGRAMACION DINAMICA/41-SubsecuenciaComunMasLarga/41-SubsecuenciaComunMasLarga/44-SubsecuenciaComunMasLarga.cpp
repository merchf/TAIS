
// Mercedes Herrero Fernandez   TAIS40
// Esther Peñas Martinez TAIS59
// Natalia Rodríguez-Peral Valiente TAIS67
// Jorge Velasco Conde TAIS87

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include "Matriz.h"  // propios o los de las estructuras de datos de clase
using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    string x, y;
    cin >> x >> y;
    if (!std::cin)  // fin de la entrada
        return false;

    //rellenamos la matriz
    Matriz<int> tabla(x.size() + 1, y.size() + 1, 0);
    for (int i = 1; i <= x.size(); i++) {
        for (int j = 1; j <= y.size(); j++)
        {
            if (x.at(i - 1) == y.at(j - 1)) {
                tabla[i][j] = tabla[i - 1][j - 1] + 1;
            }
            else {
                tabla[i][j] = max(tabla[i - 1][j], tabla[i][j - 1]);

            }
        }
    }
  

    //recuperar la solucion
    stack<char> pila;
    int i = x.size(), j = y.size();
    while (i != 0 && j != 0) {
        if (x.at(i-1) == y.at(j-1)) {
            pila.push(x.at(i-1));
            i--;
            j--;
        }
        else if (tabla[i-1][j] > tabla[i][j-1] ) {
            i--;
        }
        else {
            j--;
        }
    }
    // escribir sol
    while (!pila.empty()) {
        cout << pila.top();
        pila.pop();
    }
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
