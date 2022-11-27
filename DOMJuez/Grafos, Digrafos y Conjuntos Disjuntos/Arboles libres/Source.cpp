
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    Lo primero me he plateado como te representa el grafo en la entrada, al ver que tiene estructura vertice, arista y despues todas las uniones de las aristas, pues como nos dijo
    el profesor al hacer Grafo g(cin) te lo hace automáticamente y no tienes que introducir las aristas manualmente.
    Seguido a la hora de plantearte lo que es un arbol libre, significa que es aciclico y conexo, es decir al ser conexo el número de aristas va a ser igual al número de vértices - 1
    ( V-1 == A), y acíclico significa que el tamaño del recorrido de profundidad es igual al número de vértices que componen el grafo.

    El coste de la función en el peor de los casos es O(V + A) donde V es el número de vértices del grafo y A es el número de aristas del grafo.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class ArbolLibre {
public:
    ArbolLibre(Grafo const& g) : visit(g.V(), false), tam(0), V(g.V()), A(g.A()) {
        dfs(g, 0);
    }

    bool esArbolLibre() {
        return (V - 1 == A) && (tam == V);
    }

private:
    vector<bool> visit;
    int tam, V, A;

    void dfs(Grafo const& g, int i) {
        tam++;
        visit[i] = true;
        for (int j : g.ady(i)) {
            if (!visit[j]) dfs(g, j);
        }
    }
};

bool resuelveCaso() {

    Grafo g(cin);

    if (!cin) return false;

    ArbolLibre a(g);

    if (a.esArbolLibre()) cout << "SI";
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
