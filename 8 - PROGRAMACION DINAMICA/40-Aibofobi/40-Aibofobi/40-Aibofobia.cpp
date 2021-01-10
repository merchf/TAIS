
// Mercedes Herrero Fernandez   TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    string palabra;
    cin >> palabra;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> tabla(palabra.size()+1,palabra.size()+1, 0);
    
    for (int s = 1; s <=palabra.size()-1; s++)
    {

        for (int i = 1; i <= palabra.size() - s; i++)
        {
            int j = i + s;
            if (palabra[i-1] == palabra[j-1]) {
                tabla[i][j] = tabla[i + 1][j-1];
            }
            else {
                tabla[i][j] =1+ std::min(tabla[i][j-1], tabla[i + 1][j]);
            }
        }
    }
    
    int letras = tabla[1][palabra.size()];
    int total = palabra.size() + letras;
    string palabraFinal(total, ' ');
    int i = 0, k = 0, j = palabra.size() - 1, t = total - 1;

    while (total > 0) {
        if (total == 1) {
            palabraFinal[t] = palabra[i];
            total--;
        }
        else if (palabra[i] == palabra[j]) {
            palabraFinal[k] = palabraFinal[t] = palabra[j];
            i++; k++; t--; j--;
            total -= 2;
        }
        else {
            if (tabla[i + 1][j] < tabla[i][j - 1]) {
                palabraFinal[k] = palabraFinal[t] = palabra[j];
                k++; t--; j--;
            }
            else {
                palabraFinal[k] = palabraFinal[t] = palabra[i];
                i++; k++; t--;
            }
            total -= 2;
        }
    }
    palabraFinal.substr(0, ' ');


    cout <<tabla[1][palabra.size()]<< " " << palabraFinal << "\n";
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
