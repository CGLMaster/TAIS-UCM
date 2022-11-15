
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
    
    Para el caso recursivo básicamente te pide que compruebes las tres posiciones de arriba suya, entonces lo que hago es compruebo cual de esas tres posiciones es más grande,
    si la diagonal izquierda, la de justo arriba o la diagonal derecha.

                    { tablero(i, 0) = 0     (no tiene columnas)
    tablero(i,j)    { tablero(0, j) = 0     (no tiene filas)
                    { tablero(i, j) += max(tablero[i - 1][j], max(tablero[i - 1][j - 1], tablero[i - 1, j + 1]))  (caso recursivo)


    El coste de la función en tiempo en el peor de los caso es O(N^2), donde N son las dimensiones de los lados del tablero.
    El coste de la función en espacio tambien es O(N^2)


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void maximoValor(Matriz<int> tablero, int N) {

    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            tablero[i][j] += max(tablero[i - 1][j], max(tablero[i - 1][j - 1], tablero[i - 1][j + 1]));
        }
    }

    int suma = 0;
    int pos = 0;
    for (int i = 1; i <= N; i++) {
        if (suma < tablero[N - 1][i]) {
            suma = tablero[N - 1][i];
            pos = i;
        }
    }

    cout << suma << " " << pos << "\n";
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (!cin) return false;

    Matriz<int> tablero(N, N + 2, 0);
    for(int i = 0; i < N; i++)
        for(int j = 1; j <= N; j++)
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
