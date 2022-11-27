// Nombre del alumno Carlos Gómez López


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Matriz.h"
using namespace std;

// El coste de la función en tiempo en el peor de los casos es O(N^3), siendo N el número de cortes posibles.
// El coste de la función en espacio es O(N^2)

/*
    Recurrencia:

    carpintero(i,j): menor coste de cortes desde M[i] a M[j] y los cortes que quedan son M[i+1], M[j-1]


    carpintero(i,j) =   { carpintero(i,j) = 0       si j = i+1 || j = i
                        {  min (carpintero(i,k) + carpintero(k,j)) + 2 * (M[j] - M[i])
                          i<k<j
*/


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

const int INF = 99999999999999;

int carpintero(vector<int> const& cortes) {
    int N = cortes.size();
    Matriz<int> M(N, N, 0);

    for (int d = 2; d < N; d++) {
        for (int i = 0; i < N - d; i++) {
            int minimo = INF;
            int j = i + d;
            for (int k = i + 1; k < j; k++) {
                minimo = min(minimo, M[i][k] + M[k][j]);
            }
            M[i][j] = minimo + 2 * (cortes[j] - cortes[i]);

        }
    }

    return M[0][N - 1];
}

bool resuelveCaso() {
    
    int L, N;
    cin >> L >> N;
    if (L == 0 && N == 0) return false;
    vector<int> cortes(N + 2);
    cortes[0] = 0;
    for (int i = 1; i <= N; i++) cin >> cortes[i];
    cortes[N + 1] = L;

    cout << carpintero(cortes) << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
