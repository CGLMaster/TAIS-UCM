
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int aibofobia_rec(string const& palabra, int i, int j, Matriz<int>& M) {

    if (M[i][j] == -1) {
        if (i >= j) M[i][j] = 0;
        else if (palabra[i] == palabra[j]) M[i][j] = aibofobia_rec(palabra, i + 1, j - 1, M);
        else M[i][j] = min(aibofobia_rec(palabra, i + 1, j, M) + 1, aibofobia_rec(palabra, i, j - 1, M) + 1);
    }
    return M[i][j];
}

string reconstruir(string const& palabra, Matriz<int> const& M, int i, int j) {
    if (i > j) return { };
    if (i == j) return { palabra[i] };
    if (palabra[i] == palabra[j]) return palabra[i] + reconstruir(palabra, M, i + 1, j - 1) + palabra[j];
    else if (M[i][j] == M[i + 1][j]) return palabra[i] + reconstruir(palabra, M, i + 1, j) + palabra[i];
    else return palabra[j] + reconstruir(palabra, M, i, j - 1) + palabra[j];
}

bool resuelveCaso() {

    string palabra;
    cin >> palabra;
    if (!cin) return false;
    
    int N = palabra.size();
    Matriz<int> aibofobia(N, N, -1);

    cout << aibofobia_rec(palabra, 0, N - 1, aibofobia) << " " << reconstruir(palabra, aibofobia, 0, N - 1) << "\n";


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
