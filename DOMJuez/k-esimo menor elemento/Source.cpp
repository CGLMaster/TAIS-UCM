
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gomez Lopez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "TreeSet_AVL.h"
#include <vector>
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

void kesimo(Set<pair<int, int>> const& arbol, const vector<int>& v) {

}

bool resuelveCaso() {
    int num;
    cin >> num;
    if (num == 0) return false;
    Set<int> arbol;
    for (int i = 0; i < num; i++) {
        int n;
        cin >> n;
        arbol.insert(n);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int pos;
        cin >> pos;
        int a = arbol.k_esimo(pos);
        if (a != -1) cout << a << "\n";
        else cout << "??\n";
    }

    cout << "---\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
