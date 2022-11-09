
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

 

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int comprarEquipaciones(vector<int> const& jugadores, vector<int> const& equipaciones) {
    int cont = jugadores.size();
    int i = 0, j = 0;
    while (i < jugadores.size() && j < equipaciones.size()) {
        if (jugadores[i] == equipaciones[j] || jugadores[i] == equipaciones[j] - 1) {
            cont--;
            i++;
            j++;
        }
        else if (jugadores[i] < equipaciones[j]) i++;
        else j++;
    }
    return cont;
}

bool resuelveCaso() {

    int N, M;
    cin >> N >> M;
    if (!cin) return false;

    vector<int> jugadores(N);
    for (int i = 0; i < N; i++) cin >> jugadores[i];
    sort(jugadores.begin(), jugadores.end());

    vector<int> equipaciones(M);
    for (int i = 0; i < M; i++) cin >> equipaciones[i];
    sort(equipaciones.begin(), equipaciones.end());

    int compra = comprarEquipaciones(jugadores, equipaciones);
    cout << compra << "\n";

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
