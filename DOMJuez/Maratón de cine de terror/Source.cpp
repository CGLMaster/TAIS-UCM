
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int maraton(vector<pair<int, int>> const& finaliza) {
    int cont = 1;
    int t = finaliza[0].first;
    for (int i = 1; i < finaliza.size(); i++) {
        if (t + 10 <= (finaliza[i].first - finaliza[i].second)) {
            t = finaliza[i].first;
            cont++;
        }
    }
    return cont;
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0) return false;
    int h, m, d;
    char c;
    vector<pair<int,int>> finaliza(N);
    for (int i = 0; i < N; i++) {
        cin >> h >> c >> m >> d;
        finaliza[i] = { h * 60 + m + d , d};
    }
    sort(finaliza.begin(), finaliza.end());
    cout << maraton(finaliza) << "\n";
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
