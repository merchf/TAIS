
//Mercedes Herrero Fernandez TAIS40
//Jorge Velasco Conde TAIS87
//Esther Peñas Martínez TAIS59
//Natalia Rodríguez-Peral Valiente TAIS67

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// función que resuelve el problema
// Coste total del algoritmo voraz, O(NlogN), donde N será el número de peliculas que se van a proyectar

struct tPeli {
    int ini;
    int fin; //el inicio más la duracion de la pelicula
};

bool operator< (const tPeli& a,const tPeli& b) {
    return (a.fin < b.fin) || (a.fin == b.fin && a.ini < b.ini);
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int  N;
    cin >> N;
    if (N == 0)
        return false;

    vector<tPeli> v(N);
    for (int i = 0; i < N; i++)
    {
        tPeli peli;
        int hora, min, duracion;
        cin >> hora;
        cin.ignore(); //para evitar :
        cin >> min >> duracion;
       
        peli.ini = hora * 60 + min; //Pasar a minutos la hora
        peli.fin = peli.ini + duracion;
        v[i] = peli;
    }

    //ordenamos las peliculas de menor a mayor
    sort(v.begin(), v.end());

    //siempre se verá al menos una peli
    int totalPelis = 1;
    tPeli anterior = v[0];
    for (int i = 1; i < N; i++)//O(N)
    {
        tPeli actual = v[i];
        if (actual.ini >= anterior.fin + 10) {//no la pisa entonces sumo
            totalPelis++;
            anterior = actual;
        }
    }

    // escribir sol
    cout << totalPelis << '\n';

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
