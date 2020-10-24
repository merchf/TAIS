
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
En este problema tenemos que diferenciar entre los dos tipos de tareas que existen:
-Tarea unica, se comprobara si el tiempo en el q se realiza la tarea se solapa y se eliminara de la cola una vez comprobado
-Tareas periodicas, se comprobara si solapa con otras y de no ser asi se sumara a su tiempo inicial y final el tiempo de periocidad, para volver a añadirla
a la cola con los tiempos actualizados.

Para ver que no solapan las tareas se almacenara la tarea anterior y se comparara con la actual. En el momento en que el tiempo final de la tarea anterior sea 
superior al tiempo inicial de la tarea actual pareremos de comprobar el resto de tareas ya que habrá un solapamiento. 

*/

#include <iostream>
#include <fstream>
#include <iomanip>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

using namespace std;

struct  tTarea{
    int ini;
    int fin;
    int periodo; // si -1 es tarea unica
};

bool operator<(tTarea const & a, tTarea const & b) {
    if (a.ini < b.ini)return true;
    else if (a.ini == b.ini && a.fin < b.fin) return true;
    else return false;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(PriorityQueue<tTarea>& cola, int t) {
    bool sol = false;
    int inicio = 0, tarea = 0;
    while(!sol && inicio < t && !cola.empty()){
        tTarea actual = cola.top();
        cola.pop();
        if (actual.ini < tarea && actual.ini < t) {
            sol = true;
        }
        else {
            inicio = actual.ini;
            tarea = actual.fin;
            if (actual.periodo != -1) { // si es repetitiva tengo que actualizar el nuevo ini y fin
                actual.ini += actual.periodo;
                actual.fin += actual.periodo;
                cola.push(actual);
            }
        }
    }
    return sol;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    /*
    n->tareas unicas
    m_> tareas periodicas
    t-> tiempo para ver si hay conflictos
    */
    // leer los datos de la entrada
    int n, m, t;
    cin >> n >> m >> t;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<tTarea> cola;
    for (int i = 0; i < n; i++){
        tTarea tareaUni;
        cin >> tareaUni.ini >> tareaUni.fin;
        tareaUni.periodo = -1;// es unica, no tiene periodo
        cola.push(tareaUni);
    }
    for (int i = 0; i < m; i++){
        tTarea tareaRep;
        cin >> tareaRep.ini >> tareaRep.fin >> tareaRep.periodo;
        cola.push(tareaRep);
    }
    
    // escribir sol
    cout << (resolver(cola, t)? "SI" : "NO") << '\n';
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
