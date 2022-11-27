
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


/*@ <answer>

 El ejercicio se ha planteado como explica el profe en su video. Primero creamos unas variables que nos van a indicar el m�ximo
 que se puede obtener y un numero "infinito".
 Creamos una funci�n adyacente la cual segun el caso en el que se encuentre suma 1, multiplica por dos o divide entre 3.
 En vez de crear un digrafo, se define la funci�n de bfs, es decir se realiza un recorrido en anchura, comprobando cada uno de los
 casos (suma, multiplicaci�n y division), por cada ejecuci�n muestra el tama�o del recorrido hasta llegar a esa solucion.

 El coste de la funci�n en el peor de los casos es O(V+A) donde V es el n�mero de v�rtices del grafo y A el n�mero de aristas.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

const int MAX = 10000;
const int INF = 1000000000;

int adyacente(int v, int i) {
    switch (i)
    {
        case 0: return (v + 1) % MAX;
        case 1: return (v * 2) % MAX;
        case 2: return v / 3;
    }
}

int bfs(int ini, int fin) {
    if (ini == fin) return 0;
    vector<int> distancia(MAX, INF);
    distancia[ini] = 0;
    queue<int> q;
    q.push(ini);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            int w = adyacente(v, i);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == fin) return distancia[w];
                else q.push(w);
            }
        }
    }
}

bool resuelveCaso() {

    int ini, sol;

    cin >> ini >> sol;

    if (!std::cin) return false;

    cout << bfs(ini, sol) << "\n";

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
