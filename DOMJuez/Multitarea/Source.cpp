
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

    A la hora de realizar el código he planteado un typedef struct el cual se llama Tareas, y contiene un booleano para indicar si la tarea es repetitiva o no, el momento de inicio,
    el de fin, y en caso de que se repita el intervalo en el que se produce.
    Empiezas leyendo las tareas únicas, y a continuación leyendo las tareas periódicas. Cuando se introducen las tareas se situan en función de su tiempo incial.
    Para comprobar si hay conflictos, he creado la función hayConflictos, la cual recorre la lista de tareas siempre que no este vacía, o no se haya encontrado algún conflicto, o
    el tiempo introducido no sea menor que el tiempo en el que se encuentra actualmente.
    Mientras recorre la cola, lo que hace es obtener la tarea más prioritaria, y eliminarla de la cola. A continuación, comprueba si hay algun conflicto comparando el tiempo de inicio
    de la tarea y el tiempo actual en el que nos encontramos.
    Cambias el tiempo actual al ultimo tiempo de la tarea.
    En caso de que sea repetitico, pues aumentas sus tiempos su respectivo intervalo, y lo vuelves a introducir a la cola.

    Desglosando los costes de todo el código obtenemos O(log(N)*N + log(N)*M + log(N)*K), donde N es el número de tareas que se encuentran en la lista, M el número de tareas unicas y
    K el número de tareas periódicas.
    Dicho coste se puede reducir a O(log(N)*(N+M+K)), el cual si nos damos cuenta N = K + M, ya que sumando ambos tipos de tareas, obtenemos el número de total de tareas de la lista.
    
    Por lo que el coste de la función en el peor de los casos es de O(log(N)*N), donde N es el número de tareas que se encuentran en la lista.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

typedef struct {
    bool repetir;
    int ini;
    int fin;
    int intervalo;
}Tareas;

bool operator<(Tareas const& a, Tareas const& b) {
    return b.ini < a.ini;
}

bool hayConflictos(priority_queue<Tareas> lista, const int& N, const int& M, const int& T) {
    bool conflicto = false;
    int tActual = 0;
    while (!lista.empty() && !conflicto && lista.top().ini < T) { // O(N*log(N))
        auto t = lista.top();
        lista.pop();
        conflicto = t.ini < tActual;
        tActual = t.fin;
        if (t.repetir) {
            t.ini += t.intervalo;
            t.fin += t.intervalo;
            lista.push(t);
        }
    }
    return conflicto;
}

bool resuelveCaso() {

    int N, M, T;
    cin >> N >> M >> T;
    if (!cin) return false;
    priority_queue<Tareas> listaTareas;
    for (int i = 0; i < N; i++) { // O(M*log(N))
        Tareas t;
        cin >> t.ini >> t.fin;
        t.intervalo = 0;
        t.repetir = false;
        listaTareas.push(t);
    }
    for (int i = 0; i < M; i++) {  // O(K*log(N))
        Tareas t;
        cin >> t.ini >> t.fin >> t.intervalo;
        t.repetir = true;
        listaTareas.push(t);
    }
    bool conflictos = hayConflictos(listaTareas, N, M, T);
    if (conflictos) cout << "SI\n";
    else cout << "NO\n";
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
