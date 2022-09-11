
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
