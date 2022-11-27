
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    El coste en el peor de los casos es O(K*(V+A)), donde V es el número de vértices, A el número de aristas y K el número de 
    opciones de recorrido de camiones 

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Reparto {
public:
    Reparto(GrafoValorado<int> const& g, const int ini, const int fin, const int ancho) : visit(g.V(), false), llega(false) {
        dfs(g, ini, ancho);
        if (visit[fin]) llega = true;
    }

    bool llegaCamion() { return llega; }
private:
    vector<bool> visit;
    bool llega;
    void dfs(GrafoValorado<int> const& g, int v, const int ancho) {
        visit[v] = true;
        for (auto a : g.ady(v)) {
            if (a.valor() >= ancho) {
                int w = a.otro(v);
                if (!visit[w]) dfs(g, w, ancho);
            }
        }
    }
};

bool resuelveCaso() {

    int V, A;
    cin >> V >> A;
    if (!cin)  return false;
    GrafoValorado<int> g(V);
    int u, v, valor;
    for (int i = 0; i < A; i++) {
        cin >> u >> v >> valor;
        g.ponArista({ u - 1,v - 1,valor });
    }
    int K;
    cin >> K;
    int ini, fin, ancho;
    for (int i = 0; i < K; i++) {
        cin >> ini >> fin >> ancho;
        Reparto r(g, ini - 1, fin - 1, ancho);
        if (r.llegaCamion()) cout << "SI\n";
        else cout << "NO\n";
    }

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
