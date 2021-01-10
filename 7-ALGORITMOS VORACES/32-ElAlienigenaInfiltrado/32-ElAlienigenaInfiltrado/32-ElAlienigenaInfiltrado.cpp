
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

struct tIntervalo {
    long int ini;
    long int fin;
};
bool operator< (const tIntervalo& a, const tIntervalo& b) {
    return (a.ini < b.ini ||(a.ini == b.ini && a.fin>b.fin));
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    long int c,f,n;
    cin>>c>>f >> n;
    if (c==0 && f==0 && n == 0)
        return false;

    vector<tIntervalo> v(n);
    for (long int i = 0; i < n; i++)
    {
        tIntervalo trabajo;
        cin >> trabajo.ini >> trabajo.fin;
        v[i] = trabajo;
    }
    // escribir sol
    sort(v.begin(), v.end());
    
    long int trabajos = 0;
    bool posible = true;
    long int  finalIntervalo = c;
    long  int i = 0;
    while (i < n && finalIntervalo < f && posible)
    {
        long int maxFinal = -1;
        tIntervalo tarea = v[i];
        for (; i < n && tarea.ini <= finalIntervalo && maxFinal<f; i++)
        {
            maxFinal = max(maxFinal, tarea.fin);
            tarea = v[i];
        }
        if (maxFinal == -1) { posible = false; }
        else { 
            finalIntervalo = maxFinal; 
            trabajos++;
        }
        
    }
    posible = (posible ? finalIntervalo >= f : posible );


    (posible) ? cout << trabajos << '\n' : cout <<"Imposible\n";
    
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
