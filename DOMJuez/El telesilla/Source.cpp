
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int cuantosViajes(vector<int> const& pesos, const int P) {
    int cont = 0;
    int min = 0, max = pesos.size() - 1;
    int i = 0;
    while (i < pesos.size() && max >= min) {
        if (pesos[min] + pesos[max] <= P) {
            cont++;
            min++;
            max--;
        }
        else {
            cont++;
            max--;
        }
    }
    return cont;
}

bool resuelveCaso() {

    int P, C;
    cin >> P >> C;
    if (!cin) return false;
    
    vector<int> pesos(C);
    for (int i = 0; i < C; i++) cin >> pesos[i];
    sort(pesos.begin(), pesos.end());

    int viajes = cuantosViajes(pesos, P);
    cout << viajes << "\n";

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
