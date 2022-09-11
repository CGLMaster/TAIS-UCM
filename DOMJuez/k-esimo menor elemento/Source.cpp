
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

    A la hora de pensar el ejercicio, me hice un dibujo, para entender lo que necesito, en este caso fue muy f�cil, ya que el propio ejercicio te indica que a�adas la variable tam_i
    en el TreeSet, por lo que modifiqu� el TreeSet, y al introducir tambien por orden los int del Set, tambi�n se introducen por orden, es decir el segundo, va a ser tambi�n el 2� si
    se solicita despu�s.

    Para realizar la funci�n de b�squeda lo que empleo son dos nuevas funciones: kesimo(int pos) y buscar(int pos, Link a)

    kesimo(pos) : es una funci�n que recibe la posici�n solicitada como par�metro, y llama a la funcion buscar() pas�ndole como par�metros la posici�n y el nodo raiz, desde el cual se
                  va a empezar la b�squeda, en funci�n de si la encuentra devuelve o el valor o -1, que significa que no la ha encontrado.

    buscar(pos,a) : esta funci�n se encarga de realizar la b�squeda de la posici�n "pos", desde el nodo "a", recorriendo el lado del nodo, en funci�n de "pos" y el tama�o previamente
                    introducido "tam_i", lo busca recursivamente hasta que lo encuentra devolviendo dicho nodo, si no lo encuentra, devuelve un nodo vac�o.

    El coste de la funci�n en el peor de los casos es O(N), donde N es la altura del �rbol, ya que no recorre todos los nodos, pero en el caso de que la posici�n solicitada, supere
    la cantidad de nodos, tendr� que recorrer todo el lateral, recorriendo as� toda la altura del �rbol.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
