
// GRUPO 14
/*
Jorge Velasco Conde
Esther Pe�as Mart�nez
Natalia Rodr�guez-Peral Valiente
Mercedes Herrero Fernandez
*/


// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

using namespace std;
// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
/*Solucion resolver(Datos datos) {
    ...
}*/

// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numElems, dato, elemConsultar,k;
    cin >> numElems;
    if (numElems == 0)
        return false;

    Set<int> arbol;
    for (int i = 0; i < numElems; i++)
    {
        cin >> dato;
        arbol.insert({ dato });
    }

    cin >> elemConsultar;
    for(int i = 0; i < elemConsultar; ++i){
        cin >> k;
        try {
            cout << arbol.dokesimo(k) << endl;
        }
        catch (domain_error& e) {
            cout << "??" << endl;
        }
    }
    cout << "---" << endl;

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
