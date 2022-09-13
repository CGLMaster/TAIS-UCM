
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gomez Lopez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "BinTree.h"
using namespace std;


/*@ <answer>

    Para resolver el ejercicio me he basado primero en la estructura de como saber si un árbol es equilibrado, en este tipo de casos
    primero se hace el caso base (si esta vacio) y el luego los casos recursivos, en los cuales compruebas tanto la derecha como la izquierda
    Una vez definido la estructura, lo modifico para poder añadir la operación para saber si es AVL, es decir que en el nodo en el que
    me encuentre sea mayor que todos los nodos que estén en su rama izquierda y menor que todos los nodos de su rama derecha.
    Para ello busco el maximo y minimo de cada rama, y compruebo que el nodo cumpla estas características, junto a si es equilibrado.

    El coste de la función en el peor de los casos es O(log(N)) donde N es el número de nodos del arbol.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


bool esEquilibrado(BinTree<int> const& arbol, int& h, int& maxim, int& minim) { //O(log(N))
    if (arbol.empty()) {
        h = 0;
        maxim = 0;
        minim = 9999999;
        return true;
    }
    else {
        int hder, hizq, maxizq, maxder, minizq, minder;
        bool esIzq = esEquilibrado(arbol.left(), hizq, maxizq, minizq);
        bool esDer = esEquilibrado(arbol.right(), hder, maxder, minder);
        if (abs(hizq - hder) <= 1 && esIzq && esDer && arbol.root() > maxizq && arbol.root() < minder) {
            maxim = max(arbol.root(), maxder);
            minim = min(arbol.root(), minizq);
            h = 1 + max(hizq, hder);
            return true;
        }
        else return false;
    }
}

bool esAVL(BinTree<int> const& arbol) {
    int h, maxim, minim;
    return esEquilibrado(arbol, h, maxim, minim);
}

void resuelveCaso() {
    BinTree<int> arbol = read_tree<int>(cin); // O(log(N))
    if (esAVL(arbol)) cout << "SI\n";
    else cout << "NO\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
