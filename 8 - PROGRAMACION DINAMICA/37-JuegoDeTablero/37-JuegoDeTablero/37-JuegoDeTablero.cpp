
// Mercedes Herrero Fernandez   TAIS40
// Esther Peñas Martínez TAIS59
// Natalia Rodríguez-Peral Valiente TAIS67
// Jorge Velasco Conde   TAIS87


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
using namespace std;


const vector<pair<int, int>> dirs = { {-1,-1},{-1,0},{-1,1} };
//coste N+1*N+1 
bool resuelveCaso() {
    int N;
    cin >> N;
    if (!std::cin) 
        return false;
    Matriz<int> tablero(N+1, N+1);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
        {
            cin >> tablero[i][j];
        }
    }
	Matriz<int> mTabla(N + 1, N +1, 0);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int maximo = 0;

			for (auto d : dirs) //hago esto para averiguar el maximo de las casillas a las que puedo avanzar (vertical o dos diagonales)
			{
				int dx = i + d.first;
				int dy = j + d.second;
				if (mTabla.posCorrecta(dx, dy))
					maximo = max(maximo, mTabla[dx][dy]);
			}
			mTabla[i][j] = tablero[i][j] + maximo;
		}
	}

	int maxValor = 0;
	int col = 0;
	for (int j = 1; j <= N; j++)
	{
		if (mTabla[N][j] > maxValor) //empezamos siempre por la ultima fila
		{
			maxValor = mTabla[N][j];
			col = j;
		}
	}
	cout << maxValor << " " << col << '\n';

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
