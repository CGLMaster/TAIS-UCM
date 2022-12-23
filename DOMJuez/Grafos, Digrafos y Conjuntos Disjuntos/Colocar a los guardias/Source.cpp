
/*@ <answer>
 *
 * Nombre y Apellidos: Caros Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Grafo.h"
using namespace std;


/*@ <answer>

 El coste de la función en el peor de los casos es O(V*A), donde V es el número de vértices del grafo y A el número de aristas.

 A la hora de plantear el ejercicio he utilizado un grafo.
 Una vez tengo el grafo me voy a encargar de comprobar si es bipartito, si lo es se van a poner guardias en la particion que me permita poner menos de ellos.
 Para realizar esta comprobación se tienen que comprobar todas las componentes conexas, ya que no todo el grafo tiene porque estar recogido en una sola componente.
 A la hora de hacer la búsqueda de que partición me proporciona menos guardias, utilizao una búsqueda en profundidad dfs(), con la cual voy marcando los vértices
 ya visitados y los que no lo están le pongo lo opuesto a lo que tenga el puesto adyacente del que viene, es decir o le pongo guardia o no.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Bipartito {
public:
    Bipartito(Grafo const& g) : visitado(g.V(), false), guardia(g.V(), false), sePuede(true), cont(0), b1(0), b2(0) {
        int i = 0;
        while (i < g.V() && sePuede) {
            if (!visitado[i]) {
                guardia[i] = true; //colocamos un guardia para distinguir
                b1++; //se marca como puesto con guardia
                sePuede = dfs(g, i);
                cont += min(b1,b2); //Elegimos el que tenga menos guardias
                b1 = 0;
                b2 = 0;
            }
            i++;
        }
    }

    bool esBipartito() { return sePuede; }

    int numGuardias() { return cont; }
private:
    vector<bool> visitado;
    vector<bool> guardia;
    bool sePuede;
    int cont, b1, b2; //b1 = contador puestos con guardia // b2 = contador puestos sin guardia

    bool dfs(Grafo const& g, int v) {
        visitado[v] = true;
        //g.ady da los adyacentes
        for (int w : g.ady(v)) {
            if (!visitado[w]) {//si está marcado

                guardia[w] = !guardia[v];

                if (guardia[w]) b1++;   //se comprobará cuantos puestos con guardias hay y sin guardias
                else b2++;

                if (!dfs(g, w)) return false;
            }
            else if (guardia[w] == guardia[v])  return false; //si no está marcado y las dos aristas estan vigiladas por guardias
        }

        return true;
    }
};

bool resuelveCaso() {

    int V, A;
    cin >> V >> A;
    if (!cin) return false;

    Grafo g(V);
    int a, b;
    for (int i = 0; i < A; i++) {
        cin >> a >> b;
        g.ponArista(a - 1, b - 1);
    }

    Bipartito bp(g);

    if (bp.esBipartito()) cout << bp.numGuardias() << "\n";
    else cout << "IMPOSIBLE\n";

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
