
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numDrones, A, B, dato;
    cin >> numDrones >> A >> B;
    if (!std::cin)  // fin de la entrada
        return false;
    PriorityQueue<int, greater<>> colaA;
    PriorityQueue<int, greater<>> colaB;
    for (int i = 0; i < A; i++)
    {
        cin >> dato;
        colaA.push(dato);
    }
    for (int i = 0; i < B; i++)
    {
        cin >> dato;
        colaB.push(dato);
    }

    // escribir sol

    while (!colaA.empty() && !colaB.empty()) {
        int horasVuelo = 0;
        int cont = 0;
        vector<int> pilasUsadasA, pilasUsadasB; // hay que ir almacenando las usadas para evitar volverlas a coger
        while (!colaA.empty() && !colaB.empty() && cont < numDrones) {
            int cargaPilaA = colaA.top();
            colaA.pop();
            int cargaPilaB = colaB.top();
            colaB.pop();
            // estará volando el tiempo de la pila que menos carga tenga
            int min = std::min(cargaPilaA, cargaPilaB);
            horasVuelo += min;
            // restamos el tiempo que ha estado volando a las cargas de las pilas
            cargaPilaA -= min;
            cargaPilaB -= min;
            if (cargaPilaA != 0) {
                pilasUsadasA.push_back(cargaPilaA);
            }
            if (cargaPilaB != 0) {
                pilasUsadasB.push_back(cargaPilaB);
            }
            cont++;
        }
        /*una vez volvemos a club guardamos las pilas que aun tienen carga */
        for (int i = 0; i < pilasUsadasA.size(); i++)
        {
            colaA.push(pilasUsadasA[i]);
        }
        for (int i = 0; i < pilasUsadasB.size(); i++)
        {
            colaB.push(pilasUsadasB[i]);
        }

        cout << horasVuelo << " ";
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
