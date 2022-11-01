/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
  * Estudiante 1:Carlos G�mez TAIS45
  * Estudiante 2:Clara Sotillo TAIS96
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
using namespace std;


/*@ <answer>

 El coste de la funcion en el caso peor es de O(P log N) siendo P el numero de aristas del digrafo y N numero de vertices.
 Este coste se debe al uso del algoritmo dijkstra el cual calcula los caminos minimos desde el origen al resto de vertices
 en un tiempo O(A log V) y con un espacio adicional O(V)


 Resolvemos el problema usando un digrafo valorado invirtiendo las aristas proporcionadas, ya que queremos que se recorran los caminos de
 la salida al resto de vertices.
 Usamos dijkstra para hayar los caminos minimos desde la salida a cada uno de los vertices y luego comprobamos que esa distancia es
 menor igual al T proporcionado en cada caso

 @ </answer> */

 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
 //@ <answer>
class laberinto {

public:
    laberinto(DigrafoValorado<int> const& d, int o) : dist(d.V(), INF), pq(d.V()), origen(o) {

        Dijkstra(d);
    }

    bool hayCamino(int s) const {
        return dist[s] != INF;
    }

    int distancia(int s)const {
        return dist[s];
    }



private:

    const int INF = std::numeric_limits<int>::max();
    int origen;
    vector<int> dist;
    IndexPQ<int> pq;
    int cont;
    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }

    }
    void Dijkstra(DigrafoValorado<int> const& d) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : d.ady(v))
                relajar(a);
        }
    }
};


bool resuelveCaso() {

    // leemos la entrada
    int N, S, T, P;
    cin >> N >> S >> T >> P;

    if (!cin)
        return false;

    DigrafoValorado <int> d(N);

    int a, b, val, cont = 0;

    for (int i = 0; i < P; i++) {
        cin >> a >> b >> val;
        d.ponArista({ b - 1,a - 1,val });
    }

    laberinto l(d, S - 1);

    for (int i = 0; i < N; i++) {
        if (i != S - 1) {
            if (l.hayCamino(i) && l.distancia(i) <= T) {
                cont++;
            }

        }
    }

    cout << cont << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
