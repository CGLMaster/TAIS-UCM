
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Digrafo.h"


/*@ <answer>

    Para resolverlo planteo un digrafo introduciendo los datos del casos.txt.
    Una vez tengo el digrafo, creo una clase Dirigido la cual se encarga de recorres en profundidad cada uno de los vértices
    respetando las dependencias.
    A la hora de recorrerlo, también lo guarda topológicamente, es decir, el vértice que no tenga aristas dirigidas se pondrá
    en una cola al inicio que luego será mostrada por pantalla.

    El coste de la función en el peor de los casos es O(V+A), donde V es el número de vértices del grafo y A el número de aristas.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


class Dirigido {
public:
    Dirigido(Digrafo const& d) : visit(d.V(), false), apilado(d.V(), false), Ciclo(false) {
        for (int i = 0; i < d.V(); i++) {
            if (!visit[i]) dfs(d, i);
        }
    }

    bool hayCiclo() const { return Ciclo; }
    deque<int> const& topologico() const { return orden; }
private:
    vector<bool> visit;
    vector<bool> apilado;
    bool Ciclo;
    deque<int> orden;

    void dfs(Digrafo const& d, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : d.ady(v)) {
            if (Ciclo) return;
            if (!visit[w]) dfs(d, w);
            else if (apilado[w]) Ciclo = true;
        }
        orden.push_front(v);
        apilado[v] = false;
    }
};

bool resuelveCaso() {

    int N, M;

    cin >> N >> M;

    if (!std::cin) return false;

    Digrafo d(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        d.ponArista(a - 1, b - 1);
    }

    Dirigido dir(d);

    if (!dir.hayCiclo()) {
        for (int c : dir.topologico()) {
            cout << c + 1 << " ";
        }
    }
    else cout << "Imposible";

    cout << "\n";

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
