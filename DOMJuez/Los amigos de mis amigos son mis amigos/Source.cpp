
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    A la hora de plantear el ejercicio, me he guiado del v�deo del profe, con el cual lo resuelve, y lo he planteado de forma similar.

    El coste de la funci�n en el peor de los casos es O(N + M) donde N es el n�mero de personas que componen los v�rtices del grafo y M es el n�mero de de pares de amigos, es decir
    las aristas del grafo.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

class Amigos {
public:
    Amigos(Grafo const& g) : visit(g.V(), false), maximo(0) {
        for (int i = 0; i < g.V(); i++) {
            if (!visit[i]) {
                int tam = dfs(g, i);
                maximo = max(maximo, tam);
            }
        }
    }

    int maxi() const { return maximo; }

private:
    vector<bool> visit;
    int maximo;

    int dfs(Grafo const& g, int v) {
        visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w]) tam += dfs(g, w);
        }
        return tam;
    }
};

void resuelveCaso() {
    int N, M;
    cin >> N >> M;
    Grafo g(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        g.ponArista(A - 1, B - 1);
    }
    Amigos a(g);
    cout << a.maxi() << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
