/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include "EnterosInf.h"
#include "Matriz.h"
using namespace std;

/*@ <answer>



 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void Floyd(Matriz<EntInf> const& G, Matriz<EntInf>& C) {
    int V = G.numfils(); // número de vértices de G
    // inicialización
    C = G;
    // actualizaciones de las matrices
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                auto temp = C[i][k] + C[k][j];
                if (temp < C[i][j]) { // es mejor pasar por k
                    C[i][j] = temp;
                }
            }
        }
    }
}

bool resuelveCaso() {
    int P, R;
    cin >> P >> R;
    if (!cin) return false;

    unordered_map<string, int> mapa;
    Matriz<EntInf> M(P, P, Infinito);
    string pers1, pers2;
    int index = 0;
    for (int i = 0; i < R; i++) {
        cin >> pers1;
        if (mapa.count(pers1) == 0) {
            mapa[pers1] = index;
            index++;
        }
        cin >> pers2;
        if (mapa.count(pers2) == 0) {
            mapa[pers2] = index;
            index++;
        }
        M[mapa[pers1]][mapa[pers2]] = 1;
        M[mapa[pers2]][mapa[pers1]] = 1;
    }
    for (int i = 0; i < P; i++) {
        M[i][i] = 0;
    }

    Matriz<EntInf> C(P, P, Infinito);

    Floyd(M, C);

    EntInf max = 0;

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            if (max < C[i][j]) max = C[i][j];
        }
    }

    if (max == Infinito) cout << "DESCONECTADA\n";
    else cout << max << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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