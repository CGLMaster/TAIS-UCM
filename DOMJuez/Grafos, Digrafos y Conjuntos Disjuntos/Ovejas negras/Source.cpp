
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ConjuntosDisjuntos.h"

/*@ <answer>
    
    El coste de la función en el peor de los casos es O(F*C), donde F es el número de filas y C el número de columnas.

    A la hora de plantear el ejercicio he utilizado conjuntos disjuntos en el que en el caso de ser puntos, comprobaba las direcciones cardinales, y en el caso de que
    hubiese otro punto que no haya sido visitado lo unía en un mismo conjunto. En el caso de que sea una mancha, me guardaba en un contador cuantas manchas hay.
    Para así al final al ConjuntosDisjuntos al obtener el numero de conjuntos restarle las manchas y el fondo, y lo que me reste es una mancha blanca correspondiente
    a una oveja.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const vector<std::pair<int, int>> direcciones = { {1,0},{0,1},{-1,0},{0,-1} };

bool resuelveCaso() {

    int C, F;
    cin >> C >> F;
    if (!cin) return false;

    ConjuntosDisjuntos CD(F * C);
    vector<vector<bool>> puntos(F, vector<bool>(C)); // Matriz para marcar los sitios en los que haya un .
    bool encontrar = false;
    cin.ignore();
    int cont = 1; //Contador de # y del fondo
    for (int i = 0; i < F; i++) {
        string fila;
        getline(cin, fila, '\n');
        for (int j = 0; j < C; j++) {
            if (fila.at(j) == '.') {
                puntos[i][j] = true;
                encontrar = true;
                int pos = (i * C + j);
                for (auto dir : direcciones) {
                    int filaDir = i + dir.first;
                    int colDir = j + dir.second;
                    int posDir = filaDir * C + colDir;
                    if (filaDir >= 0 && colDir >= 0 && filaDir < F && colDir < C && puntos[filaDir][colDir] && !CD.unidos(pos, posDir)) { // Siempre que sean direcciones dentro de la matriz, sea un . y no estén ya unidos
                        CD.unir(pos, posDir);
                    }
                }
            }
            else cont++; //Si es mancha la contamos para luego descartarla de conjunto
        }
    }
    cout << CD.num_cjtos() - cont << "\n";
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
