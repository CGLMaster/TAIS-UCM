/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos: Carlos G�mez L�pez
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
/*INCLUDES UTILIZADOS*/
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"
using namespace std;


/*@ <answer>

    El coste de la funci�n en el peor de los casos es O(M*log(M)), siendo M el n�mero de carreteras
    que unen los pueblos N.

    Para llevar a cabo el ejercicio he planteado un arbol de recubrimiento m�nimo.
    Lo primero que he hecho ha sido crear un grafo valorado, introduciendo los datos de la entrada.
    Tras haber creado el grafo he creado la clase limpieza, la cual se va a emplear de hacer
    el algoritmo de kruskal, en el cual he hecho la modificaci�n de que coja el camino que m�s cueste en tiempo.
    Para determinar si la limpieza es posible, simplemente compruebas la cantidad de conjuntos que tengas,
    si hay mas de 1 significa que ya no es posible limpiar.

    El caso que se que me falla es, uno en el que su recorrido en profundidad es mas grande.
    5 4
1 2 20
1 3 30
1 4 10
4 5 30

 @ </answer> */

 // ========================================================================
 // Escribe el c�digo completo de tu soluci�n debajo de la etiqueta <answer>
 // ========================================================================
 //@ <answer>

class limpieza {
public:
    limpieza(GrafoValorado<int> const& g) : coste(0), cjtos(g.V()) {
        kruskal(g);
    }

    int costeMin() { return coste; }
    bool esPosible() { return cjtos.num_cjtos() == 1; }
private:
    vector<Arista<int>> _ARM;
    int coste;
    ConjuntosDisjuntos cjtos;


    void kruskal(GrafoValorado<int> const& g) { // O(M*log(M))
        PriorityQueue<Arista<int>> pq(g.aristas());
        while (!pq.empty()) { //O(M)
            auto a = pq.top(); pq.pop(); // O(log(M))
            int v = a.uno(), w = a.otro(v);
           if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w); // O(1)
                _ARM.push_back(a);
                coste = max(coste,a.valor());
                if (_ARM.size() == g.V() - 1) break;
           }
        }
    }
};


void resuelveCaso() {

    int N, M;
    cin >> N >> M;
    GrafoValorado<int> g(N);

    int a, b, val;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> val;
        g.ponArista({ a - 1,b - 1,val });
    }

    limpieza l(g);

    if (l.esPosible()) cout << l.costeMin() << "\n";
    else cout << "Imposible\n";



}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
