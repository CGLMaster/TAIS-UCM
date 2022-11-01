
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
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

int maraton(vector<pair<int, int>> const& finaliza) {
    int cont = 1;
    int t = finaliza[0].first;
    for (int i = 1; i < finaliza.size(); i++) {
        if (t + 10 <= (finaliza[i].first - finaliza[i].second)) {
            t = finaliza[i].first;
            cont++;
        }
    }
    return cont;
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0) return false;
    int h, m, d;
    char c;
    vector<pair<int,int>> finaliza(N);
    for (int i = 0; i < N; i++) {
        cin >> h >> c >> m >> d;
        finaliza[i] = { h * 60 + m + d , d};
    }
    sort(finaliza.begin(), finaliza.end());
    cout << maraton(finaliza) << "\n";
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
