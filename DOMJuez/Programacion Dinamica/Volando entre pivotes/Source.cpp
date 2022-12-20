
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    volando(i) : formas distintas de llegar al pivote N - 1 desde el pivote i pudiendo saltar como máximo M pivotes.

    volando(i) =    { 1                                                     si i = N - 1
                    { Sumatorio desde k = 0 hasta M { volando(i + k + 1) }  si i < N - 1
                                i + k + 1 < N

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int volandoPivotes(vector<int>& pivotes, const int& M) {
    unsigned long long int val = 0;
    int N = pivotes.size();
    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1) pivotes[i] = 1;
        else {
            int k = 0;
            while (k <= M && (i + k + 1) < N) {
                pivotes[i] += pivotes[i + k + 1];
                pivotes[i] %= 1000000007;
                k++;
            }
        }
    }
    return pivotes[0];
}

bool resuelveCaso() {

    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) return false;
    vector<int> pivotes(N, 0);
    int cuantos = volandoPivotes(pivotes, M);
    
    cout << cuantos << "\n";

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
