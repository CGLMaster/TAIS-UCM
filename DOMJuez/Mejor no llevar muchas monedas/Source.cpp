
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
#include "EnterosInf.h"
using namespace std;


/*@ <answer>

    El coste de la función en tiempo en el peor de los casos es O(N*C*K), siendo N el número de monedas a contemplar, C el valor del coche y K la cantidad de cada moneda.
    El coste de la función en espacio adicional es O(N*C) --> la matriz

    Recursividad:
        
        cuantas(i,j) : mínimo de monedas i a llevar para pagar j

                        {    cuantas(0,j) = INF      si j > 0
        cuantas(i,j) =  {    cuantas(i,0) = 0
                        {    min( cuantas(i - 1, j - k*vi) + k)
                          0 <= k <= ci
                           k <= j/vi

        ci : cantidad de la moneda i
        vi : valor de la moneda i

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

typedef struct {
    int cantidad;
    int valor;
}Moneda;

bool operator<(Moneda const& a, Moneda const& b) {
    return a.valor > b.valor;
}

EntInf minMonedas(vector<Moneda> const& monedas, int C) {
    int N = monedas.size();
    Matriz<EntInf> M(N + 1, C + 1, Infinito);
    M[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        M[i][0] = 0;
        for (int j = 1; j <= C; j++) {
            M[i][j] = M[i - 1][j];
            if (monedas[i - 1].valor <= j) { //Siempre que el valor de la moneda me valga para pagar el coche, entonces hacemos el caso recursivo
                int k = 1;
                while (k <= monedas[i - 1].cantidad && k <= (j / monedas[i - 1].valor) && j - k * monedas[i - 1].valor <= C) {
                    auto val = M[i - 1][j - k * monedas[i - 1].valor] + k;
                    if (val < M[i][j]) M[i][j] = val;
                    k++;
                }
            }
        }
    }

    return M[N][C];
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (!cin) return false;
    vector<Moneda> monedas(N);
    for (int i = 0; i < N; i++) cin >> monedas[i].valor;
    for (int i = 0; i < N; i++) cin >> monedas[i].cantidad;

    sort(monedas.begin(), monedas.end());

    int coche;
    cin >> coche;

    auto min = minMonedas(monedas, coche);
    if (min == Infinito) cout << "NO\n";
    else cout << "SI " << min << "\n";

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
