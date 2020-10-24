
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
En este problema hay que tener en cuenta dos requisitos para el orden de prioridad de las cajas, por un lado
el tiempo que la caja estara ocupada o por otro lado el numero de la caja, teniendo mas peso el tiempo de espera.
Para resolver el problema se asignara a la cola el numero asignado a cada caja, siendo el mas prioritario el menor numero de caja.
Segun el numero de clientes se ira asignando segundos a las cajas mas priotiritarias.
Para saber la caja resultante tendra que tener el minimo tiempo acumulado y el menor numero de caja, en caso de que coincidan los tiempos
*/


#include <iostream>
#include <fstream>
#include <iomanip>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

using namespace std;


struct tCaja
{
    int num;
    int tiempo;
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool operator<(tCaja const &a, tCaja const &b) {
    /*Sera primera la que menos tiempo este ocupada y si tienen el mismo tiempo
    la que menor num tenga*/
    if (a.tiempo < b.tiempo) return true;
    else if ((a.tiempo == b.tiempo) && a.num < b.num) return true;
    else return false;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, c,seg;
    cin >> n >> c;
    if (n == 0 && c == 0)
        return false;
    PriorityQueue<tCaja> cola;
    //i es el numero de la caja por lo q empieza en 1
    for (int i = 1; i <= n; i++)
    {
        cola.push({ i,0 });
    }
    //Se añade el tiempo que esta ocupada cada caja
    for (int i = 0; i < c; i++)
    {
        tCaja caja = cola.top();
        cin >> seg;
        caja.tiempo += seg;
        cola.pop();
        cola.push(caja);
    }
    // escribir sol
    cout << cola.top().num << '\n';

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
