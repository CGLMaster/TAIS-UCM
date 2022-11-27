
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

    El coste de la función en el peor de los casos es O(F*C), donde F es el número de filas y C el número de columnas

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const vector<std::pair<int, int>> direcciones = { {0,1},{0,-1}, {1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };

bool resuelveCaso() {

    int F, C;
    cin >> F >> C;
    if (!cin)  return false;
    ConjuntosDisjuntos CD(F * C);
    vector<vector<bool>> hastag(F, vector<bool>(C)); // Matriz para marcar los sitios en los que haya un #
    int maxi = 0;
    bool encontrar = false;
    cin.ignore();
    for (int i = 0; i < F; i++) {
        string fila;
        getline(cin, fila, '\n');
        for (int j = 0; j < C; j++) {
            if (fila.at(j) == '#') {
                hastag[i][j] = true;
                encontrar = true;
                int pos = (i * C + j);
                for (auto dir : direcciones) {
                    int filaDir = i + dir.first;
                    int colDir = j + dir.second;
                    int posDir = filaDir * C + colDir;
                    if (filaDir >= 0 && colDir >= 0 && filaDir < F && colDir < C && hastag[filaDir][colDir] && !CD.unidos(pos, posDir)) { // Siempre que sean direcciones dentro de la matriz, sea un # y no estén ya unidos
                        CD.unir(pos, posDir);
                        maxi = max(maxi, CD.cardinal(pos));
                    }
                }
            }
        }
    }

    if (maxi == 0 && encontrar) maxi = 1; // Si ha encontrado al menos uno, se cambiará el máximo a 1, si no ha encontrado será 0, y si no el max que haya salido
    cout << maxi << " ";
    int N;
    cin >> N;
    if (maxi == 0 && N > 0) maxi = 1;
    for (int i = 0; i < N; i++) {
        int f, c;
        cin >> f >> c;
        f--; 
        c--;
        hastag[f][c] = true;
        int pos = (f * C + c);
        for (auto dir : direcciones) {
            int filaDir = f + dir.first;
            int colDir = c + dir.second;
            int posDir = filaDir * C + colDir;
            if (filaDir >= 0 && colDir >= 0 && filaDir < F && colDir < C && hastag[filaDir][colDir] && !CD.unidos(pos, posDir)) {
                CD.unir(pos, posDir);
                maxi = max(maxi, CD.cardinal(pos));
            }
        }
        cout << maxi << " ";
    }
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
