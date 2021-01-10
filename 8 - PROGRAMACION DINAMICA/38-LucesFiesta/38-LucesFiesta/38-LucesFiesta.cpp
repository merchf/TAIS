
// Mercedes Herrero Fernandez   TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
using namespace std;
const int INF = 9999999;
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, pMax, pMin;
    cin >> n >> pMax >> pMin;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> potencia(n+1);
    vector<int> coste(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> potencia[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> coste[i];
    }

    //rellenamos la matriz
    Matriz<int> tabla(n+1, pMax+1, 0);

    for (int i = 0; i <= n; i++)
    {
        tabla[i][0] = 0;
    }
    for (int j = 0; j <= pMax; j++)
    {
        tabla[0][j] = INF;
    }

    for (int i = 1; i <= n; i++) {
        int potenciaActual = potencia[i];
        for (int j = 1; j <= pMax; j++)
        {
            if (j<potenciaActual) {//si bombilla es mayor que la que se mira
                tabla[i][j] = tabla[i - 1][j];//mismo coste
            }
            else {
                tabla[i][j] = min(tabla[i - 1][j], tabla[i][j - potenciaActual]+coste[i]);

            }
        }
    }

    // escribir sol
    //buscar la mas barata
    int min = INF;
    int pot = 0, i = pMin;
    while (i <= pMax) {
        if (tabla[n][i] < min) {
            min = tabla[n][i];
            pot = i;
        }
        i++;
    }
    (min != INF) ? cout << min << " " << pot << '\n' : cout << "IMPOSIBLE\n";
    

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
