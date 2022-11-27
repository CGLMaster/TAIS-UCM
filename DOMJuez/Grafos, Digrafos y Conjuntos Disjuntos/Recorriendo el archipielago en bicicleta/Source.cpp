
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"

/*@ <answer>

    El coste de la función en el peor de los casos es O(A * log(A)), donde A es el número de aristas del grafo, ya que se producen A vueltas a un bucle que tiene coste log(A).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Archipielagos { // Hago un Arbol de recubrimiento de coste mínimo (ARM)
public:
    Archipielagos(GrafoValorado<int> const& g) : CD(g.V()), coste(0) {
        kruskal(g);
    }
    bool hayPuentes() const { return CD.num_cjtos() == 1; }
    int costeARM() const { return coste; }
private:
    vector<Arista<int>> ARM;
    ConjuntosDisjuntos CD;
    int coste;
    
    void kruskal(GrafoValorado<int> const& g) {
        auto aristas = g.aristas();
        priority_queue<Arista<int>, vector<Arista<int>>, greater<Arista<int>>> cola(aristas.begin(), aristas.end());
        while (!cola.empty()) {                         //O(A*log(A))
            auto a = cola.top();
            cola.pop();                                 //O(log(A))
            int v = a.uno(), w = a.otro(v);
            if (!CD.unidos(v, w)) {
                CD.unir(v, w);
                ARM.push_back(a);
                coste += a.valor();
                if (ARM.size() == g.V() - 1) break;
            }
        }
    }
};

bool resuelveCaso() {

    int I, P;
    cin >> I >> P;
    if (!cin)  return false;
    GrafoValorado<int> g(I);
    int ini, fin, valor;
    for (int i = 0; i < P; i++) {
        cin >> ini >> fin >> valor;
        g.ponArista({ ini - 1, fin - 1, valor });
    }
    
    Archipielagos a(g);

    if (a.hayPuentes()) cout << a.costeARM() << "\n";
    else cout << "No hay puentes suficientes\n";

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
