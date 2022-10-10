
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    Resuelvo el ejercicio realizando una b�squeda en profundidad del digrafo "d", el cual ha sido leido a trav�s de la entrada directamente.
    Para esta b�squeda se crea la clase Sumidero la cual va a recorrer cada uno de los vectores marcandolos como visitados y
    va a comprobar que no tenga ninguna arista dirigida de este.
    El v�rtice que tenga un grado de entrada V - 1 y que se considere posible sumidero, es decir que no salga ninguna arista de �l,
    ser� el que se devuelva y salga por pantalla.

    El coste de la funci�n en el peor de los casos es O(V + A), donde N es el n�mero de v�rtices del digrafo y A el n�mero de aristas de �ste.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
