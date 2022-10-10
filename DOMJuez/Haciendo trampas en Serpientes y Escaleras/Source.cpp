
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
using namespace std;

/*@ <answer>

  El coste de la función en el peor de los casos es O(N^2 + K*N^2), donde N es el tamaño de las dimensiones de la matriz y K es el numero de caras del dado

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int bfs(unordered_map<int, int> const& salta, const int& N, const int& k) {
    queue<int> q;
    vector<int> dist(N*N+1);
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 1; i <= k && v + i <= (N*N); i++) {
            int sig = v + i;
            if (salta.count(sig)) {
                sig = salta.at(sig);
            }
            if (dist[sig] == 0) {
                dist[sig] = dist[v] + 1;
                if (sig == N * N) return dist[sig];
                q.push(sig);
            }
        }
    }
}

bool resuelveCaso() {

    int N, K, S, E;

    cin >> N >> K >> S >> E;

    if (N==0&&K==0&&S==0&&E==0) return false;

    unordered_map<int, int> salta;

    for (int i = 0; i < (S + E); i++) {
        int a, b;
        cin >> a >> b;
        salta.insert({ a,b });
    }

    cout << bfs(salta, N, K) << "\n";

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
