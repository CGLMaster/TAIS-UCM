
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

    El coste de la función en el peor de los casos es O(N*log(N)) donde N es el número de pilas que tiene Daniel. Este coste se obtiene de la funcion sort().

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int parejas(vector<int> const& pilas, const int& V) {
    int ini = 0;
    int fin = pilas.size() - 1;
    int cont = 0;
    while (ini < fin) {
        if (pilas[ini] + pilas[fin] >= V) {
            cont++;
            ini++;
            fin--;
        }
        else ini++;
    }
    return cont;
}

void resuelveCaso() {

    int N, V;
    cin >> N >> V;
    vector<int> pilas(N);
    for (int i = 0; i < N; i++) cin >> pilas[i];
    sort(pilas.begin(), pilas.end());
    int numParejas = parejas(pilas, V);
    cout << numParejas << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
