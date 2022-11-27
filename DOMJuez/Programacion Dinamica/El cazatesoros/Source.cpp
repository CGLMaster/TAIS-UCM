
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

  cazatesoros(i,j) = cantidad(C) máxima de oro a recoger con j segundos de oxigeno entre 1 a i tesoros que se encuentran a una cierta profundidad(P).

                    { cazatesoros(i,0) = 0
 cazatesoros(i,j)   { cazatesoros(0,i) = 0
                    { cazatesoros(i,j) = cazatesoros(i-1,j)                                     si P[i] + 2P[i] > j
                    { cazatesoros(i,j) = max (cazatesoros(i-1,j), cazatesoros(i-1,j-3P[i]) + C[i])  si P[i] + 2P[i] <= j
  
 El coste está en el orden de O(N*T) ya que es el numero de subproblemas distintos que se resuelven donde N es el numero de cofres y T el tiempo del que disponen debajo del agua.  

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

typedef struct {
    int profundidad;
    int cantidad;
}tCofres;

int cazatesoros_recursion(vector<tCofres> const& cofres, Matriz<int>& M, int i, int j) {

    if (M[i][j] != -1) return M[i][j];

    if (i == 0 || j == 0) M[i][j] = 0;
    else if (3 * cofres[i - 1].profundidad > j) M[i][j] = cazatesoros_recursion(cofres, M, i - 1, j);
    else M[i][j] = max(cazatesoros_recursion(cofres, M, i - 1, j), cazatesoros_recursion(cofres, M, i - 1, j - 3 * cofres[i - 1].profundidad) + cofres[i - 1].cantidad);

    return M[i][j];
}

int cazatesoros(vector<tCofres> const& cofres, int T, int& numCofres, deque<tCofres>& sol) {
    int N = cofres.size();
    Matriz<int> M(N + 1, T + 1, -1);

    int maximoOro = cazatesoros_recursion(cofres, M, N, T);

    int i = N, j = T;
    while (i > 0 && j > 0) {
        if (M[i][j] != M[i - 1][j]) {
            sol.push_front(cofres[i - 1]);
            j = j - 3 * cofres[i - 1].profundidad;
            numCofres++;
        }
        --i;
    }
    return maximoOro;
}

bool resuelveCaso() {

    int T, N;
    cin >> T >> N;
    if (!cin) return false;

    vector<tCofres> cofres(N);
    for (int i = 0; i < N; i++) cin >> cofres[i].profundidad >> cofres[i].cantidad;

    int numCofres = 0;
    deque<tCofres> sol;
    int maxOro = cazatesoros(cofres, T, numCofres, sol);

    cout << maxOro << "\n" << numCofres << "\n";
    for (tCofres c : sol) {
        cout << c.profundidad << " " << c.cantidad << "\n";
    }
    cout << "---\n";

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
