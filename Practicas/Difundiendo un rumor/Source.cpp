/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1:
  * Estudiante 2:
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;

#include "Grafo.h";

/*@ <answer>

 El coste de la función en el peor de los casos es O(N+M) donde N es el número de vértices y M el número de aristas

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

class busqueda {
public:
    busqueda(Grafo const& g, vector<int> const& dinero) : visit(g.V(), false) {
        din = 0;
        for (int i = 0; i < g.V(); i++) {
            if (!visit[i]) {
                min = dinero[i];
                dfs(g, i, dinero);
                din += min;
            }
        }
    }

    int dinero() { return din; }

private:
    vector<bool> visit;
    int min;
    int din;

    void dfs(Grafo const& G, int v, vector<int> const& dinero) {
        visit[v] = true;
        for (int w : G.ady(v)) {
            if (!visit[w]) {
                if (dinero[w] < min) {
                    min = dinero[w];
                }
                dfs(G, w, dinero);
            }
        }
       
    }
};


bool resuelveCaso() {

    // leemos la entrada
    int N, M;
    cin >> N >> M;

    if (!cin) return false;

    vector<int> dinero(N);
    for (int i = 0; i < N; i++) cin >> dinero[i];

    Grafo g(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g.ponArista(a - 1, b - 1);
    }
    
    busqueda b(g, dinero);

    cout << b.dinero() << "\n";

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

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
