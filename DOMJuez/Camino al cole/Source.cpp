
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

class Camino {
public:
    Camino(GrafoValorado<int> const& g) : cont(0) {
        dfs(g);
    }

    int caminos() const { return cont; }

private:
    vector<Arista<int>> ARM;
    int cont;
    int coste;

    void dfs(GrafoValorado<int> const& g) {
        ConjuntosDisjuntos CD(g.V());
        auto aristas = g.aristas();
        priority_queue<Arista<int>, vector<Arista<int>>, greater<Arista<int>>> cola(aristas.begin(), aristas.end());
        while (!cola.empty()) {                         
            auto a = cola.top();
            cola.pop();                                 
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

    int N, C;
    cin >> N >> C;
    if (!cin) return false;
    GrafoValorado<int> g(N);
    int ini, fin, valor;
    for (int i = 0; i < C; i++) {
        cin >> ini >> fin >> valor;
        g.ponArista({ ini - 1, fin - 1, valor });
    }

    Camino c(g);

    cout << c.caminos() << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
