
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gomez Lopez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

    Básicamente no tengo nada que opinar sobre el ejercicio porque está explicado en el video del profesor de "Colas de prioridad".
    El coste de la función en el peor de los casos es de O(log(N)*(N+K)) donde N es el número de nodos y K es el número de envíos.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct usuarios {
    int id;       //identificador (en caso de empate)
    int periodo; // tiempo entre consultas
    int actual; // cuando le toca
};

bool operator<(usuarios const& a, usuarios const& b) {
    return b.actual < a.actual || (a.actual == b.actual && b.id < a.id);
}

bool resuelveCaso() {

    int num;
    cin >> num;
    if (num == 0) return false;
    priority_queue<usuarios> cola;
    for (int i = 0; i < num; i++) { //O(N*log(N))
        int n, p;
        cin >> n >> p;
        cola.push({n, p, p});
    }
    int K;
    cin >> K;
    while (K--) {               // O(K*log(N))
        auto c = cola.top();
        cola.pop();
        cout << c.id << "\n";
        c.actual += c.periodo;
        cola.push(c);
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
