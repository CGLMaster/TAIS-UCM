
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

void maximoValor(Matriz<int> tablero, int N) {

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < N; j++) {
            tablero[i][j] += max(tablero[i - 1][j], max(tablero[i - 1][j - 1], tablero[i - 1][j + 1]));
        }
    }

    int suma = 0;
    int pos = 0;
    for (int i = 0; i < N; i++) {
        if (suma < tablero[N][i]) {
            suma = tablero[N][i];
            pos = i + 1;
        }
    }

    cout << suma << " " << pos << "\n";
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (!cin) return false;

    Matriz<int> tablero(N + 1, N + 1, 0);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> tablero[i][j];

    maximoValor(tablero, N);

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
