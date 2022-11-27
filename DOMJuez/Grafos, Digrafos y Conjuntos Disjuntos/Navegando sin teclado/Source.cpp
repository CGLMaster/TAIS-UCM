
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>

 El coste de la funcion en el peor de los casos es O(A * log(V)), donde V es el número de vertices del grafo.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Navegando {
public:
    Navegando(DigrafoValorado<int> const& d, vector<int> const& coste) : dist(d.V(), INF), pq(d.V()) {
        dist[0] = coste[0];
        pq.push(0, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : d.ady(v))
                relajar(a, coste);
        }
    }

    int costeMin() { return dist[dist.size() - 1]; }
    bool hayCamino() const { return dist[dist.size() - 1] != INF; }

private:
    const int INF = std::numeric_limits<int>::max();
    vector<int> dist;
    IndexPQ<int> pq;

    void relajar(AristaDirigida<int> a, vector<int> coste) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + coste[w]) {
            dist[w] = dist[v] + a.valor() + coste[w];
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada

    int N;

    cin >> N;

    if (N == 0) return false;

    vector<int> coste(N);
    for (int i = 0; i < N; i++) cin >> coste[i];
    int M;
    cin >> M;
    DigrafoValorado<int> d(N);
    int a, b, valor;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> valor;
        d.ponArista({ a - 1,b - 1,valor });
    }

    Navegando n(d, coste);

    if (n.hayCamino()) cout << n.costeMin() << endl;
    else cout << "IMPOSIBLE" << endl;

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
