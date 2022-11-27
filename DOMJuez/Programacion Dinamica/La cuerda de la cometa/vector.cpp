/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include "EnterosInf.h"
using namespace std;


/*@ <answer>


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


typedef struct {
    int longitud;
    int coste;
}tCuerda;

void cordelesUsados(vector<tCuerda> cuerdas, int L) {

    vector<bool> sePuede(L + 1, false);
    sePuede[0] = true;

    for (int i = 1; i <= cuerdas.size(); i++) {
        for (int j = L; j >= cuerdas[i-1].longitud; j--) {
            sePuede[j] = sePuede[j] || sePuede[j - cuerdas[i-1].longitud];
        }
    }

    if (sePuede[L]) {

        cout << "SI ";

        vector<long long int> numManeras(L + 1, 0);
        numManeras[0] = 1;

        for (int i = 1; i <= cuerdas.size(); i++) {
            for (int j = L; j >= cuerdas[i-1].longitud; j--) {
                numManeras[j] = numManeras[j] + numManeras[j - cuerdas[i-1].longitud];
            }
        }

        cout << numManeras[L] << " ";

        vector<EntInf> numCordeles(L + 1, Infinito);
        numCordeles[0] = 0;

        for (int i = 1; i <= cuerdas.size(); i++) {
            for (int j = L; j >= cuerdas[i-1].longitud; j--) {
                numCordeles[j] = min(numCordeles[j], numCordeles[j - cuerdas[i-1].longitud] + 1);
            }
        }

        cout << numCordeles[L] << " ";

        vector<EntInf> coste(L + 1, Infinito);
        coste[0] = 0;

        for (int i = 1; i <= cuerdas.size(); i++) {
            for (int j = L; j >= cuerdas[i-1].longitud; j--) {
                coste[j] = min(coste[j], coste[j - cuerdas[i-1].longitud] + cuerdas[i - 1].coste);
            }
        }

        cout << coste[L] << "\n";


    }
    else cout << "NO\n";
}

bool resuelveCaso() {

    int N, L;
    cin >> N >> L;
    if (!cin) return false;

    vector<tCuerda> cuerdas(N);
    int l, c;
    for (int i = 0; i < N; i++) {
        cin >> l >> c;
        cuerdas[i] = { l, c };
    }

    cordelesUsados(cuerdas, L);

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