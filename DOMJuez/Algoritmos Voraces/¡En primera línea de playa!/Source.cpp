
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

    El coste de la función en el peor de los casos es O(N*log(N)), donde N es el número de edificios, a los cuales se van a hacer pasadizos subterráneos.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Edificios {
    int W;
    int E;
};

bool operator<(Edificios const& a, Edificios const& b) {
    return a.E < b.E || (a.E == b.E && a.W < b.W);
}

int numPasadizos(vector<Edificios> const& edificios) {
    int fin = edificios[0].E;
    int cont = 1;
    for (int i = 1; i < edificios.size(); i++) {
        if (edificios[i].W >= fin) {
            cont++;
            fin = edificios[i].E;
        }
    }
    return cont;
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0) return false;

    vector<Edificios> edificios(N);
    int w, e;
    for (int i = 0; i < N; i++) {
        cin >> w >> e;
        edificios[i] = { w, e };
    }
    sort(edificios.begin(), edificios.end());

    int s = numPasadizos(edificios);
    cout << s << "\n";

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
