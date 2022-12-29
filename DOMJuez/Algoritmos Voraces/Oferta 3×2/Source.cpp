
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

 Para resolver el ejercicio he empleado un algoritmo voraz el cual vas a tener un vector ordenada de mayor a menor costes,
 vas a ir quitando de los 2 primeros libros de la cola con mayor coste y el tercero es el que recibes gratis, consiguiendo asi maximizar el descuento.

 El coste de la función es O(N*log(N) + N) siendo N el número de libros disponibles.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

/*
* 
* PEOR COSTE POR LO QUE LO HE DESCARTADO
* 
//El coste de la función es O(N* log(N) + N * log(N)) siendo N el número de libros disponibles.

int oferta3x2(priority_queue<int> q, const int& N) {
    int coste = 0;
    int cont = 0;
    for (int i = 0; i < N; i++) { // O(N*log(N))
        if (cont == 2) {
            coste += q.top();
            cont = 0;
        }
        else {
            cont++;
        }
        q.pop();
    }
    return coste;
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (!cin) return false;

    priority_queue<int, vector<int>, less<int>> q;
    int libro;
    for (int i = 0; i < N; i++) { // O(N*log(N))
        cin >> libro;
        q.push(libro);
    }
    
    int coste = oferta3x2(q, N);
    cout << coste << "\n";

    return true;
}
*/

int oferta3x2(vector<int> const& v) {
    int coste = 0;
    int cont = 0;
    for (int i = 0; i < v.size(); i++) { //O(N)
        if (cont == 2) {
            coste += v[i];
            cont = 0;
        }
        else {
            cont++;
        }
    }
    return coste;
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (!cin) return false;

    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<int>()); // O(N*log(N))

    int coste = oferta3x2(v);
    cout << coste << "\n";

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
