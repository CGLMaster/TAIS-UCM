
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    A la hora de plantear el ejercicio, he creado la class Consultas, la cual se introduce como parámetros el grafo (previamente leido) y el número de consultas a realizar.
    Después se llama a la función que te devuelve que nodos se han quedado sin consultar, a través de un recorrido en anchura, guardando el número de nodos que llega a recorrer y
    restándoselos a el número de nodos total.

    El coste de la función en el peor de los casos es O(V + A), donde V es el número de vértices del grafo, es decir los nodos, y A el número de aristas que comforman el grafo.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Consultas {
public:
    Consultas(Grafo const& g, int K) : K(K), g(g) {

    }

    void hacerConsulta() {
        int nodoIni, campoTTL;
        for (int i = 0; i < K; i++) {
            cin >> nodoIni >> campoTTL;
            int l = dfs(nodoIni - 1, campoTTL);
            cout << g.V() - l << "\n";
        }
    }

private:
    int K;
    Grafo g;

    int dfs(int nodo, const int& campoTTL) {            // O(V+A)
        queue<int> q;
        vector<bool> visit(g.V(), false); // Comprueba si ese vector ya ha sido visitado
        vector<int> dist(g.V(), 0); // Distancia recorrida demomento
        int tam = 1;
        visit[nodo] = true;
        q.push(nodo);                  
        while (!q.empty()) {
            int v = q.front();
            q.pop();                    
            for (int w : g.ady(v)) {
                if (!visit[w] && dist[v] + 1 <= campoTTL) {
                    dist[w] = dist[v] + 1;
                    visit[w] = true;
                    tam++;
                    q.push(w);          
                }
            }
        }
        return tam;
    }

};


bool resuelveCaso() {
    int V, A;
    cin >> V >> A;
    if (!cin) return false;
    Grafo g(V);
    for (int i = 0; i < A; i++) {
        int x, y;
        cin >> x >> y;
        g.ponArista(x - 1, y - 1);
    }
    int K;
    cin >> K;
    Consultas c(g, K);
    c.hacerConsulta();
    cout << "---\n";
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

    while(resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
