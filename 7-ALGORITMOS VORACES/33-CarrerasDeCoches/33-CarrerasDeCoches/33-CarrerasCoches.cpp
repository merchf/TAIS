
// Mercedes Herrero Fernandez   TAIS40
// Esther Peñas Martinez TAIS59
// Jorge Velasco Conde TAIS87
// Natalia Rodríguez-Peral Valiente TAIS67

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int N, V;
    cin >> N >> V;
   
    vector<int> v(N);//vector con los voltajes de cada pila
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(),v.end(),greater<int>());//ordenamos el vector de mayor a menor
    int maxCoches = 0;
    int ini = 0;//inicio del vector
    int fin = N - 1;//final del vector

    while(ini<fin){
    //si la suma entre la pila de mayor voltaje y la pila de menor voltaje es mayor o igual que el voltaje minimo necesario
        if (v[ini] + v[fin] >= V){
            maxCoches++;
            ini++;//quitas la grande
        }
        fin--;//quitas la pequeña
    }
  
    // escribir sol
    cout << maxCoches << '\n';
  
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
