
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "treeSet_AVL.h"  // propios o los de las estructuras de datos de clase
using namespace std;


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int elems,dato,k1,k2;
    cin >> elems;
    if (elems !=0)
        return false;
    Set<int> arbol;
    for (int i = 0; i < elems; i++)
    {
        cin >> dato;
        arbol.insert(dato);
    }
    cin >> k1 >> k2;
    vector<int> sol;
    arbol.rangoClaves(k1, k2, sol);

    // escribir sol
    for(int var : sol)
    {
        cout << var << " ";
    }
    cout << endl;

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
