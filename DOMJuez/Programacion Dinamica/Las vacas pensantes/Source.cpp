
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"

/*@ <answer>

    vacas(i,j) = máxima comida que puede comer la protagonista entre los cubos (C) i, j y que le toque comer

              { vacas(i,j) = C[i]   si i = j
              { vacas(i,j) = 0      si i > j
    vacas(i,j){     (         { vacas(i+2,j)    si C[i-1] > C[j]
              {     (   ci +  { vacas(i+1,j-1)  si C[i-1] < C[j]
              { max (                   ó
              {     (   cj +  { vacas(i,j-2)    si C[i] < C[j-1]
              {     (         { vacas(i+1,j-1)  si C[i] > C[j-1]

    El coste de la función en el peor de los casos es O(N^2), donde N es el número de cubos que tienen para comer.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int cuantoCome(vector<int> const& cubos, Matriz<int>& M, int i, int j) {
    if (M[i][j] != -1) return M[i][j];
    if (i == j) M[i][j] = cubos[i];
    else if (i > j) return 0;
    else {
        int maxI = 0, maxJ = 0;
        if (cubos[i + 1] > cubos[j]) maxI = cuantoCome(cubos, M, i + 2, j);
        else maxI = cuantoCome(cubos, M, i + 1, j - 1);
        maxI += cubos[i];
        if (cubos[i] < cubos[j - 1]) maxJ = cuantoCome(cubos, M, i, j - 2);
        else maxJ = cuantoCome(cubos, M, i + 1, j - 1);
        maxJ += cubos[j];
        M[i][j] = max(maxI, maxJ);
    }
    return M[i][j];
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N==0) return false;
    
    vector<int> cubos(N);
    for (int i = 0; i < N; i++) cin >> cubos[i];

    Matriz<int> M(N, N, -1);

    int come = cuantoCome(cubos, M, 0, N-1);

    cout << come << "\n";

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
