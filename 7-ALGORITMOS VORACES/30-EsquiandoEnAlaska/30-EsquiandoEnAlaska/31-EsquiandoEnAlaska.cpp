
// Mercedes Herrero Fernandez TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==0)
        return false;
    vector<int> alturas(n);
    vector<int> esquis(n);
    for (int i = 0; i < n; i++)
    {
        cin >> alturas[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> esquis[i];
    }
    int minSuma = 0;
    sort(alturas.begin(), alturas.end());
    sort(esquis.begin(), esquis.end());
    // escribir sol
    for (int i = 0; i < n; i++)
    {
        minSuma += abs(alturas[i] - esquis[i]);
    }
    cout << minSuma << '\n';
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
