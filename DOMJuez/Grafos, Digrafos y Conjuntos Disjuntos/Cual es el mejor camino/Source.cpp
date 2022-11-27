
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <limits>
#include <queue>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>

 A la hora de plantear el ejercicio, me he dado cuenta que lo estaba planteando con un digrafo valorado y no con un grafo valorado, lo cual suponía que algunos casos me saliesen mal.
 Una vez he caido en ello, el resto lo he mantenido de la misma forma, es decir en este caso, intento buscar que haya camino, realizando para ello un recorrido en profundidad del grafo
 y después compruebo el camino más corto, y si ambos coinciden es la solución con el coste y SI, si no coinciden es el coste y NO y si no hay camino es SIN CAMINO
 Para poder llevar a cabo esta locura, he tenido que hacer las funciones igual que en los apuntes, pero para el caso de relajar y Dijkstra he tenido que modificar la forma de plantearlos
 Es decir no solo me voy a centrar en obtener el coste menor, si no tambien la mayor distancia de de numeros de vertices que recorre para llegar al "destino".
 Por ello he utilizado pair, en vez de crear otros dos vectores (uno para la cola y otro para la distancia), además de lo que ya tengo, ya que de esta forma el coste es menor.
 
 El coste de la función en el peor de los casos es O(K * ( (A * log(V) + (V + A) ) ), donde K es el número de consultas que se realizan, A el número de aristas
 y V el número de vértices del grafo

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


// Salida = 0 --> No tiene ningun camino
// Salida = 1 --> Hay camino pero no se puede recorrer
// Salida = 2 --> Hay camino y se puede recorrer
class MejorCamino {
public:
    MejorCamino(GrafoValorado<int> const& d, const int& ini, const int& fin) : pq(d.V()), distBFS(d.V(), INF), salida(0), dist(d.V(), {0,INF}) {
        bfs(d, ini);
        if (distBFS[fin] != INF) {
            Dijkstra(d, ini);
            salida++;
            if (dist[fin].first == distBFS[fin]) salida++;
        }
    }
    int queSalida() { return salida; }
    int coste(int n) { return dist[n].second; }
private:
    const int INF = std::numeric_limits<int>::max();
    IndexPQ<pair<int,int>> pq;
    vector<int> distBFS;
    vector<pair<int, int>> dist; //dist va a tener como primer valor la distancia contada con el numero de vertices que atraviesa y como segundo el coste de ésta
    int salida;

    void relajar(Arista<int> a, int v) {
        int w = a.otro(v);
        if (dist[w].second > dist[v].second + a.valor()) {
            dist[w].second = dist[v].second + a.valor();
            dist[w].first = dist[v].first + 1; // aumenta el numero de vertices al camino con menor coste
            pq.update(w, dist[w]);
        }
        else if (dist[w].second == dist[v].second + a.valor() && dist[w].first > dist[v].first + 1) { // En caso de que el coste sea el mismo y el número de vertices es mayor
            dist[w].first = dist[v].first + 1; // aumenta el numero de vertices al camino con menor coste
            pq.update(w, dist[w]);
        }
    }
    void Dijkstra(GrafoValorado<int> const& d, const int& ini) { // O(A * log(V))
        dist[ini] = { 0,0 };
        pq.push(ini, { 0,0 });
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : d.ady(v))
                relajar(a, v);
        }
    }
    void bfs(GrafoValorado<int> const& d, const int& ini) { // Recorrido en profundidad del Dirafo Valorado --> O(V + A)
        distBFS[ini] = 0;
        queue<int> cola;
        cola.push(ini);
        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            for (auto a : d.ady(v)) {
                int w = a.otro(v);
                if (distBFS[w] == INF) {
                    distBFS[w] = distBFS[v] + 1;
                    cola.push(w);
                }
            }
        }
    }

};

bool resuelveCaso() {

    int N, C;
    cin >> N >> C;
    if (!cin) return false;
    GrafoValorado<int> d(N);
    int a, b, valor;
    for (int i = 0; i < C; i++) {
        cin >> a >> b >> valor;
        d.ponArista({ a - 1, b - 1, valor });
    }

    int K;
    cin >> K;
    int ini, fin;
    for (int i = 0; i < K; i++) {
        cin >> ini >> fin;
        MejorCamino mj(d, ini - 1, fin - 1);
        int s = mj.queSalida();
        if (s == 0) cout << "SIN CAMINO\n";
        else {
            cout << mj.coste(fin - 1);
            if (s == 1) cout << " NO\n";
            else cout << " SI\n";
        }
    }

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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
