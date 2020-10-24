
// Mercedes Herrero Fernandez
//TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
* Para ir obteniendo el minimo esfuerzo al sumar elementos la cola debe ir ordenada
* de menor a mayor, de forma que el elemento mas prioritario siempre sea menor que los siguientes elementos.
* Siguiendo esta regla, se debe ir recorriendo la cola consultando el elemento mas prioritario, guardarlo en una variable,
* eliminarlo de la cola y repitiendo el mismo proceso con el siguiente. De esta forma ya tenemos dos elementos para sumarlos, cuyo resultado
* lo añadiriamos al esfuerzo minimo almacenado. La suma de esos dos elementos habrá que volverla a introducir en la cola
* para cumplir el requisito del enunciado y tener en cuenta el esfuerzo que requiere cada suma.
* Esta operacion solo se realiza en el caso en que el tamaño de la cola sea mayor que uno, ya que si solo tiene un elemento
* el esfuerzo es 0.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
long long  resolver(PriorityQueue<long long> &cola) {
    //recorro la cola  siempre que su tamaño sea mayor que uno, si no el esfuerzo es 0
    long long  esfuerzoMin = 0,a,b;
    if (cola.size() > 1) {
        while (cola.size() > 1) {
            a = cola.top();
            cola.pop();
            b = cola.top();
            cola.pop();
            esfuerzoMin += a + b;
            if (!cola.empty()) {
                cola.push((a + b));
            }
        }
    }
    return esfuerzoMin;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int elems, dato;
    // leer los datos de la entrada
    cin >> elems;
    if (elems == 0)
        return false;
    PriorityQueue<long long> cola;
    for (int i = 0; i < elems; i++)
    {
        cin >> dato;
        cola.push(dato);
    }
    
    // escribir sol
    cout << resolver(cola) << endl;
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
