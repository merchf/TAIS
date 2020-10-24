
// EJERCICIO GRUPO

/*
Esther Peñas Martínez - 59
Mercedes Herrero Fernández - 40
Jorge Velasco Conde - 87
Natalia Rodríguez - Peral Valiente - 67
*/

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
El arbol tiene que cumplir dos requisitos:
ser binario busqueda-> el mayor nodo de la izq es menor que la raiz y el min nodo de la dcha es mayor que la raiz
ser autoequilibrado-> todos los nodos tienen una diferencia de alturas entre sus hijos de como mucho 1
*/

#include <iostream>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase

using namespace std;
// función que resuelve el problema
// comentario sobre el coste
//caso mejor O(log(N)), donde N es numero de nodos
//caso peor O(n)n donde n es el numero de nodos


struct datos {
    bool esAVL;
    int max;
    int min;
    int altura;
};

datos resolver(bintree<int> const & arbol) {
   
    if (arbol.right().empty() && arbol.left().empty()) {
        return { true,arbol.root(),arbol.root(),1 };
    }
    else if (arbol.left().empty()) {
        datos dcha = resolver(arbol.right());
        return{dcha.esAVL && dcha.altura <=1 &&dcha.min > arbol.root() ,max(arbol.root(),dcha.max),min(arbol.root(),dcha.min), dcha.altura + 1 };
    }

    else if (arbol.right().empty() ) {
        datos izq = resolver(arbol.left());
        return{ izq.esAVL && izq.altura <=1 && izq.max < arbol.root() ,max(arbol.root(),izq.max),min(arbol.root(),izq.min), izq.altura + 1 };
    }
    else {
       datos  izq = resolver(arbol.left());
       datos dcha = resolver(arbol.right());
       return{ izq.esAVL && dcha.esAVL && abs(izq.altura - dcha.altura) <=1 && izq.max < arbol.root() && dcha.min > arbol.root(),
           max(arbol.root(),max(izq.max,dcha.max)) ,min(arbol.root(),min(izq.min,dcha.min)), max(izq.altura,dcha.altura) + 1 };
    }

}
bool esAVL(bintree<int> const& arbol) {
    datos sol = resolver(arbol);
    return  sol.esAVL;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree<int> arbol = leerArbol(-1);
    // escribir solución
    if (arbol.empty()) {
        cout << "SI" << endl;
    }
    else {
        cout << ((esAVL(arbol)) ? "SI" : "NO") << endl;
    }
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
