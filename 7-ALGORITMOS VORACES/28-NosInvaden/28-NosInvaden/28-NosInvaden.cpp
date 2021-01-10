
// Mercedes Herrero Fernandez   TAIS40

// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> ciudadesInvadidas(N);
    vector<int> equiposDefensa(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ciudadesInvadidas[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> equiposDefensa[i];
    }

    sort(ciudadesInvadidas.begin(), ciudadesInvadidas.end());
    sort(equiposDefensa.begin(), equiposDefensa.end());


    int i=0,j=0, ciudadesVictoria = 0;
    while (i < N && j < N) {
        if (equiposDefensa[i] >= ciudadesInvadidas[j]) {
            j++;
            ciudadesVictoria++;
        }
        i++;

    }
    
    // escribir sol
    cout << ciudadesVictoria << '\n';
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
