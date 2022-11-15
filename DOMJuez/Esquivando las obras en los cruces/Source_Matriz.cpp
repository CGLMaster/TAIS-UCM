
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

    evitandoObras (i,j) es el numero de caminos de coste mínimo que no pasan por zonas de obras desde (1,1) hasta (i,j)

                        { evitandoObras (1,1) = 1
                        { evitandoObras (i,1) { si ciudad[i][j] = 'X' ? 0 : evitandoObras (i-1,0)}
    evitandoObras (i,j) { evitandoObras (1,j) { si ciudad[i][j] = 'X' ? 0 : evitandoObras (1,j-1)}
                        { evitandoObras (i,j) = 0                                            si ciudad[i][j] = 'X'
                        { evitandoObras (i,j) = evitandoObras(i - 1,j) + evitandoObras(i,j-1)    si ciudad[i][j] = '.'

    El coste de la función en tiempo en el peor de los casos es O(N*M), donde N son las dimensiones de la ciudad.
    El coste de la función en espacio en el peor de los casos es O(N*M).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void evitandoObras(Matriz<char> ciudad, int N, int M) {

    Matriz<int> obras(N, M, 0);
    obras[0][0] = 1;

    for (int j = 1; j < M; j++) {
        if (ciudad[0][j] == 'X') obras[0][j] = 0;
        else obras[0][j] = obras[0][j - 1];
    }

    for (int i = 1; i < N; i++) {
        if (ciudad[i][0] == 'X') obras[i][0] = 0;
        else obras[i][0] = obras[i - 1][0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (ciudad[i][j] == 'X') obras[i][j] = 0;
            else obras[i][j] = obras[i - 1][j] + obras[i][j - 1];
        }
    }

    cout << obras[N - 1][M - 1] << "\n";

}

bool resuelveCaso() {

    int N, M;
    cin >> N >> M;
    if (!cin) return false;

    Matriz<char> ciudad(N, M, '0');
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> ciudad[i][j];

    evitandoObras(ciudad, N, M);

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
