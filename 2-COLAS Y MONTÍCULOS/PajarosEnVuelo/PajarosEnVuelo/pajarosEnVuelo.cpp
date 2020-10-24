
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    /*
    Al empezar quien esta en el vertice es el primero(variable edad) luego hay que ir modificando la v segun la condicon de ser mayores o menores
    Por lo que la variable edad guardara siempre el vertice*/
    // leer los datos de la entrada
    int edad, numParejas;
    cin >> edad >>numParejas;
    if (edad == 0 && numParejas ==0)
        return false;

    PriorityQueue<int, greater<>> izq;
    PriorityQueue<int> dcha;

    for (int i = 0; i < numParejas; i++)
    {
        int uno, dos;
        cin >> uno >> dos;
        //Veo el primer pajaro y comparo con el que estaba en el vertice
        if (uno >= edad) {
            dcha.push(uno);
        }
        else {
            izq.push(uno);
        }
        //miramos el segundo pajaro y lo mismo
        if (dos >= edad) {
            dcha.push(dos);
        }
        else {
            izq.push(dos);
        }
        //quien tenga mayor tam se seca al vertice el top y se guarda el antiguo vertice en el que tenga menor tam
        if (dcha.size() > izq.size()) {
            izq.push(edad);
            edad = dcha.top();
            dcha.pop();
        }
        else if (izq.size() > dcha.size()) {
            dcha.push(edad);
            edad = izq.top();
            izq.pop();
        }

        cout << edad << " ";
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
