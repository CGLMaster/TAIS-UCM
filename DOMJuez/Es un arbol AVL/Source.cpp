
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


bool esEquilibrado(BinTree<int> const& arbol, int& h) {
    if (arbol.empty()) {
        h = 0;
        return true;
    }
    else {
        int hder, hizq;
        bool esIzq = esEquilibrado(arbol.left(), hizq);
        bool esDer = esEquilibrado(arbol.right(), hder);
        h = 1 + max(hizq, hder);
        if (!arbol.left().empty()) {
            if (arbol.left().root() > arbol.root()) return false;
        }
        if (!arbol.right().empty()) {
            if (arbol.right().root() < arbol.root()) return false;
        }
        if (abs(hizq - hder) <= 1 && esIzq && esDer) return true;
        else return false;
    }
}


void resuelveCaso() {
    BinTree<int> arbol = read_tree<int>(cin);
    int h = 0;
    if (esEquilibrado(arbol, h)) cout << "SI\n";
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
