
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

    Para resolver el ejercicio me he basado primero en la estructura de como saber si un �rbol es equilibrado, en este tipo de casos
    primero se hace el caso base (si esta vacio) y el luego los casos recursivos, en los cuales compruebas tanto la derecha como la izquierda
    Una vez definido la estructura, lo modifico para poder a�adir la operaci�n para saber si es AVL, es decir que en el nodo en el que
    me encuentre sea mayor que todos los nodos que est�n en su rama izquierda y menor que todos los nodos de su rama derecha.
    Para ello busco el maximo y minimo de cada rama, y compruebo que el nodo cumpla estas caracter�sticas, junto a si es equilibrado.

    El coste de la funci�n en el peor de los casos es O(log(N)) donde N es el n�mero de nodos del arbol.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
