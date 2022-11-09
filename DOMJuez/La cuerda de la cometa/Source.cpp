
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
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

typedef struct {
    int longitud;
    int coste;
}tCuerda;

vector<int> cordelesUsados(vector<tCuerda> cuerdas, int L, int& numManeras) {

    vector<int> cometaFinal(L + 1, INT_MAX - 1);
    cometaFinal[0] = 0;

    for (int i = 1; i < cuerdas.size(); i++) {
        for (int j = cuerdas[i].longitud; j <= L; j++) {
            cometaFinal[j] = min(cometaFinal[j], cometaFinal[j - cuerdas[i].longitud] + 1);
        }
    }

    numManeras = cometaFinal[L];
    if (numManeras >= cuerdas.size()) numManeras = -1;
    else {
        vector<int> cuantas(cuerdas.size(), 0);
        int i = cuerdas.size() - 1, j = L;
        while (j > 0) {
            if (cuerdas[i].longitud <= j && cometaFinal[j] == cometaFinal[j - cuerdas[i].longitud] + 1) {
                cuantas[i]++;
                j = j - cuerdas[i].longitud;
            }
            else i--;
        }
        return cuantas;
    }

    return cometaFinal;
}

bool resuelveCaso() {

    int N, L;
    cin >> N >> L;
    if (!cin) return false;

    vector<tCuerda> cuerdas(N);
    int l, c;
    for (int i = 0; i < N; i++) {
        cin >> l >> c;
        cuerdas[i] = {l, c};
    }

    int numManeras = 0;
    auto S = cordelesUsados(cuerdas, L, numManeras);

    if (numManeras != -1) {
        int coste = 0, cont = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != 0) {
                coste += cuerdas[i].coste * S[i];
                cont++;
            }
        }
        cout << "SI " << numManeras << " " << cont << " " << coste << "\n";
    }
    else cout << "NO\n";

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
