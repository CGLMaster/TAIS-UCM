
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>

  El coste de la funci�n en el peor de los casos es O(N) donde N es el n�mero de agujeros que tiene la manguera.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int parches(vector<int> const& agujeros, int L) {
    int distancia = agujeros[0];
    int cont = 1;
    for (int i = 0; i < agujeros.size(); i++) {
        if (distancia + L < agujeros[i]) {
            distancia = agujeros[i];
            cont++;
        }
    }
    return cont;
}

bool resuelveCaso() {

    int N, L;
    cin >> N >> L;
    if (!cin)  return false;
    vector<int> agujeros(N);
    for (int i = 0; i < N; i++) cin >> agujeros[i];
    
    cout << parches(agujeros, L) << "\n";

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
