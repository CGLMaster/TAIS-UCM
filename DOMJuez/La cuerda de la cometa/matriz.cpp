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
#include "Matriz.h"
using namespace std;


/*@ <answer>
    
    Recurrencia de cada una de las fases:

                        {   sePuede(i,0) = true
    sePuede(i,j) =      {   sePuede(0,j) = false
                        {   sePuede(i-1,j)                                                      si longitud[i-1] > j
                        {   sePuede(i-1,j) || sePuede(i-1,j-longitud[i-1])                      si longitud[i-1] <= j

                        {   maneras(i,0) = 1
    maneras(i,j) =      {   maneras(0,j) = 0
                        {   maneras(i-1,j)                                                      si longitud[i-1] > j
                        {   maneras(i-1,j) + maneras(i-1,j-longitud[i-1])                       si longitud[i-1] <= j

                        {   minCordeles(i,0) = 0
    minCordeles(i,j) =  {   minCordeles(0,j) = 0
                        {   minCordeles(i-1,j)                                                  si longitud[i-1] > j
                        {   min(minCordeles(i-1,j) + minCordeles(i-1,j-longitud[i-1]) + 1)      si longitud[i-1] <= j

                        {   coste(i,0) = 0
    coste(i,j) =        {   coste(0,j) = 0
                        {   coste(i-1,j)                                                        si longitud[i-1] > j
                        {   min(coste(i-1,j) + coste(i-1,j-longitud[i-1]) + coste[i-1])         si longitud[i-1] <= j

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

    int N = cuerdas.size();

    Matriz<bool> sePuede(N + 1, L + 1, false);
    sePuede[0][0] = true;

    for (int i = 1; i <= N; i++) {
        sePuede[i][0] = true;
        for (int j = 1; j <= L; j++) {
            if (cuerdas[i - 1].longitud > j) {
                sePuede[i][j] = sePuede[i - 1][j];
            }
            else {
                sePuede[i][j] = sePuede[i - 1][j] || sePuede[i - 1][j - cuerdas[i - 1].longitud];
            }
        }
    }

    if (sePuede[N][L]) {

        cout << "SI ";

        Matriz<long long int> numManeras(N + 1, L + 1, 0);
        numManeras[0][0] = 1;

        for (int i = 1; i <= N; i++) {
            numManeras[i][0] = 1;
            for (int j = 1; j <= L; ++j) {
                if (cuerdas[i - 1].longitud > j) {
                    numManeras[i][j] = numManeras[i - 1][j];
                }
                else {
                    numManeras[i][j] = numManeras[i - 1][j] + numManeras[i - 1][j - cuerdas[i - 1].longitud];
                }
            }
        }

        cout << numManeras[N][L] << " ";

        Matriz<EntInf> numCordeles(N + 1, L + 1, Infinito);
        numCordeles[0][0] = 0;

        for (int i = 1; i <= N; i++) {
            numCordeles[i][0] = 0;
            for (int j = 1; j <= L; ++j) {
                if (cuerdas[i - 1].longitud > j) {
                    numCordeles[i][j] = numCordeles[i - 1][j];
                }
                else {
                    numCordeles[i][j] = min(numCordeles[i - 1][j], numCordeles[i - 1][j - cuerdas[i - 1].longitud] + 1);
                }
            }
        }

        cout << numCordeles[N][L] << " ";

        Matriz<EntInf> coste(N + 1, L + 1, Infinito);
        coste[0][0] = 0;

        for (int i = 1; i <= cuerdas.size(); i++) {
            coste[i][0] = 0;
            for (int j = 1; j <= L; ++j) {
                if (cuerdas[i - 1].longitud > j) {
                    coste[i][j] = coste[i - 1][j];
                }
                else {
                    coste[i][j] = min(coste[i - 1][j], coste[i - 1][j - cuerdas[i - 1].longitud] + cuerdas[i - 1].coste);
                }
            }
        }

        cout << coste[N][L] << "\n";


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