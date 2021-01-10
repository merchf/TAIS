
// Mercedes Herrero Fernandez   TAIS40

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
using namespace std;

struct tDatosCofre{
    int profuncidad;
    int oro;
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int T, N;//t =segundos que puedo estar bajo el agua, n=num cofres
    cin >> T >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<tDatosCofre> cofres(N + 1);
    for (int i = 1; i <=N; i++)
    {
        cin >> cofres[i].profuncidad >> cofres[i].oro;
    }

    Matriz<int> tabla(N + 1, T + 1, 0);
    /*el tiempo de descenso a una profundidad p es de p segundos
    mientras que el tiempo de ascenso es de 2p segundos. TOTAL DE 3*PROFUNDIDAD
    */
    for (int i = 1; i <=N; i++)
    {
        tDatosCofre cofreActual = cofres[i];
        int oxigenoVital = 3 * cofreActual.profuncidad;
        for (int j = 1; j <=T; j++)//tiempos oxigenos
        {
            if (j < oxigenoVital) {
                tabla[i][j] = tabla[i - 1][j]; 
            }
            else {
                tabla[i][j] = std::max(tabla[i - 1][j], (tabla[i - 1][j - oxigenoVital] + cofreActual.oro));
            }
        }
    }
    //sol = linea cantidad oro a recoger, linea num cofrea recoger, linea cada info del cofre recogido
    cout << tabla[N][T] << '\n';//oro recogido
    int i = N, j = T;
    vector<tDatosCofre> recogidos;
    while (i > 0) {
        tDatosCofre d = cofres[i];
        int oxigenoVital = 3 * d.profuncidad;

        if (tabla[i][j] != tabla[i - 1][j]) {// ese cofre se coge
            recogidos.push_back(d);
            i--;
            j -= oxigenoVital;
        }
        else {
            i--;
        }
    }
    cout << recogidos.size() << '\n';// num cofres cogidos
    for (int i = recogidos.size()-1; i >=0 ; i--)
    {
        cout << recogidos[i].profuncidad << " " << recogidos[i].oro << '\n';
    }
    cout << "---\n";
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
