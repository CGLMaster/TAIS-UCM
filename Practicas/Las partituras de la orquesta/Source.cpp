/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
  * Estudiante 1: Carlos G�mez L�pez TAIS45
  * Estudiante 2: Clara Sotillo Sotillo TAIS96
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>


 el coste de la funcion en el peor de los casos es O((N log N) + (K log N)) donde K es igual P-N donde P es el numero de partituras
 y N es el numero de grupos de instrumentos


 Creamos un struct para cada tipo de instrumento con su numero de integrantes y de partituras

 Creamos una cola de prioridad de maximos ordenandolo por el numero de integrantes entre el numero de partituras
 teniendo en cuenta los casos que el resto de la division no sea cero

 Introducimos los grupos en la cola con el numero de partituras inicializado a 1 y el numero de participantes

 Recorremos un bucle con las partituras restantes despues de la inicializacion (P-N)

 Dentro del bucle, cogemos el intrumento m�s prioritario, lo eliminamos y lo volvemos a a�adir con una partitura m�s.

 Finalmente mostramos el grupo con el mayor numero de integrantes por partitura


 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
 //@ <answer>
struct instrumento {
    int num, cont;
};

bool operator<(instrumento const& a, instrumento const& b) {

    return (a.num / a.cont) < (b.num / b.cont) || ((a.num / a.cont) == (b.num / b.cont) && (a.num % a.cont) < (b.num % b.cont));
}

bool resuelveCaso() {


    int P, N;
    priority_queue <instrumento> q;
    instrumento inst;
    cin >> P >> N;

    if (!cin)
        return false;

    for (int i = 0; i < N; i++) { // n log n
        cin >> inst.num;
        inst.cont = 1;
        q.push(inst);
    }

    for (int i = 0; i < P - N; i++) { // (P-N) log n

        inst = q.top();
        inst.cont++;
        q.pop(); // log n
        q.push(inst);// log n
    }
    inst = q.top();
    if (inst.num % inst.cont == 0) {
        cout << inst.num / inst.cont << "\n";
    }
    else {
        cout << (inst.num / inst.cont) + 1 << "\n";
    }
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

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}