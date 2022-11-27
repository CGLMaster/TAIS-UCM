
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <limits>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>

 A la hora de plantear el ejercicio, me he dado cuenta que lo estaba planteando con un digrafo valorado y no con un grafo valorado, lo cual suponía que algunos casos me saliesen mal.
 Una vez he caido en ello, el resto lo he mantenido de la misma forma, es decir en este caso, simplemente había que hacer un algoritmo de Dijkstra el cual tendremos que modificar su
 funcion relajar, de tal forma que vas a guardar el contador de caminos que lleve su vértice anterior si su valor es superior, y si es igual vas a aumentar su contador de caminos con
 el contador de caminos del vértice anterior.

 El coste de la función en el peor de los casos es O(A * log(V)), siendo A el número de aristas y V el número de vértices del grafo

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Camino {
public:
    Camino(GrafoValorado<int> const& d) : dist(d.V(), INF), pq(d.V()), caminos(d.V()) {
        Dijksta(d);
    }

    int numCaminos() { return caminos[caminos.size() - 1]; }

private:
    const int INF = std::numeric_limits<int>::max();
    vector<int> dist;
    IndexPQ<int> pq;
    vector<int> caminos;

    void Dijksta(GrafoValorado<int> const& d) {
        dist[0] = 0;
        caminos[0] = 1;
        pq.push(0, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : d.ady(v))
                relajar(a, v);
        }
    }

    void relajar(Arista<int> a, int v) {
        int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            caminos[w] = caminos[v];
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor()) caminos[w] += caminos[v];
    }

};

bool resuelveCaso() {

    int N, C;
    cin >> N >> C;
    if (!cin) return false;
    GrafoValorado<int> d(N);
    int a, b, valor;
    for (int i = 0; i < C; i++) {
        cin >> a >> b >> valor;
        d.ponArista({ a - 1,b - 1,valor });
    }
    Camino c(d);

    cout << c.numCaminos() << "\n";

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
