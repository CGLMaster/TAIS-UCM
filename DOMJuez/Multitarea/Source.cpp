
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

typedef struct {
    int ini;
    int fin;
    int repetir;
}Tareas;

bool operator<(Tareas const& a, Tareas const& b) {
    return b.ini < a.ini || (b.ini == a.ini) && (b.fin < a.fin);
}

bool hayConflictos(priority_queue<Tareas> lista, const int& N, const int& M, const int& T) {
    bool conflicto = false;
    int tActual = 0;
    while (!lista.empty() && !conflicto && lista.top().ini < T) {
        auto t = lista.top();
        lista.pop();
        if (t.fin > lista.top().ini && T > lista.top().ini) conflicto = true;
        if (t.repetir > 0) {
            t.ini += t.repetir;
            t.fin += t.repetir;
            lista.push(t);
        }
        tActual = t.fin;
    }
    return conflicto;
}

bool resuelveCaso() {

    int N, M, T;
    cin >> N >> M >> T;
    if (!cin) return false;
    priority_queue<Tareas> listaTareas;
    for (int i = 0; i < N; i++) {
        Tareas t;
        cin >> t.ini >> t.fin;
        t.repetir = 0;
        listaTareas.push(t);
    }
    for (int i = 0; i < M; i++) {
        Tareas t;
        cin >> t.ini >> t.fin >> t.repetir;
        listaTareas.push(t);
    }
    bool conflictos = hayConflictos(listaTareas, N, M, T);
    if (conflictos) cout << "SI\n";
    else cout << "NO\n";
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
