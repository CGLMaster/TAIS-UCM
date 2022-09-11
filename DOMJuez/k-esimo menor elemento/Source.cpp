
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gomez Lopez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "TreeSet_AVL.h"
#include <vector>
using namespace std;


/*@ <answer>

    A la hora de pensar el ejercicio, me hice un dibujo, para entender lo que necesito, en este caso fue muy fácil, ya que el propio ejercicio te indica que añadas la variable tam_i
    en el TreeSet, por lo que modifiqué el TreeSet, y al introducir tambien por orden los int del Set, también se introducen por orden, es decir el segundo, va a ser también el 2º si
    se solicita después.

    Para realizar la función de búsqueda lo que empleo son dos nuevas funciones: kesimo(int pos) y buscar(int pos, Link a)

    kesimo(pos) : es una función que recibe la posición solicitada como parámetro, y llama a la funcion buscar() pasándole como parámetros la posición y el nodo raiz, desde el cual se
                  va a empezar la búsqueda, en función de si la encuentra devuelve o el valor o -1, que significa que no la ha encontrado.

    buscar(pos,a) : esta función se encarga de realizar la búsqueda de la posición "pos", desde el nodo "a", recorriendo el lado del nodo, en función de "pos" y el tamaño previamente
                    introducido "tam_i", lo busca recursivamente hasta que lo encuentra devolviendo dicho nodo, si no lo encuentra, devuelve un nodo vacío.

    El coste de la función en el peor de los casos es O(N), donde N es la altura del árbol, ya que no recorre todos los nodos, pero en el caso de que la posición solicitada, supere
    la cantidad de nodos, tendrá que recorrer todo el lateral, recorriendo así toda la altura del árbol.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    int num;
    cin >> num;
    if (num == 0) return false;
    Set<int> arbol;
    for (int i = 0; i < num; i++) {
        int n;
        cin >> n;
        arbol.insert(n);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int pos;
        cin >> pos;
        int a = arbol.k_esimo(pos);
        if (a != -1) cout << a << "\n";
        else cout << "??\n";
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
