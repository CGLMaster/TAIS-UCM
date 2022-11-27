
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>

  El coste de la función en el peor de los casos es O(N) donde N es el número de agujeros que tiene la manguera.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int parches(vector<int> const& agujeros, int L) {
    int distancia = agujeros[0];
    int cont = 1;
    for (int i = 0; i < agujeros.size(); i++) {
        if (distancia + L < agujeros[i]) {
            distancia = agujeros[i];
            cont++;
        }
    }
    return cont;
}

bool resuelveCaso() {

    int N, L;
    cin >> N >> L;
    if (!cin)  return false;
    vector<int> agujeros(N);
    for (int i = 0; i < N; i++) cin >> agujeros[i];
    
    cout << parches(agujeros, L) << "\n";

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
