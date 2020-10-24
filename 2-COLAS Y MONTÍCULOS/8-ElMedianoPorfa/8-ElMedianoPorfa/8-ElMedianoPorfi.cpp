
//Mercedes Herrero Fernandez
//Esther Peñas Martinez
//Jorge Velasco Conde

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h" 

using namespace std;


class ColaMedianas {
private:

    PriorityQueue<int,greater<int>> colaIzq; //menores que la mediana
    PriorityQueue<int,less<int>> colaDcha; // mayores que la mediana

    void reordenar(){
        if(abs(colaDcha.size() -colaIzq.size()) >1 || (!colaDcha.empty() && colaIzq.empty())){
            if(colaDcha.size() > colaIzq.size()){
                colaIzq.push(colaDcha.top());
                colaDcha.pop();
            }
            else {
                colaDcha.push(colaIzq.top());
                colaIzq.pop();
            }
        }
    }

public:
    
    ColaMedianas(): colaIzq(), colaDcha(){};
    ~ ColaMedianas() {};

    void insertar(int x) {
        if (colaIzq.empty()) {
            colaIzq.push(x);
        }
        else {
            if (x < colaIzq.top()) {
                colaIzq.push(x);
            }
            else {
                colaDcha.push(x);
            }
            
            reordenar();
        }
    }

    bool vacia() const {
        return colaDcha.empty() && colaIzq.empty();
    }

    int mediana() const {
        if(vacia()) // si no tengo elementos salta excepcion
            throw domain_error("ECSA");
        else {
            return colaDcha.size() > colaIzq.size() ? colaDcha.top() : colaIzq.top();
        }
    }

    void quitarMediana() {
        if (!vacia()) {
            if (colaDcha.size() > colaIzq.size()) {
                colaDcha.pop();
            }
            else {
                colaIzq.pop();
            }
            reordenar();
        }
    }

};


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    ColaMedianas cola;
    int dato;
    for (int i = 0; i < N; i++)
    {
        cin >> dato;
        if (dato != 0) {
            cola.insertar(dato);
        }
        else {//el carnicero pregunta por la mediana
            try{
                std::cout << cola.mediana() << " ";
                cola.quitarMediana();
            }
            catch(domain_error & e){
                std::cout << e.what()<< " ";
            }
        }
    }

    std::cout << "\n";

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
