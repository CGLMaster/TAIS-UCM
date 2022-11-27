
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

 El coste de la función en el peor de los casos es O(N*log(N)), donde N es el número de ciudades atacadas e invadidas.
 El coste O(2(N*log(N))) se debe a que vas a ordenar cada uno de los vectores, que simplificando se queda en O(N*log(N))

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int victoria(vector<int> const& enemigos, vector<int> const& defensas) {
    int cont = 0;
    int j = 0;
    for (int i = 0; i < enemigos.size(); i++) {
        if (enemigos[j] <= defensas[i]) {
            j++;
            cont++;
        }
    }
    return cont;
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (!cin)  return false;
    vector<int> enemigos(N);
    for (int i = 0; i < N; i++) cin >> enemigos[i];
    sort(enemigos.begin(), enemigos.end());
    vector<int> defensas(N);
    for (int i = 0; i < N; i++) cin >> defensas[i];
    sort(defensas.begin(), defensas.end());

    cout << victoria(enemigos, defensas) << "\n";

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
