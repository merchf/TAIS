
// Mercedes Herrero Fernandez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, L;
    cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> agujeros(N);
    for (int i = 0; i < N; i++)
    {
        cin >> agujeros[i];
    }
    int parches = 1;
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (agujeros[i] - agujeros[j] > L) {
            parches++;
            j = i;
        }
    }
    // escribir sol
    cout << parches << '\n';
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
