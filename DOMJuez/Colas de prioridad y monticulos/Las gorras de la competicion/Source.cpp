
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

    El coste de la funci�n en el peor de los casos es O(N*log(N)), donde 

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

struct tGorras {
    int pos = 0;
    long long int gorras = 0;
};

bool operator<(tGorras const& a, tGorras const& b) {
    return b.gorras < a.gorras || b.gorras == a.gorras && b.pos < a.pos ;
}

long long int compraGorras(priority_queue<tGorras>& q) {
    long long int compra = 0;
    tGorras e1,e2;
    while (q.size() > 1) {
        e1 = q.top(); q.pop();
        e2 = q.top(); q.pop();
        compra += e1.gorras + e2.gorras;
        e1.gorras += e2.gorras;
        q.push(e1);
    }
    return compra;
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0) return false;

    //priority_queue<int, vector<int>, greater<int>> competicion;
    priority_queue<tGorras> competicion;
    int seguidores;
    for (int i = 0; i < N; i++) {
        cin >> seguidores;
        competicion.push({i, seguidores });
    }

    long long int gorras = compraGorras(competicion);
    cout << gorras << "\n";

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
