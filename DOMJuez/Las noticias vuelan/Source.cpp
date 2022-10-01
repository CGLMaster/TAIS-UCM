
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

class Noticia {
public:
    Noticia(Grafo const& g) : visit(g.V(), false), componentes(g.V()){
        int i = 0;
        for (int v = 0; v < g.V(); v++) {
            if (!visit[v]) {
                int tam = dfs(g, v, i);
                tamanios.push_back(tam);
                i++;
            }
        }
    }

    int getTamanio(int v) {
        if (componentes[v] != -1) {
            return tamanios[componentes[v]];
        }
        return 1;
    }

private:
    vector<bool> visit; // visit[v] = �hay camino de s a v?
    vector<int> tamanios; // Tama�o de cada componente
    vector<int> componentes; // Cada v�rtice a que componente pertenece
    int s; // v�rtice origen
    int dfs(Grafo const& G, int v, int comp) {
        visit[v] = true;
        componentes[v] = comp;
        int tam = 1;
        for (int w : G.ady(v)) {
            if (!visit[w]) {
                tam += dfs(G, w, comp);
            }
        }
        return tam;
    }
};

bool resuelveCaso() {

    int N, M;
    cin >> N >> M;
    if (!cin)  return false;
    Grafo g(N);
    for (int i = 0; i < M; i++) {
        int U;
        cin >> U;
        int antes;
        if (U != 0) {
            cin >> antes;
        }
        for (int j = 1; j < U; j++) {
            int n;
            cin >> n;
            g.ponArista(antes - 1, n - 1);
            antes = n;
        }
    }

    Noticia n(g);
    for (int i = 0; i < N; i++) cout << n.getTamanio(i) << " ";
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
