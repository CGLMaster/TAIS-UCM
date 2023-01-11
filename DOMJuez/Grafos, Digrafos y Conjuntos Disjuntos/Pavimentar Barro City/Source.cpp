
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase
#include "GrafoValorado.h"

/*@ <answer>

    El coste de la función en el peor de los casos es O(C*log(C)), siendo C el número de calles entre intersecciones N.
    El coste en espacio adicional es O(C).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Pavimentar {
public:
    Pavimentar(GrafoValorado<int> g) : coste(0), cjtos(g.V()) {
        kruskal(g);
    }

    int valCoste() { return coste; }
    bool esPosible() { return cjtos.num_cjtos() == 1; }

private:
    vector<Arista<int>> ARM;
    int coste;
    ConjuntosDisjuntos cjtos;

    void kruskal(GrafoValorado<int>& g) { // O(C*log(C))
        auto arista = g.aristas();
        priority_queue<Arista<int>, vector<Arista<int>>, greater<Arista<int>>> pq(arista.begin(), arista.end());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop(); // O(log(C))
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                ARM.push_back(a); coste += a.valor();
                if (ARM.size() == g.V() - 1) break;
            }
        }
    }

};

bool resuelveCaso() {

    int N, C;
    cin >> N >> C;
    if (!cin)return false;

    GrafoValorado<int> g(N);
    
    int a, b, val;
    for (int i = 0; i < C; i++) {
        cin >> a >> b >> val;
        g.ponArista({ a - 1, b - 1, val });
    }

    Pavimentar p(g);

    if (p.esPosible()) cout << p.valCoste() << "\n";
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
