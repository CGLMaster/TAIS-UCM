
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
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
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int comprarEquipaciones(vector<int> const& jugadores, vector<int> const& equipaciones) {
    int cont = 0;
    int i = 0;
    while (i < jugadores.size() && i < equipaciones.size()) {
        if (jugadores[i] != equipaciones[i]) {
            if (jugadores[i] + 1 != equipaciones[i]) {
                cont++;
            }
        }
        i++;
    }
    if (i < jugadores.size()) {
        cont += jugadores.size() - i;
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
