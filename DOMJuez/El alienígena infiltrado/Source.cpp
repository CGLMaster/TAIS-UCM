
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

struct Exposicion {
    int C;
    int F;
};

bool operator<(Exposicion const& a, Exposicion const& b) {
    return a.F < b.F || (a.F == b.F && a.C < b.C);
}

int cuantoCubre(vector<Exposicion> const& intervalos, Exposicion const& exp) {
    int cont = 0;
    int fin = intervalos[0].F;
    int i = 1;
    while (i < intervalos.size() && fin < exp.F) {
        if (intervalos[i].F >= fin && intervalos[i].C <= fin) {
            cont++;
            fin = intervalos[i].F;
        }
        else {
            cont = 0;
            break;
        }
        i++;
    }
    return cont;
}

bool resuelveCaso() {

    Exposicion expuesto;
    int N;
    cin >> expuesto.C >> expuesto.F >> N;
    if (expuesto.C == 0 && expuesto.F == 0 && N == 0) return false;

    vector<Exposicion> intervalos(N);
    int C, F;
    for (int i = 0; i < N; i++) {
        cin >> C >> F;
        intervalos[i] = { C,F };
    }
    
    sort(intervalos.begin(), intervalos.end());

    int s = cuantoCubre(intervalos, expuesto);

    if (s != 0) cout << s << "\n";
    else cout << "Imposible\n";

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
