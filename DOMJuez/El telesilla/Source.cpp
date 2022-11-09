
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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

int cuantosViajes(vector<int> const& pesos, const int P) {
    int cont = 0;
    int min = 0, max = pesos.size() - 1;
    int i = 0;
    while (i < pesos.size() && max >= min) {
        if (pesos[min] + pesos[max] <= P) {
            cont++;
            min++;
            max--;
        }
        else {
            cont++;
            max--;
        }
    }
    return cont;
}

bool resuelveCaso() {

    int P, C;
    cin >> P >> C;
    if (!cin) return false;
    
    vector<int> pesos(C);
    for (int i = 0; i < C; i++) cin >> pesos[i];
    sort(pesos.begin(), pesos.end());

    int viajes = cuantosViajes(pesos, P);
    cout << viajes << "\n";

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
