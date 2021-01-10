
// Mercedes Herrero Fernandez TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct tEdificio {
    int oeste;
    int este;
};
bool operator< (const tEdificio &a, const tEdificio &b) {
    return(a.este < b.este) || (a.este == b.este && a.oeste < b.oeste);
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==0)
        return false;

    vector<tEdificio> v(n);
    for (int i = 0; i < n; i++)
    {
        tEdificio edificio;
        cin >> edificio.oeste >> edificio.este;
        v[i] = edificio;
    }
    // escribir sol
    sort(v.begin(), v.end());
    tEdificio anterior = v[0];
    int pasadizos = 1;
    for (int i = 1; i < n; i++)
    {
        tEdificio actual = v[i];
        if (actual.oeste >= anterior.este) {
            anterior = actual;
            pasadizos++;
        }
    }
    cout << pasadizos << '\n';
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
