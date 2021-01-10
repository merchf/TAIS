
// Mercedes Herrero Fernandez TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
El problema se basa en saber si ya hemos utilizado a algun amigo o hay que introducir uno nuevo. Por que no pueda ir yo a una actividad no significa 
que siempre tenga que meter a un amigo nuevo. Por ello utilizo una cola en la que voy actualizando los amigos que he ido usando para las conferencias.
Si no puedo ir yo primero compruebo que tenga algun amigo si esta libre le asigno la conferencia a el  si no meto un amigo nuevo y se sumaria los compis que necesito. 

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

struct tActividad {
    int ini;
    int fin;
};


bool operator<(const tActividad& a, const tActividad& b) {
    return (a.ini < b.ini) || (a.ini == b.ini && a.fin < b.fin);
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<tActividad> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].ini >> v[i].fin;
    }
    sort(v.begin(), v.end());
    int amigos = 0;
    tActividad miActividad = v[0];
    PriorityQueue<tActividad> compis;
    for (int i = 1; i < v.size(); i++)
    {
        tActividad siguiente = v[i];
        if (miActividad.fin > siguiente.ini) { // se solapan y yo no podria ir 
            //ahora tengo que ver si algun compi esta libre o tengo que usar uno nuevo
            if (compis.empty() || compis.top().fin >= siguiente.ini) {
                compis.push(siguiente);
            }
            else { // Puede ir un compi que ya ha terminado la anterior
                compis.pop();
                compis.push(siguiente);
            }
        }
        else { // me da tiempo a ir yo
            miActividad = siguiente;
        } 
        amigos = max(amigos, compis.size());
    }
    // escribir sol
    cout << amigos << '\n';
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
