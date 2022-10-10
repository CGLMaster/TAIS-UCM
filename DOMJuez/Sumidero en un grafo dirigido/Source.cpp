
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    Resuelvo el ejercicio realizando una búsqueda en profundidad del digrafo "d", el cual ha sido leido a través de la entrada directamente.
    Para esta búsqueda se crea la clase Sumidero la cual va a recorrer cada uno de los vectores marcandolos como visitados y
    va a comprobar que no tenga ninguna arista dirigida de este.
    El vértice que tenga un grado de entrada V - 1 y que se considere posible sumidero, es decir que no salga ninguna arista de él,
    será el que se devuelva y salga por pantalla.

    El coste de la función en el peor de los casos es O(V + A), donde N es el número de vértices del digrafo y A el número de aristas de éste.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Sumidero {
public:
    Sumidero(Digrafo const& d) : visit(d.V(), false), gradoE(d.V()) {
        essumidero = false;
        sol = -1;
        for (int v = 0; v < d.V(); v++) {
            if (!visit[v]) {
                dfs(d, v);
            }
        }
        if (sol != -1 && gradoE[sol] == d.V() - 1) essumidero = true;
    }

    bool esSumidero() { return essumidero; }
    int elSumidero() { return sol; }

private:
    vector<int> gradoE;
    vector<bool> visit;
    bool essumidero;
    int sol;

    void dfs(Digrafo const& d, int v) {
        visit[v] = true;
        if (d.ady(v).size() == 0) sol = v;
        for (int w : d.ady(v)) {
            gradoE[w]++;
            if (!visit[w]) {
                dfs(d, w);
            }
        }
    }
};

bool resuelveCaso() {

    Digrafo d(cin);

    if (!cin)  return false;

    Sumidero s(d);

    if (s.esSumidero()) cout << "SI " << s.elSumidero();
    else cout << "NO";

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
