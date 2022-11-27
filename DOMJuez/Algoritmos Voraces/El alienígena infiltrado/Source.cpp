
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

    El coste de la funcione en el peor de los casos es O(N * log(N)), donde N es el número de intervalos a comprobar. Este coste se debe a la funcion sort().

 @ </answer> */


 // ================================================================
 // Escribe el codigo completo de tu solucion aqui debajo
 // ================================================================
 //@ <answer>

struct Exposicion {
    int C;
    int F;
};

bool operator<(Exposicion const& a, Exposicion const& b) {
    return a.C < b.C;
}

int cuantoCubre(vector<Exposicion> const& intervalos, Exposicion const& exp, bool& imposible) { // O(N)
    int cont = 0;
    int ini = exp.C;
    int i = 0;
    while (!imposible && ini < exp.F) {
        int Cubierto = ini;
        while (i < intervalos.size() && intervalos[i].C <= ini) {
            if (intervalos[i].F > Cubierto)
                Cubierto = intervalos[i].F;
            i++;
        }
        if (Cubierto > ini) {
            cont++;
            ini = Cubierto;
        }
        else imposible = true;
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

    sort(intervalos.begin(), intervalos.end()); // O(N*log(N))

    bool s = false;
    int num = cuantoCubre(intervalos, expuesto, s);

    if (!s) cout << num << "\n";
    else cout << "Imposible\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta linea ya no forma parte de la solucion.

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