
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    El coste de la función en el peor de los casos es O(L), donde L es el número de instrucciones, se queda asi porque el número de aristas va a ser o L o 2L en el peor de los casos.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

// tipoNecro = 0 --> Nunca termina
// tipoNecro = 1 --> A veces termina
// tipoNecro = 2 --> Siempre termina

class Necromicon {
public:
    Necromicon(Digrafo const& d) : visit(d.V(), false), tipoNecro(0), ciclo(false), apilado(d.V(), false) {
        dfs(d, 0);
        if (visit[d.V() - 1]) {
            if (ciclo) tipoNecro = 1;
            else tipoNecro = 2;
        }
    }
    int queTipoEs() { return tipoNecro; }
private:
    vector<bool> visit;
    vector<bool> apilado;
    int tipoNecro;
    bool ciclo;

    void dfs(Digrafo const& d, int v) {
        visit[v] = true;
        apilado[v] = true;
        for (int w : d.ady(v)) {
            if (!visit[w]) dfs(d, w);
            else if (apilado[w]) ciclo = true;
        }
        apilado[v] = false;
    }
};

bool resuelveCaso() {

    int L;
    cin >> L;
    if (!cin) return false;
    Digrafo libro(L + 1);
    for (int i = 0; i < L; i++) {
        string s;
        cin >> s;
        int a;
        if (s == "A") {
            libro.ponArista(i, i + 1);
        }
        else if(s == "J") {
            cin >> a;
            libro.ponArista(i, a - 1);
        }
        else {
            cin >> a;
            libro.ponArista(i, i + 1);
            libro.ponArista(i, a - 1);
        }
    }

    Necromicon n(libro);

    int sol = n.queTipoEs();

    if (sol == 0) cout << "NUNCA";
    else if (sol == 1) cout << "A VECES";
    else cout << "SIEMPRE";

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
